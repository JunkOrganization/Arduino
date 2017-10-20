void setup()
{
  pinMode(3,OUTPUT);
}

void loop()
{
  for(int i=200;i<=800;i++)  //用循环的方式将频率从200HZ 增加到800HZ
  {
    tone(3,i);     //在D3端口输出频率
    delay(5);      //该频率维持5毫秒   
  }
  tone(3,0);
  delay(4000);     //最高频率下维持4秒钟

  for(int i=800;i>=200;i--)  // 频率降低
  {
    tone(3,i);
    delay(10);    //该频率维持10毫秒   
  }
}
