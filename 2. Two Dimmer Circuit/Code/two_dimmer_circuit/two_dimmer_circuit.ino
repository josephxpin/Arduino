const int pot1 = A0;
const int pot2 = A1;
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

int sensorValue = 0;
int outputValue = 0;

void setup() {
  analogWrite(led1, 0);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
}

int dimmer(int pot, int led) {
  sensorValue = analogRead(pot);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(led, outputValue);
  return sensorValue;
}

void loop() {
  int dim1 = dimmer(pot1, led1);
  int dim2 = dimmer(pot2, led2);

  if (abs(dim1-dim2) < 10) {
    analogWrite(led3, 255);
  } else {
    analogWrite(led3, 0);
  }
  
  delay(2);
}
