int carRed1 = 13; //设置纵向汽车灯
int carYellow1 = 12;
int carGreen1 = 11;
int carRed2 = 10; //设置横向汽车灯
int carYellow2 = 9;
int carGreen2 = 8;
const int buttonPin1 = 2;     // 定义按键输入引脚
const int buttonPin2 = 3;
//顺序为carRed1,carYellow1,carGreen1,carRed2,carYellow2,carGreen2
long lights[5] = {0x21, 0x32, 0xC, 0x16, 0x00};
int buttonState1 = 0;        //初始化按键值
int buttonState2 = 0;
boolean led;   //定义led为布尔型（true或false）
int lightState;
void skin(int num);
void changeLights();
void stateChange1();
void stateChange2();

void setup()
{
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);
  attachInterrupt(0, stateChange1, FALLING);
  attachInterrupt(1, stateChange2, CHANGE);
}

void loop()
{
  changeLights(1);
}

void changeLights(int num)
{
  if (num == 1)   //1路口红灯5s
  {
    skin(lights[0]);
    delay(5000);
    lightState = 1;
    num++;
  }

  if (num == 2)   //1路口红黄1s
  {
//    for (int x = 0; x < 10; x++) {
//      skin(lights[1]);
//      delay(250);
//      skin(lights[4]);
//      delay(250);
//    }
    lightState = 2;
      skin(lights[1]);
      delay(1000);
    num++;
  }

  if (num == 3)   //1路口绿灯5s
  {
    skin(lights[2]);
    delay(5000);
    lightState = 3;
    num++;
  }

  if (num == 4)   //1路口黄灯1s
  {
//    for (int x = 0; x < 10; x++) {
//      skin(lights[3]);
//      delay(250);
//      skin(lights[4]);
//      delay(250);
//    }
    lightState = 4;
    skin(lights[3]);
    delay(1000);
  }
}

void skin(int num)
{
  digitalWrite(carRed1, ((num >> 5) & 0x01));
  digitalWrite(carYellow1, ((num >> 4) & 0x01));
  digitalWrite(carGreen1, ((num >> 3) & 0x01));
  digitalWrite(carRed2, ((num >> 2) & 0x01));
  digitalWrite(carYellow2, ((num >> 1) & 0x01));
  digitalWrite(carGreen2, ((num >> 0) & 0x01));
}

void stateChange1()
{
  if (lightState == 3 || lightState == 4)
    changeLights(3);
  else if (lightState == 1)
    changeLights(2);
}

void stateChange2()
{
  if (lightState == 1 || lightState == 2)
    changeLights(1);
  else if (lightState == 3)
    changeLights(4);
}

