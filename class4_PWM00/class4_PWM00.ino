int n = 0;
int buttonPin1 = 2;
int buttonPin2 = 3;
int ledPin = 11;
void setup() {
  pinMode(buttonPin1, INPUT); //button
  pinMode(buttonPin2, INPUT); //button
  pinMode(ledPin, OUTPUT); //3,5,6,9,10,11 PWM
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == LOW)
  {
    n += 5;
    if (n >= 255)
    {
      n = 255;
    }
    analogWrite(ledPin, n);
    delay(300);
  }
  if (buttonState2 == LOW)
  {
    n -= 5;
    if (n <= 0)
    {
      n = 0;
    }
    analogWrite(ledPin, n);
    delay(300);
  }

}
