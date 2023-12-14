#include <Arduino.h>
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 14;

int motor2Pin1 = 33;
int motor2Pin2 = 32;
int enable2Pin = 25;

int motor3Pin1 = 21;
int motor3Pin2 = 19;
int enable3Pin = 18;

int motor4Pin1 = 23;
int motor4Pin2 = 22;
int enable4Pin = 15;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 170;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(enable3Pin, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  pinMode(enable4Pin, OUTPUT);

  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel);
  ledcAttachPin(enable3Pin, pwmChannel);
  ledcAttachPin(enable4Pin, pwmChannel);
  ledcWrite(pwmChannel, dutyCycle);
}

void loop() {

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);

  //move forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
  for (dutyCycle = 170; dutyCycle < 255; dutyCycle++) {
    ledcWrite(pwmChannel, dutyCycle);
    delay(20);
  }

  dutyCycle = 170;
  ledcWrite(pwmChannel, dutyCycle);
}
