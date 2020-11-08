#include <ezButton.h>
#include <Servo.h>
#define SW1 2
#define SW2 3
#define SW3 4

Servo myservo;
ezButton button(SW1);
int popBtn ;
int flag=0;
int angleStep=10;
int btnStat;
int angle=0;
int btnR , btnL;
int turnOn=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  
  Serial.begin(9600);
  button.setDebounceTime(50);
  myservo.attach(9);
  btnStat = digitalRead(SW1); 
  
}

void loop() {
  button.loop();
  popBtn = btnStat;
  btnStat = digitalRead(SW1);
  btnR = digitalRead(SW2);
  btnL = digitalRead(SW3);
  
  if(button.isPressed() && flag==0){//właczanie silnika
    Serial.println("Wcisniety przycisk włącz!");
    flag = 1;//flaga=1 symbolizuje wł silnik
    turnOn=turnOn + 1;//wyswietlanie ilosci uruchomien
    Serial.println(turnOn);
     for(int i=0; i<100;i++){
      if(angle == 0)
      angle = 180;
      if(angle == 180)
      angle = 0;    
     myservo.write(angle);
      }
     }
    
    if(btnR ==LOW && flag==1){
       if (angle > 0 && angle <= 180) {
        angle = angle - angleStep;
       if(angle < 0){
        angle = 0;
       }else{
      myservo.write(angle); 
       }}
       delay(100);
       } 
       
     if(btnL ==LOW && flag==1){
      if (angle >= 0 && angle <= 180) {
      angle = angle + angleStep;
      if(angle >180){
        angle =180;
       }else{
      myservo.write(angle);
       }}
       delay(100);     
      }      
      
      if(button.isPressed() && flag==1){//wyłaczenie silnika
    Serial.println("Wcisniety przycisk w celu wył");
    angle=0;
    myservo.write(angle);
    flag = 0; 
    delay(50);
      }
 
}
