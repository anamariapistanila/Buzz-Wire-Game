const int startPin = 4;   //punctul de start al sarmei
const int endPin = 5;     //punctul de final al sarmei
const int buzzer = 6;

int red = 8;    //cand se atinge sarma, se aprinde becul rosu
int green = 9;   // apoi se face din nou verde

int startPoint, endPoint;  // aici citim starea pinilor


void setup() {
   Serial.begin(9600);
    
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
    delay(1000); }
  }

}
