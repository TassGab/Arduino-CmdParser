#include "CmdParser.h"
CmdParserClass CP=CmdParserClass();
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  String cmd="#1,5,3,55272.";
  Serial.println(cmd);
  CP.Parse(cmd);
}

void loop() {
  // put your main code here, to run repeatedly:

}
