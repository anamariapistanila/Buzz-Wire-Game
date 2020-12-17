
#include <LiquidCrystal.h>
LiquidCrystal lcd( 7,6,5,4,3,2,1);

const int startPin = 4;   //punctul de start al sarmei
const int endPin = 5;     //punctul de final al sarmei
const int buzzer = 8;

int red = 9;    //cand se atinge sarma, se aprinde becul rosu
int green = 10;   // apoi se face din nou verde

int startPoint, endPoint;  // aici citim starea pinilor


void setup() {
   Serial.begin(9600);

   lcd.begin(16,2);

   lcd.setCursor(0,0); 
   lcd.print("Buzz Wire Game"); 
   delay(3000);
   lcd.clear();
    
   pinMode(buzzer, OUTPUT);  
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(startPin, INPUT_PULLUP);
   pinMode(endPin, INPUT_PULLUP);  //rezistentele oferite de Arduino

}

void loop() {
   startPoint = digitalRead(startPin);
   endPoint = digitalRead(endPin); 

//transmisie
  Serial.print(startPoint);
  Serial.print("\n");
  Serial.print(endPoint); 

  if (startPoint == LOW && endPoint == LOW ){  //daca ambii pini sunt low inseamna ca am atins sarma, se va aprinde becul rosu si buzzerul va face un sunet
    digitalWrite(buzzer, HIGH);
    digitalWrite(red,HIGH); 
    digitalWrite(green,LOW);
    delay(1000);
    
    digitalWrite(buzzer, LOW); 
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);

    lcd.setCursor(0,0); 
    lcd.print("Ai pierdut jocul"); 
    lcd.setCursor(0,1); 
    lcd.print("Mai incearca"); 
}
    else if (startPoint == HIGH && endPoint == LOW){     //am ajuns la final cu succes
       lcd.setCursor(0,0); 
       lcd.print("Ai castigat!"); 
       
  }
      delay(500); 
  }
