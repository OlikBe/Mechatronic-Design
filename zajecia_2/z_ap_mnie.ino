#include <PID_v1.h>

int cm = 0;

double Setpoint;
double Input;
double Output;

const double Kp=7;
const double Ki=1;
const double Kd=1;

PID newPID(&Input,&Output,&Setpoint,Kp,Ki,Kd,DIRECT);


void setup()
{
  Serial.begin(9600);
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Input = cm;
  Setpoint = 50;
  newPID.SetMode(AUTOMATIC);

}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  
  Input = cm;
  
  newPID.Compute();
  
  
  
  startMotor(Output);
  delay(1000);
  stopMotor();
  delay(1000);
}




void startMotor (uint8_t _speed) {
      
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      analogWrite(9, _speed);      
    

  }

void stopMotor() {

      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      analogWrite(9, 0);
       
  }

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
