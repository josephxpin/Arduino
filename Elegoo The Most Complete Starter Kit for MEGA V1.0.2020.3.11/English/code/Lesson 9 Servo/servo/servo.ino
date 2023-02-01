//www.elegoo.com
//2018.12.19
#include <Servo.h>
Servo myservo;

int button_pin = 7;
int val;

void setup() {
  myservo.attach(9);
  pinMode(button_pin, INPUT_PULLUP);
  val = 0;
}

void loop() {
  if (digitalRead(button_pin)==LOW) {
    if (val == 180) val = 0;
    else val=val+10;
    myservo.write(val);
    delay(15);
    while (digitalRead(button_pin)==LOW);
  }
}
