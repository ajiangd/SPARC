#include <Servo.h>
Servo myservo;
int pos = 0;

// int red_light_pin=7;
// int green_light_pin=6;
// int blue_light_pin=5;
// const int buzzer = 3;

const int trigPin = 12; 
const int echoPin = 11;

long duration;
int distance;

void setup() {
 
  // pinMode(red_light_pin, OUTPUT);
  // pinMode(green_light_pin, OUTPUT);
  // pinMode(blue_light_pin, OUTPUT);
  // pinMode(buzzer, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);

  myservo.attach(9);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance >= 0 && distance < 20){
    for (pos = 0; pos <= 180; pos +=10){
      myservo.write(pos);
      delay(300);
}
   
    // RGB_color(255,0,0);
    // delay (300);
    // tone(buzzer, 1000);      
  }
  else if (distance >= 20 && distance < 40){
   for (pos = 0; pos <= 180; pos +=8){
      myservo.write(pos);
      delay(300);
   }
    // RGB_color(255,255,0);
    // delay (300);
    // noTone(buzzer);
  } 
  else if (distance >= 40 && distance < 60){
   for (pos = 0; pos <= 180; pos +=6){
      myservo.write(pos);
      delay(300);
   }
    // RGB_color(255,255,255);
    // delay (300);
    // noTone(buzzer);
  } 
  else if (distance >= 60 && distance < 80){
    for (pos = 0; pos <= 180; pos +=4){
      myservo.write(pos);
      delay(300);
    }
    // RGB_color(0,0,255);
    // delay (300);
    // noTone(buzzer);
  } 
  else if (distance >= 80){
    for (pos = 0; pos <= 180; pos +=2){
      myservo.write(pos);
      delay(300);
    }
    // RGB_color(0,255,0);
    // delay (300);
    // noTone(buzzer);
  } 
}

// void RGB_color(int red_light_value, int green_light_value, int blue_light_value){
//   analogWrite(red_light_pin, red_light_value);
//   analogWrite(green_light_pin, green_light_value);
//   analogWrite(blue_light_pin, blue_light_value);
// }
