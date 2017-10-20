float temp;   //创建一个浮点型变量temp作为存储空间准备存放数据
void setup()
{
  Serial.begin(115200);     //波特率
}
void loop()
{ 
  int V1 = analogRead(A0);    //从A0口读取电压数据，返回值为0-1024
//  float vol = V1*(5.0 / 1023.0);  //换算 ：测量范围为0-5V   
  float vol = map( V1, 0, 1023, 0, 5);          
  if (vol == temp)   //过滤重复的数据，仅输出和上次不同的电压值
  {
    temp = vol;       //暂存这次的值到temp
  }
  else
  { 
    Serial.print(vol);    //串口输出电压值，并且不换行  
    Serial.println(" V"); //串口输出字符V，并且换行
    temp = vol;
    delay(1000);          //等待1秒钟，用于控制数据的刷新速度。
  }
}
