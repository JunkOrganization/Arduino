void setup() {
  pinMode(3,OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  val=map( val, 0, 1023, 0, 255);
  analogWrite(3,val);
}
