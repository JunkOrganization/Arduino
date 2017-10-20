int carRed1 = 13; //设置纵向汽车灯
int carYellow1 = 12;
int carGreen1 = 11;
int carRed2 = 3; //设置横向汽车灯
int carYellow2 = 2;
int carGreen2 = 1;
//顺序为carRed1,carYellow1,carGreen1,carRed2,carYellow2,carGreen2
long lights[5] = {0x21, 0x32, 0xC,0x16, 0x00};
void skin(int num);

void setup()
{
  pinMode(carRed1, OUTPUT);
  pinMode(carYellow1, OUTPUT);
  pinMode(carGreen1, OUTPUT);
  pinMode(carRed2, OUTPUT);
  pinMode(carYellow2, OUTPUT);
  pinMode(carGreen2, OUTPUT);
}

void loop()
{
//  digitalWrite(carRed1, HIGH);
  skin(lights[0]);
  delay(5000);

  for (int x = 0; x < 10; x++) {
    skin(lights[1]);
    delay(250);
    skin(lights[4]);
    delay(250);
  }
//  skin(lights[1]);
//  delay(1000);
  skin(lights[2]);
  delay(5000);

  for (int x = 0; x < 10; x++) {
    skin(lights[3]);
    delay(250);
    skin(lights[4]);
    delay(250);
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

