#include <IRremote.h>

int receiver=11;
IRrecv irrecv(receiver);
decode_results results;

int red_light_pin=7;
int green_light_pin=6;
int blue_light_pin=5;

const int trigPin = 12; 
const int echoPin = 11;
const int buzzer = 3;

long duration;
int distance;

void translateIR()
{
  switch(results.value)
  {
  case 0xB946FF00: Serial.println("UP"); break;
  case 0xEA15FF00: Serial.println("DOWN"); break;
  case 0xBC43FF00: Serial.println("RIGHT"); break;
  case 0xBB44FF00: Serial.println("LEFT"); break;
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
  delay (500);
}

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)){
  {
    Serial.println(results.value);
    irrecv.resume();
  }

  if (distance >= 0 && distance < 20){
    RGB_color(255,0,0);
    delay (300);
    tone(buzzer, 1000);      
  }
  else if (distance >= 20 && distance < 40){
    RGB_color(255,255,0);
    delay (300);
    noTone(buzzer);
  } 
  else if (distance >= 40 && distance < 60){
    RGB_color(255,255,255);
    delay (300);
    noTone(buzzer);
  } 
  else if (distance >= 60 && distance < 80){
    RGB_color(0,0,255);
    delay (300);
    noTone(buzzer);
  } 
  else if (distance >= 80){
    RGB_color(0,255,0);
    delay (300);
    noTone(buzzer);
  } 
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value){
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
}
