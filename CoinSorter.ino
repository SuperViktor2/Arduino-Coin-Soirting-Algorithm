#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

Servo servo1;
Servo servo2;
Servo servo5;

const int button = 2;

int lastButtonState;
int currentButtonState;

void pomakniServo1 (int brojKovanica) {
  for (byte times = 0; times < brojKovanica; times++) {
    for (int pos = 0; pos <= 180; pos += 1) {

      servo1.write(pos);
      delay(15);
    }

    for (int pos = 180; pos >= 0; pos -= 1) {
      servo1.write(pos);
      delay(15);
    }

    delay (500);
  }
}

void pomakniServo2 (int brojKovanica) {
  for (byte times = 0; times < brojKovanica; times++) {
    for (int pos = 0; pos <= 180; pos += 1) {

      servo2.write(pos);
      delay(15);
    }

    for (int pos = 180; pos >= 0; pos -= 1) {
      servo2.write(pos);
      delay(15);
    }

    delay (500);
  }
}

void pomakniServo5 (int brojKovanica) {
  for (byte times = 0; times < brojKovanica; times++) {
    for (int pos = 0; pos <= 180; pos += 1) {

      servo5.write(pos);
      delay(15);
    }

    for (int pos = 180; pos >= 0; pos -= 1) {
      servo5.write(pos);
      delay(15);
    }

    delay (500);
  }
}


void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT_PULLUP);
  currentButtonState = digitalRead(button);

  lcd.begin(16, 2);

  servo1.attach(6);
  servo1.write(0);

  servo2.attach(5);
  servo2.write(0);

  servo5.attach(3);
  servo5.write(0);

  lcd.print("Zeljeni iznos: ");
  lcd.setCursor(14, 1);
  lcd.print("Kn");
  
}


void loop() {
  int sensorValue = analogRead(A7);
  int kuna = sensorValue / 100;
  int pet = kuna / 5;
  int ostatak = kuna % 5;
  int dva = ostatak / 2;
  int jedan = 1;

  if(kuna == 10) kuna = 9;

  lcd.setCursor(0, 1);
  lcd.print(kuna);

  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(button);

  if (lastButtonState == HIGH && currentButtonState == LOW) {

    if ((kuna % 5 == 0) || (ostatak % 2 == 0)) jedan = 0;

    pomakniServo1(pet);
    pomakniServo2(dva);
    pomakniServo5(jedan);
  }
Serial.println(kuna);
}
