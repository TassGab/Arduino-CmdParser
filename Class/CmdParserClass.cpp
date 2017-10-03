/*
 CmdParserClass.cpp - Library for Parsing commands
 Gabriele Tasselli, February 13, 2017
 */
#include <Crc16.h>
#include "CmdParser.h"
void CmdParserClass::Parse(String inCommand){
  Crc16 crc;
   WriteErrMsg("");
   Cmd=-1;
   error=true;
   Nfield=-1;
   if (inCommand[inCommand.length()-1] == '.' && inCommand[0]=='#')//
    {   

       int crcext=0;
       //unsigned short value;
       char data[100];
      Serial.print("CMD =");Serial.println(inCommand);
      int lastI=inCommand.lastIndexOf(',');
      //Serial.println(lastI);
      String crcstr=inCommand.substring(lastI+1,inCommand.length()-1);
      Serial.println(crcstr);
      crcext=crcstr.toInt();
      inCommand.toCharArray(data,lastI);
      Serial.println(data);
      crc.clearCrc();
      Serial.println(crcext,DEC);
      CrcCalc = crc.XModemCrc((byte *)data,0,lastI+1);
      Serial.println(CrcCalc,DEC);

      if(crcext == CrcCalc) 
      {
        error=false;
        Serial.println("CRC OK");
        stringParser(inCommand);
      }
      else 
      {
        error=true;
        String s1="CRC error: calc=";
        s1.concat(CrcCalc);
        WriteErrMsg(s1);
        //errMsg.concat(CrcCalc);
        //Serial.println(errMsg);
      }
      //inCommand="";   
    }  
    else
    {
      error=true;
     WriteErrMsg("Sintax error");
    }
    //inCommand="";
}
void CmdParserClass::stringParser(String s)
{
 //Format #CMD,f1,f2,...,CRC.
 #define Fcmd 0
 #define Ff1 1
  int is=0;
  int ncount=0;
  int inChar;
  String inString="";
  for (is=1;is<s.length();is++)
  {
    
    if (isDigit(s[is])) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)s[is];
    }
    if(ncount<MAX_CMD_F)
    {      
      if (s[is] == ',' ) 
      {
       numbers[ncount]=inString.toInt();
       Serial.print('>');Serial.println(numbers[ncount]);
       ncount++;
       // clear the string for new input:
       inString = "";
      }
      else if(s[is] == '.' )
      {
       numbers[ncount]=inString.toInt();
       inString = "";
       error=false;
       WriteErrMsg("No error");
      Serial.print("\r\nCRC=");Serial.println(numbers[ncount]);
     }
    }
    else
    {
      error=true;
      WriteErrMsg("N field exceeds "+MAX_CMD_F);

    }
  }//end for
        inString = "";
  Cmd=(uint8_t)numbers[Fcmd];
  Nfield=(uint8_t)ncount;//CRC already removed when stringParser is called
  Serial.print("Cmd=");Serial.println(Cmd);
  Serial.print("errMsg="); Serial.println(errMsg);
  Serial.print("Nfield="); Serial.println(Nfield);
}
void CmdParserClass::WriteErrMsg(String s)
{
  s.toCharArray(errMsg,MAX_ERR_MSG);
}

