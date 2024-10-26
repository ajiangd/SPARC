#define PWMA 5
#define PWMB 6
#define BIN1 7
#define AIN1 8
#define STBY 3

#define IR_R A0
#define IR_M A1
#define IR_L A2

#define trigPin 13
#define echoPin 12\


void turn_right() {
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 50);
}

void turn_left() {
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMA, 50);
  analogWrite(PWMB, 0);
}

void walk(){
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMA, 75);
  analogWrite(PWMB, 75);
}

void run(){
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMA, 135);
  analogWrite(PWMB, 135);
}

void half_turn(){
  digitalWrite(STBY, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(AIN1, HIGH);
  analogWrite(PWMA, 75);
  analogWrite(PWMB, 0);

void stop(){
  digitalWrite(STBY, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(AIN1, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(AIN1, OUTPUT);
  Serial.begin(9600);
}

void emergency_breaks(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  duration = pulseIn(echoPin, HIGH);
  distance = duration*.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <= 30){
    // stop();
    // delay(500);
   half_turn();
    delay(20);
    
    if(analogRead(IR_M)>100){
      walk();
    }
  }  
}

void loop() {
  int l = analogRead(IR_L);
  int r = analogRead(IR_R);
  int m = analogRead(IR_M);
  // Serial.print("Left: ");
  // Serial.println(analogRead(IR_L));
  // Serial.print("Middle: ");
  // Serial.println(analogRead(IR_M));
  // Serial.print("Right ");
  // Serial.println(analogRead(IR_R));
  // delay(10);
  
  if ((m > 400) && (l< 400) && (r < 400)){
    walk();
    }
    // delay(400);
    if ((r > 400) && (l < 400) && (m < 400 )){
      Serial.print("Forward");
      turn_right();
      // delay(400);
    }
    if ((l > 400) && (r < 400) && (m < 400)){
      turn_left();
      // delay(400);
    }
    if ((l < 400) && (r < 400) && (m < 400)){
      half_turn();
    }
    if ((l > 400) && (r > 400) && (m > 400)){
      emergency_breaks();
    }
    // if (analogRead(IR_L > 400 && IR_M > 400 && IR_R > 400)){
    //   backward();
    // }
  
}
