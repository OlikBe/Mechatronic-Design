#define trigPin 12
#define echoPin 11

void setup() {
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

}

void loop() {
long time,length;
  
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

time=pulseIn(echoPin,HIGH);
length = time/58;

Serial.print(length);
Serial.println(" cm");

delay(500);


}
