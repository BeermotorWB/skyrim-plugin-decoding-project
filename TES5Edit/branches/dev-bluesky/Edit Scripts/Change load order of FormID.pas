﻿{
  
  修改表单序号的加载顺序部分。
  内置的右键菜单命令“修改表单序号”分配新的表单。
  此脚本仅修改表单序号的加载顺序部分。
}
unit UserScript;

var
  NewLoadOrder: Cardinal;

function Initialize: integer;
var
  s: string;
begin
  // set this to predefined value if you don't want the script to prompt you
  NewLoadOrder := -1;
  
  if NewLoadOrder = -1 then begin
    Result := 1;
    if not InputQuery('输入', '以十六进制定义新的加载顺序', s) then 
      Exit;
    if s = '' then
      Exit;
    NewLoadOrder := StrToInt64('$' + s);
  end;

  Result := 0;
end;
  
function Process(e: IInterface): integer;
var
  OldFormID, NewFormID: Cardinal;
  m: IInterface;
begin
  Result := 0;
  
  // file header doesn't have formid
  if Signature(e) = 'TES4' then
    Exit;
  
  OldFormID := GetLoadOrderFormID(e);
  
  // clear load order byte in oldformid and set new load order in high byte (shifted left by 24 bits)
  NewFormID := (OldFormID and $00FFFFFF) + (NewLoadOrder shl 24);
  
  if NewFormID = OldFormID then
    Exit;
  
  // here we shoud check for availability of NewFormID, but it will generate error and abort anyway if that happens
  // ...

  //AddMessage(Format('Changing FormID from [%s] to [%s] on %s', [IntToHex64(OldFormID, 8), IntToHex64(NewFormID, 8), Name(e)]));
  
  // the record in question might originate from master file
  m := MasterOrSelf(e);
  
  // skip overridden records, don't know what to do with them for now
  if not Equals(m, e) then
    Exit;
  
  // first change formid of references
  while ReferencedByCount(m) > 0 do
    CompareExchangeFormID(ReferencedByIndex(m, 0), OldFormID, NewFormID);

  // change formid of record
  SetLoadOrderFormID(e, NewFormID);
 
end;

end.
