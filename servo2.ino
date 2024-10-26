#include <IRremote.hpp>
#include <Servo.h>

Servo myservo;
int pos = 0;

int receiver = 11;
IRrecv irrecv(receiver);
decode_results results;

void turn_clockwise()
{
    if (pos < 170) {pos+=10;}
    pos+=10;
    myservo.write(pos);
    delay(15);
}

void turn_counterclockwise()
{
  if (pos < 10) {pos-=10;}
  pos-=10;
  myservo.write(pos);
  delay(15);
}

void translateIR()
{
  switch(IrReceiver.decodedIRData.decodedRawData)
  {
  case 0xB946FF00: Serial.println("UP"); break;
  case 0xEA15FF00: Serial.println("DOWN"); break;
  case 0xBC43FF00: Serial.println("RIGHT"); turn_counterclockwise(); break;
  case 0xBB44FF00: Serial.println("LEFT"); turn_clockwise(); break;
  case 0xBF40FF00: Serial.println("OK"); break;
  case 0xE916FF00: Serial.println("1"); break;
  case 0xE619FF00: Serial.println("2"); break;
  case 0xF20DFF00: Serial.println("3"); break;
  case 0xF30CFF00: Serial.println("4"); break;
  case 0xE718FF00: Serial.println("5"); break;
  case 0xA15EFF00: Serial.println("6"); break;
  case 0xF708FF00: Serial.println("7"); break;
  case 0xE31CFF00: Serial.println("8"); break;
  case 0xA55AFF00: Serial.println("9"); break;
  case 0xAD52FF00: Serial.println("0"); break;
  case 0xBD42FF00: Serial.println("*"); break;
  case 0xB54AFF00: Serial.println("#"); break;
  case 0xFFFFFFFF: Serial.println("REPEAT"); break;
  default:
    Serial.println("other button ");
  }
  delay (200);
}

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  IrReceiver.begin(receiver,ENABLE_LED_FEEDBACK);

  myservo.attach(9);
}

void loop() {
  if (IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(100);
    translateIR();
    IrReceiver.resume();
  }
}
