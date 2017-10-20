void setup()
{
 Serial.begin(9600);
  pinMode(10,OUTPUT);
}
 
void loop()
{
  while(Serial.available())
   {
     char c=Serial.read();
      if(c== '1')
        {
          Serial.print('0');
          Serial.print('\n');
          digitalWrite(10, HIGH);  
          delay(1000);
        }
   }
}
