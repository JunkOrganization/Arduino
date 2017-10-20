void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    delay(2000);
    digitalWrite(3,HIGH);
    delay(1000);


}
