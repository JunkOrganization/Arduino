int pin = 2;  //定义引脚为D2
float time1,time2;  //定义变量为浮点数
void setup()
{
  Serial.begin(115200);  //串口波特率
  pinMode(pin,  INPUT_PULLUP); //设置引脚为内部上拉输入模式
}
 
void loop()
{
  // 读取引脚上的低电平脉冲，最大脉冲时间间隔为60秒，
  // 并且把结果赋值给time1变量
  Serial.print("Hello World!");
  time1= pulseIn(pin, LOW,60000000)/1000;//将读取的时间转换成ms
  Serial.print(time1); //通过串口输出time1变量
  Serial.print("ms  ");
  time2= pulseIn(pin, LOW,60000000)/1000.0;//将读取的时间转换成ms
  Serial.print(time2); //通过串口输出time2变量
  Serial.println("ms");//通过串口打印出单位并换行准备输出下一个值
}
