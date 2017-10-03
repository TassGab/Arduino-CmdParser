#include "CmdParser.h"
CmdParserClass CP=CmdParserClass();
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  String cmd="#1,5,55272.";
  Serial.println(cmd);
  CP.Parse(cmd);
  Serial.print("error msg=");
  Serial.println(CP.errMsg);
}

void loop() {
  // put your main code here, to run repeatedly:

}
