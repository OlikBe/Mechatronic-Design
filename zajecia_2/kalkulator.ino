int a,b;
char znak;
float wynik;


void setup() {
  
  Serial.begin(9600);
  Serial.setTimeout(1000);

}

void loop() {
  
  Serial.println("Podaj pierwszą liczbe");
   delay(2500);
 while(!Serial.available());
  a = Serial.parseInt();
  if()
  Serial.read();//czyszczenie portu
  Serial.print("Liczba a = ");
  Serial.println(a);
  
  delay(1000);
  
  Serial.println("Podaj drugą liczbe ");
  while(!Serial.available());

    b=Serial.parseInt();
    Serial.read();//czyszczenie portu
    Serial.print("Liczba b = ");
    Serial.print(b);
    Serial.println();
    delay(1000);
 

   Serial.println("Wybierz działanie wprowadzająć symbol:");
   Serial.println( "dodawanie(+)" );
   Serial.println("odejmowanie(-) ");
   Serial.println("mnożenie(*) ");
   Serial.println("dzielenie(/) ");

  while(!Serial.available());
  znak = (char)Serial.read();

  switch (znak){

    case '+':
    wynik=a+b;
    break;
    case '-':
    wynik=a-b;
    break;
    case '*':
    wynik=a*b;
    break;
    case '/':
    if(b=0){
      Serial.println("Nie dziel przez zero!")
      }else{
     wynik=a/b;    }
    break;
    default:
    Serial.println("Bład !");
    break;
    }

Serial.println(wynik);
  
}
