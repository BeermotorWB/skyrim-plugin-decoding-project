/*===========================================================================
 *
 * File:		SrMustrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrMustRecord class.
 *
 *=========================================================================*/
#ifndef __SRMUSTRECORD_H
#define __SRMUSTRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sridrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrMustRecord Definition
 *
 *=========================================================================*/
class CSrMustRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrMustRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pFltvData;
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pCnamData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pAnamData;
	CSrSubrecord*		m_pCitcData;
	CSrSubrecord*		m_pBnamData;
	CSrSubrecord*		m_pLnamData;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pSnamData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrMustRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrMustRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrMustRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrMustRecord.H
 *=========================================================================*/
