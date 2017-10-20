const int buttonPin = 2;     // 定义按键输入引脚
const int ledPin =  11;     //定义led引脚
int buttonState = 0;        //初始化按键值
boolean led;   //定义led为布尔型（true或false）

void setup() {
  pinMode(ledPin, OUTPUT);    //设置led引脚为输出状态
  pinMode(buttonPin, INPUT_PULLUP); //设置按键引脚为输入状态
}
void loop() {
  buttonState = digitalRead(buttonPin);//从指定的数字引脚读取数值，是高还是低。
  if (buttonState == HIGH)
    //外部下拉，因为这样起始状态为低，
    //只有按下才是高，按下才翻转，否则不按时则会闪烁
  {
    delay(100);                 //短暂延时，防抖
    // delay(1000);             //长按
    // if (buttonState == LOW)  //判断是否还是低
    led = !led;
  }
  else {
    digitalWrite(ledPin, led);
  }
}
