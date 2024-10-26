#include "IRremote.hpp"
int receiver = 11;
IRrecv irrecv(receiver);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  IrReceiver.begin(receiver,ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(100);
    irrecv.resume();
  }
}
