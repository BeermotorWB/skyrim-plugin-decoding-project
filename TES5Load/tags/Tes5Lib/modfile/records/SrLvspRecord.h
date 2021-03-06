/*===========================================================================
 *
 * File:		SrLvsprecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	17 December 2011
 *
 * Defines the CSrLvspRecord class.
 *
 *=========================================================================*/
#ifndef __SRLVSPRECORD_H
#define __SRLVSPRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srlvlosubrecord.h"
	#include "../subrecords/srbytesubrecord.h"
    #include "../subrecords/srlvlfsubrecord.h"
	#include "../subrecords/srcoedsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrLvspRecord Definition
 *
 *=========================================================================*/
class CSrLvspRecord : public CSrIdRecord 
{
	DECLARE_SRSUBRECCREATE()
	DECLARE_SRFIELDMAP()
	DECLARE_SRCLASS(CSrLvspRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*			m_pObndData;
	CSrByteSubrecord*		m_pChanceNone;
	CSrLvlfSubrecord*		m_pFlags;
	CSrByteSubrecord*		m_pListCount;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	void SetListCount (const dword Value);


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrLvspRecord();
	virtual void Destroy (void);

	CSrLvloSubrecord* AddItem    (const srformid_t FormID, const dword Level, const dword Count);
	bool DeleteItem (CSrLvloSubrecord* pItem); 

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrLvspRecord; }

		/* Get class members */
	dword GetListCount    (void) { return m_pListCount  ? m_pListCount->GetValue() : 0; }
	byte  GetChanceNone   (void) { return m_pChanceNone ? m_pChanceNone->GetValue() : 0; }
	bool  IsCalculateEach (void) { return m_pFlags ? m_pFlags->IsCalculateEach() : false; }
	bool  IsCalculateAll  (void) { return m_pFlags ? m_pFlags->IsCalculateAll() : false; }
	bool  IsUseAll        (void) { return m_pFlags ? m_pFlags->IsUseAll() : false;}  

	CSrLvloSubrecord* GetFirstItem (int& Position);
	CSrLvloSubrecord* GetNextItem  (int& Position);

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	void SetChanceNone    (const byte Value);
	void SetCalculateEach (const bool Flag) { if (m_pFlags) m_pFlags->SetCalculateEach(Flag); }
	void SetCalculateAll  (const bool Flag) { if (m_pFlags) m_pFlags->SetCalculateAll(Flag); }
	void SetUseAll        (const bool Flag) { if (m_pFlags) m_pFlags->SetUseAll(Flag); }
	void UpdateListCount  (void);


		/* Begin field method definitions */
    DECLARE_SRFIELD_BYTE(CSrLvspRecord, ChanceNone, GetChanceNone, SetChanceNone)
    DECLARE_SRFIELD_DWORD1(CSrLvspRecord, ItemCount, GetListCount(), dword Tmp)
	DECLARE_SRFIELD_BOOL(CSrLvspRecord, CalculateEach, IsCalculateEach, SetCalculateEach)
	DECLARE_SRFIELD_BOOL(CSrLvspRecord, CalculateAll, IsCalculateAll, SetCalculateAll)
	DECLARE_SRFIELD_BOOL(CSrLvspRecord, UseAll, IsUseAll, SetUseAll)

};
/*===========================================================================
 *		End of Class CSrLvspRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLvspRecord.H
 *=========================================================================*/
