
#include "Wire.h"    // This library allows you to communicate with I2C devices.

const int led = 13;
const int p1 = 4;
const int p2 = 5;
const int p3 = 6;
int dato,control=0;
int deli=20;

const int MPU_ADDR = 0x68;     // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t accelerometer_x, accelerometer_y, accelerometer_z;     // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z;     // variables for gyro raw data
int16_t temperature;    // variables for temperature data
char tmp_str[7];    // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) {     // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;



}
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);


  pinMode(led, OUTPUT);

  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);

  digitalWrite(p1,HIGH);
  digitalWrite(p2,HIGH);
  digitalWrite(p3,HIGH);
}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  // "Wire.read()<<8 | Wire.read();" means two registers are read and stored in the same variable
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  gyro_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)
  
  // print out data
// Serial.print(convert_int16_to_str(accelerometer_x));Serial.print(",");  //LADO LADO
// Serial.print(convert_int16_to_str(accelerometer_y));Serial.print(",");  //ADELANTE ATRAS 

//pulsadores
 if(digitalRead(p1) == LOW)
    {
    //pulsador 1
   // Serial.write(5);
    Serial.flush();
    Serial.println(5);
    delay(deli);    
    control=1;
    }
 if(digitalRead(p2) == LOW)
    {
    //pulsador2
    //Serial.write(6);
    Serial.flush();
    Serial.println(6);
    delay(deli);  
    control=1;  
    }
 if(digitalRead(p3) == LOW)
    {
    //Pulsador3
    //Serial.write(7);
    Serial.flush();
    Serial.println(7);
    delay(deli); 
    control=1;   
    }

  
  //acelerometro

   if(accelerometer_y <= -12000)
    {
    //Atras
    //Serial.write(2);
    Serial.flush();
    Serial.println(2);
    delay(deli);  
    control=1;  
    }
   
   if(accelerometer_y >= 9000)
    {
    //Adelante
    //Serial.write(1);
    Serial.flush();
    Serial.println(1);
    delay(deli);
    control=1;    
    }

    if(accelerometer_x >=12000)
    {
  //  derecha
    //Serial.write(4);
    Serial.flush();
    Serial.println(4);
    delay(deli);
    control=1;
    }
    if(accelerometer_x <= -11000)
    {
   //izquierda
    //Serial.write(3);
    Serial.flush();
    Serial.println(3);
    delay(deli);
    control=1;
    }
    if(control==0){
    Serial.flush();
    Serial.println(9);
    delay(deli);
    }
    control=0;

  delay(1);
}
