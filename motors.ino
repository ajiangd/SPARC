#include <IRremote.hpp>

int EN = 3;
int IN1 = 7;
int IN2 = 9;

int receiver = 11;
IRrecv irrecv(receiver);
decode_results results;

int values[6] = { 0, 50, 100, 150, 200, 255 };
num = find().values;

void no_rotation() {
  analogWrite(EN, values[0]);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(45);
}

void turn_clockwise() {
  analogWrite(EN, values[3]);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(45);
}

void turn_counterclockwise() {
  analogWrite(EN, values[3]);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(45);
}

void fast(num) {
  num += 1;
  analogWrite(EN), values[num]);
}


void translateIR() {
  switch (IrReceiver.decodedIRData.decodedRawData) {
    case 0xB946FF00:; break;
    case 0xEA15FF00: Serial.println("DOWN"); break;
    case 0xBF40FF00: no_rotation(); break;
    case 0xBC43FF00: turn_clockwise(); break;
    case 0xBB44FF00: turn_counterclockwise(); break;
  }
}

void setup() {
  // put your setup code here, to run once:
  IrReceiver.begin(receiver, ENABLE_LED_FEEDBACK);
  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  no_rotation();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    delay(100);

    translateIR();
    IrReceiver.resume();
  }
}
