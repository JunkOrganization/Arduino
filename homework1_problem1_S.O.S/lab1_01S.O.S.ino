int ledPin = 13;
#define TIME_SHORT 200
#define TIME_LONG 800
#define TIME_WAIT1 150
#define TIME_WAIT2 200
long time_short = 0 , time_long = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //三个短闪烁来表示字母“S”
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(ledPin, HIGH);
    delay(TIME_SHORT);
    digitalWrite(ledPin, LOW);
    delay(TIME_WAIT1);
  }

  delay(TIME_WAIT2);
  
  //三个长闪烁来表示字母“O”
  for (int x = 0; x < 3; x++) {
    digitalWrite(ledPin, HIGH);
    delay(TIME_LONG);
    digitalWrite(ledPin, LOW);
    delay(TIME_WAIT1);
  }

  delay(TIME_WAIT2);

  //再用三个短闪烁来表示字母“S”
  for (int x = 0; x < 3; x++) {
    digitalWrite(ledPin, HIGH);           //设置LED 为开
    delay(TIME_SHORT);                           //延时150毫秒
    digitalWrite(ledPin, LOW);            //设置LED 为关
    delay(TIME_WAIT1);                           //延时100毫秒
  }

  //在重复S.0.S信号前等待3秒
  delay(3000);
}
