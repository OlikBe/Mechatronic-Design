
void setup() {
  pinMode(7, OUTPUT); //Dioda jako wyjście
  pinMode(8, INPUT_PULLUP); //Przycisk jako wejście
  digitalWrite(7, LOW); //Wyłączenie diody
}
 
void loop()
{
  if (digitalRead(8) == LOW) { //Jeśli przycisk wciśnięty
    digitalWrite(7, HIGH); //Włącz diodę
  } else { //Jeśli warunek nie został spełniony (przycisk nie jest wciśnięty)
    digitalWrite(7, LOW); //Wyłącz diodę
  }
}
