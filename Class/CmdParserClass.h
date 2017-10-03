/*
 CmdParser.h - Library for parsing serial commands
 Command format: #CMD,<f1>,<f2>,..<fn>,CRC.
 Gabriele Tasselli, February 13, 2017
 */
#ifndef CmdParser_h
#define CmdParser_h
//#include <chibi.h>
#define MAX_CMD_F 10
#define MAX_ERR_MSG 20
class CmdParserClass
{
 public:
 uint8_t Cmd;//Command
 uint8_t CrcCalc; //Calculated CRC
 uint8_t numbers[MAX_CMD_F];//array of fields
 uint8_t Nfield; //N of fields
 char errMsg[MAX_ERR_MSG]; //error message string
 bool error; //flag of parsing error
 void Parse(String);
 private:
 void stringParser(String);
 void WriteErrMsg(String);
};
#endif
