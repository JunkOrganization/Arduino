int motorPin = 7;

void setup() 
{
   pinMode(motorPin, OUTPUT);

}

void loop() 
{
  digitalWrite(motorPin, LOW);  // LOW to enable turn on the NO switch  
  delay(1000);
  digitalWrite(motorPin, HIGH);
  delay(1000);
  
}
