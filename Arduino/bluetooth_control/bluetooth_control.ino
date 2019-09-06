// SMARS Bluetooth remote control
// Kevin McAleer
// April 2019
// May 2019 - added buzzer feature
// Requires a Fundomoto sheild


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
  Serial.println("SMARSFan OS 1.2");
  Serial.println("---------------");

  // establish motor direction toggle pins
  pinMode(ch_A_Direction, OUTPUT);
  pinMode(ch_B_Direction, OUTPUT);

  // establish motor brake pins
  //  pinMode(ch_A_Brake, OUTPUT);
  //  pinMode(ch_B_Brake, OUTPUT);
}

void buzz(){
  Serial.println("Buzzer: Sound");
  digitalWrite(buzzerPin, HIGH);
  delay(delaylength / 2);
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
  // put your main code here, to run repeatedly:
  int i=0;
  byte byte_count=Serial.available();
  Serial.println(byte_count);
  if (byte_count)
  {
    int first_byte=byte_count;
    int remaining_bytes=0;
//    if(first_byte>=BUFFER_SIZE-1)
//    {
//      remaining_bytes=byte_count-(BUFFER_SIZE-1);
//    }

//    wrong ! do not need to build and array, just read each chararcter one at a time and act on it.
//    for(i=0;i<first_byte;i++)
//    {
//      inChar=Serial.read(); // read one byte
//      inData[i]=inChar;
//      Serial.println(state);
//    }

    inChar = Serial.read();
    Serial.println(inChar);

//    inData[i]='\0'; // terminate the string

//    state = inData;
    if (inChar == 'u') {
      forward();
    }
    else if (inChar == 'd') {
      backward();
    }
    else if (inChar == 'l') {
      left();
    }
    else if (inChar == 'r') {
      right();
    }
    else if (inChar == "s") {
      fullstop();
    }
    else if (inChar == 'b') {
      buzz();
    }
    for(i=0;i<remaining_bytes;i++)
    {
      inChar=Serial.read(); // burn off any remaining bytes
    }
    // state = 0;

    }
  }
