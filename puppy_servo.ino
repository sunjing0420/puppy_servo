#include<NewPing.h>
#include<Servo.h>

int trigPin = 12;
int echoPin = 13;
int maxDis = 200;

NewPing sonar(trigPin, echoPin, maxDis);
Servo myservo;

int servoPin = 9;
int servoVal;

int ledPin = 5;
int ledVal = 0;


void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int oldDistance = sonar.ping_cm();
  delay(15);
  int newDistance = sonar.ping_cm();
  if (newDistance == oldDistance) {
    if (newDistance > 0 && newDistance < 8) {
      Serial.print(newDistance);
      Serial.println("yes");
      servoVal = 30;
      ledVal = HIGH;
      myservo.write(servoVal);
    }else if(newDistance>8 && newDistance<100){
      Serial.print(newDistance);
      Serial.println("no");
      servoVal = -30;
      ledVal = LOW;
      myservo.write(servoVal);
    }
  }
      digitalWrite(ledPin, ledVal);

}
