int ledPin=11;  //D3、D5、D6、D9、D10、D11是pwm输出口

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int fadeValue=0;fadeValue<=255;fadeValue+=5)
  //循环语句，控制PWM亮度的增加，控制fadeValue的变化大小可以控制亮度级别
  {
    analogWrite(ledPin,fadeValue);   //将亮度级别写入给led
    delay(30);                       
  }
   for(int fadeValue=255;fadeValue>=0;fadeValue-=5)
   //循环语句，控制PWM亮度减小，控制fadeValue的变化大小可以控制亮度级别
  {
    analogWrite(ledPin,fadeValue); //将亮度级别写入给led
    delay(30);                      
  }
}
