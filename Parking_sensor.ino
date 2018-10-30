#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define buzzer 3

int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 110 && distance >=81) {
    digitalWrite(led, HIGH);
    intermitente(500);
}
  else {
    digitalWrite(led,LOW);
  }
  if (distance < 80 && distance >=71) {
      digitalWrite(led2, HIGH);
      intermitente(400);
}
  else {
      digitalWrite(led2, LOW);
  }
  if (distance < 70 && distance >=51) {
      digitalWrite(led3, HIGH);
      intermitente(300);
} 
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 50 && distance >=36) {
    digitalWrite(led4, HIGH);
    intermitente(250);
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 35 && distance >=26) {
    digitalWrite(led5, HIGH);
    intermitente(100);
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 25 && distance >=0) {
    digitalWrite(led6, HIGH);
    intermitente(50);
}
  else {
    digitalWrite(led6,LOW);
  }
 
  if (distance > 100 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
 
  delay(10);
}
void intermitente(int intermitencia){
  tone(buzzer, sound);
  delay(intermitencia);
  noTone(buzzer);
  delay(intermitencia);
  }


