void setup() {
  Serial.begin(115200);         //使用115200速率进行串口通讯
  for(int i=2;i<5;i++)          //设置led输出口 2，3,4， 分别接R、G、B 引脚
  {
    pinMode(i, OUTPUT);  
  }
}

void loop() {
  int n = analogRead(A0);    //读取A0口的电压值
  float temp = n * (5.0 / 1023.0*100);   //换算成温度
  if (temp<25)  //低温区的温度值设置、以及led显示
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);    //共阳极，低电平点亮
    digitalWrite(2, HIGH);
  }
  else if (temp>=25 && temp<=28)  //中温区温度范围设置  &&为“与”的意思
  {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (temp>28)   //高温区温度设置
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }
  Serial.println(temp); //串口输出温度数据
  delay(1000);         //等待1秒，控制刷新速度
}
