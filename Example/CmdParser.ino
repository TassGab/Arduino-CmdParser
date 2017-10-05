#include "CmdParserClass.h"
CmdParserClass CP=CmdParserClass();
int ledPin=13;
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  String cmd="#1,0,3,127.";
  Serial.println(cmd);
  //CP.func1=TurnOn;
  CP.func2=TurnOff;
  CP.Parse(cmd);

  //Serial.println((&TurnOn));
  for (int i=0; i<CP.Nfield; i++)
  {
    Serial.print("Field ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.println(CP.Field[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void TurnOn()
{
 digitalWrite(ledPin,HIGH);
 Serial.println("Function Invoked through pointer");
}
void TurnOff()
{
 digitalWrite(ledPin,LOW);
 Serial.println("Function Invoked through pointer");
}
