// SMARS Bluetooth remote control
// Kevin McAleer
// April 2019
// May 2019 - added buzzer feature
// Requires a Fundomoto sheild
// September 2019 - use software serial for bluetooth module, using builtin rx/tx with bluetooth causes garbage on rx

//const int left_motor_direction = 13;
//const int right_motor_direction = 12;
//const int right_motor_PWM = 10;
//const int left_motor_PWM = 11;
//const int pan_servo_pin = 9;
//const int echoPin = 8;
//const int triggerPin = 7;
//const int buzzer = 4;
//const int tilt_servo_pin = 6;
//const int left_motor_IR_sensor_pin = 2;
//const int right_motor_IR_sensor_pin = 3;

#include "SoftwareSerial.h"
SoftwareSerial MyBlue(2, 3); // RX | TX 

//int ch_A_Brake = 9;
//int ch_B_Brake = 8;
int ch_A_Direction = 12;
int ch_B_Direction = 13;
int ch_A_speed = 10;
int ch_B_speed = 11;
char state = 0;
int delaylength = 1000;
int buzzerPin = 4;
//#define BUFFER_SIZE = 64; // this will prevent buffer overruns
//char inData[BUFFER_SIZE]; // this is a character buffer
char inChar=-1; // initalise the first character as nothing

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("SMARSFan OS 1.3");
  Serial.println("---------------");
  MyBlue.begin(9600);  //Baud Rate for AT-command Mode.  

  // establish motor direction toggle pins
  pinMode(ch_A_Direction, OUTPUT);
  pinMode(ch_B_Direction, OUTPUT);

  // establish motor brake pins
  //  pinMode(ch_A_Brake, OUTPUT);
  //  pinMode(ch_B_Brake, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
//   buzz();
//   delay(delaylength/10);
//   buzz();
}

void buzz(){
  Serial.println("Buzzer: Sound");
  digitalWrite(buzzerPin, HIGH);
  delay(delaylength / 10);
  digitalWrite(buzzerPin, LOW);
}

void forward() {
  // Move Forward

  Serial.println("MOTORS: UP");
  digitalWrite(ch_A_Direction, LOW); // set direction to forward
  digitalWrite(ch_B_Direction, HIGH); // set direction to forward

  analogWrite(ch_A_speed, 255); // full speed ahead
  analogWrite(ch_B_speed, 255); // full speed ahead

  delay(delaylength);

  analogWrite(ch_A_speed, 0); // stop
  analogWrite(ch_B_speed, 0); // stop


  //  Serial.flush();
}

void backward() {
  // Move Backward
  Serial.println("MOTORS: DOWN");
  digitalWrite(ch_A_Direction, HIGH); // set direction to backward
  digitalWrite(ch_B_Direction, LOW); // set direction to backward

  analogWrite(ch_A_speed, 255); // full speed ahead
  analogWrite(ch_B_speed, 255); // full speed ahead

  delay(delaylength);

  analogWrite(ch_A_speed, 0); // stop
  analogWrite(ch_B_speed, 0); // stop

  //  Serial.flush();
}

void left() {
  // Move left
  Serial.println("MOTORS: LEFT");
  digitalWrite(ch_A_Direction, HIGH); // set direction to left
  digitalWrite(ch_B_Direction, HIGH); // set direction to left

  analogWrite(ch_A_speed, 255); // full speed ahead
  analogWrite(ch_B_speed, 255); // full speed ahead

  delay(delaylength);

  analogWrite(ch_A_speed, 0); // stop
  analogWrite(ch_B_speed, 0); // stop

  //  Serial.flush();
}

void right() {
  // Move right
  Serial.println("MOTORS: RIGHT");
  digitalWrite(ch_A_Direction, LOW); // set direction to right
  digitalWrite(ch_B_Direction, LOW); // set direction to right

  analogWrite(ch_A_speed, 255); // full speed ahead
  analogWrite(ch_B_speed, 255); // full speed ahead

  delay(delaylength);

  analogWrite(ch_A_speed, 0); // stop
  analogWrite(ch_B_speed, 0); // stop

  //  Serial.flush();
}

void fullstop() {
  // stop!
  Serial.println("MOTORS: STOP");
  digitalWrite(ch_A_Direction, HIGH); // set direction to right
  digitalWrite(ch_B_Direction, HIGH); // set direction to right

  analogWrite(ch_A_speed, 0); // full speed ahead
  analogWrite(ch_B_speed, 0); // full speed ahead

  delay(delaylength);

  //  Serial.flush();
}

void loop()
{
  bool isData = false;
  inChar = "";
  // from bluetooth to terminal
  if (MyBlue.available()) 
  {
    inChar = MyBlue.read();
    Serial.write(MyBlue);
    isData = true;
  }
  if(Serial.available())
  {
    MyBlue.write(Serial.read());
  }

    if(isData)
    {
      isData = false;
//       MyBlue.read();
//      int value = inChar;
//      Serial.print("Value:");
//      Serial.print(value);
//      Serial.print(" Character:");
//      Serial.println(inChar);
      if (inChar == 'u') 
      {
        forward();
      }
      else if (inChar == 'd') 
      {
        backward();
      }
      else if (inChar == 'l') 
      {
        left();
      }
      else if (inChar == 'r') 
      {
        right();
      }
      else if (inChar == "s") 
      {
        fullstop();
      }
      else if (inChar == 'b') 
      {
        buzz();
      }
  }
}
 
