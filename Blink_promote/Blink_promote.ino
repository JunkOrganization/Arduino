int ledPin = 13;
#define TIME 1000
long time_low = 0 , time_high = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int x = 0; x < 3; x++)
  {
    if (millis() < time_high + TIME)  //采用millis()：返回自Microduino板开始运行当前程序的毫秒数  milli-second
    {
      digitalWrite(ledPin, HIGH); //采用millis()比delay()函数效果更好，占用资源少，对系统拖延较少。
      time_low = millis();
    }
    else
    {
      digitalWrite(ledPin, LOW);
      if ( millis() > time_low + TIME)
        time_high = millis();
    }
  }
}
