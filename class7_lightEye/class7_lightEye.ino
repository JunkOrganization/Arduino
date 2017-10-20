int a =600;        // 阈值。根据实际情况进行调整。使得光线强时小于此值，弱时大于此值。

void setup ()
{
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}
void loop()
{
  int n = analogRead(A0); //读取模拟口A0数值
  Serial.println(n);
  if (n>= a )            //对光线强度进行判断，小于预设值关闭LED,否则就点亮
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  delay(100);
}
