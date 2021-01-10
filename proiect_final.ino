#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int startPin = 8;   //punctul de start al sarmei
const int endPin = 9;     //punctul de final al sarmei
const int buzzer = 10;

int red = 11;    
int green = 12;  

int startPoint, endPoint;  // aici citim starea pinilor


void setup() {
   Serial.begin(9600);
    lcd.init(); 

   lcd.backlight();
   
    lcd.setCursor(0,0); 
    lcd.print("Buzz Wire Game"); 
    
      
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
    tone(buzzer, 1000);
    digitalWrite(red,HIGH); 
    digitalWrite(green,LOW);
    delay(1000);
    
     noTone(buzzer);
    digitalWrite(red,HIGH);
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Ai pierdut jocul"); 
    lcd.setCursor(0,1); 
    lcd.print("Mai incearca"); 
}
    else if (startPoint == HIGH && endPoint == LOW){     //am ajuns la final cu succes
       tone(buzzer, 1000);
       digitalWrite(green,HIGH);
       digitalWrite(red,LOW);
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Ai castigat!"); 
       noTone(buzzer);
       
  }
      delay(500); 
  }
