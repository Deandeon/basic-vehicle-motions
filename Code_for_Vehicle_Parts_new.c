
#include <NewPing.h> //library for the ultrasonic Sensor

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int EN1 =6;
int EN2 =7;
int trigpin = 8;
int echoPin =9;
int unknown = 11;
int new = 12;

int sensorval = 0;

int duration = 0;

int distance = 0;

void stopMoving();
void moveForward();
void moveLeft();
void moveRight();
void moveBackwards();
void autoMode();
void sharpturnright();
void sharpturnLeft();
void ultraact();



void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigpin, OUPUT);
  pinMode(echoPin,INPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

 //ULTRASONIC SENSOR SETUP

  Serial.begin(9600);
}

void loop() {
  ultraact();
  moveFoward();
}



void moveBackwards() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void moveLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void moveRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void stopMoving() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);

}

void ultraact(){
  Serial.print("sensor range = ");
  Serial.println(sensorval);

  delay(1000);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the duration of the echo pulse and calculate distance in centimeters
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
}

void sharpturnright()
{
analogWrite(EN1,255);
analogWrite(EN2,255);
digitalWrite(IN1,HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}


void sharpturnLeft()
{
analogWrite(EN1,255);
analogWrite(EN2,255);
digitalWrite(IN1,LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
}

void autoMode(){





}
