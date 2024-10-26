#include <Wire.h>
const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int minVal=265; int maxVal=402;

double x; double y; double z;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  GyX=Wire.read()<<8|Wire.read();
  GyY=Wire.read()<<8|Wire.read();
  GyZ=Wire.read()<<8|Wire.read();

  int xAng = map(AcX,minVal,maxVal, -90,90);
  int yAng = map(AcY,minVal,maxVal, -90,90);
  int zAng = map(AcZ,minVal,maxVal, -90,90);

  x = RAD_TO_DEG * (atan2(-yAng,-zAng)+PI);
  y = RAD_TO_DEG * (atan2(-xAng,-zAng)+PI);
  z = RAD_TO_DEG * (atan2(-yAng,-xAng)+PI);

  Serial.print(" AngleX "); Serial.print(x);
  Serial.print(" AngleY "); Serial.print(y);
  Serial.print(" AngleZ "); Serial.println(z);

  // Serial.print("Accelerometer: ");
  // Serial.print("X = "); Serial.print(AcX);
  // Serial.print(" | Y = "); Serial.print(AcY);
  // Serial.print(" | Z = "); Serial.print(AcZ);

  // Serial.print(" | Gyroscope: ");
  // Serial.print("X = "); Serial.print(GyX);
  // Serial.print(" | Y = "); Serial.print(GyY);
  // Serial.print(" | Z = "); Serial.print(GyZ);
  // Serial.println(" ");
  delay(333);
}
