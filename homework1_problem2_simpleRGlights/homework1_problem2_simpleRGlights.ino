int carRed = 13; //设置汽车灯
int carYellow = 12;
int carGreen = 11;
void changeLights();

void setup() {
  //所有LED设置为输出模式
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
}

void loop()
{
  changeLights();
}
void changeLights() {
  digitalWrite(carGreen, LOW);
  digitalWrite(carRed, HIGH); //汽车红灯亮5s
  delay(5000); //等待5秒

  //  //digitalWrite(carGreen, LOW); //汽车绿灯灭
  //  digitalWrite(carYellow, HIGH); //汽车黄灯亮
  //  digitalWrite(carRed, HIGH); //汽车红灯亮
  //  delay(1000); //为安全考虑等待1秒

  //闪烁行人灯红黄灯，提示可过马路时间快到
  for (int x = 0; x < 10; x++) {
    digitalWrite(carRed, HIGH);
    digitalWrite(carYellow, HIGH);
    delay(250);
    digitalWrite(carRed, LOW);
    digitalWrite(carYellow, LOW);
    delay(250);
  }

  digitalWrite(carRed, LOW);//行人红灯灭
  digitalWrite(carGreen, HIGH);//行人绿灯亮5s
  delay(5000);
}
