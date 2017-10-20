//unfinished
long  data[5][8]=
{
  0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,//单独一个从左至右亮
  0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,//单独一个从从右至左亮
  0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,//两边往中间亮及中间往两边亮
  0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,//从左到右依次点亮
  0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,//从右到左依次熄灭
};
int ledPin[8]={10,9,8,7,4,11,12,13};
const int buttonPin = 2;     // 定义按键输入引脚
int buttonState = 0;        //初始化按键值
int turn=0;

void changeLights(int num);
void leddisplay(int num);
int buttonRead();

void setup() {
  for(int i=0;i<8;i++) 
  {
    pinMode(ledPin[i],OUTPUT);  //设置输出引脚
  } 
}

void loop() 
{
  turn = turn % 5;
  changeLights(turn);
}

void changeLights(int num)
{
  for(int i=0; i<8; i++)  //分别读取不同花样灯
  {
    leddisplay(data[turn][i]);
    delay(300);     //每个状态显示200ms
//    for(int j=0;j<2;j++)
    {
//      delay(100);
      if(buttonRead())
       return;
    }
  }
//  leddisplay(0x00);   //循环完毕全灭
//  delay(200);
}

void leddisplay(int num)    // 将花样字模对应到端口显示
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(ledPin[i],((num>>i)&0x01));
  }
}

int buttonRead()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    turn++;
    return 1;
  }
  return 0;
}

