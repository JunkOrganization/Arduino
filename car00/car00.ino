//created by ZhaoNing
  //car
#define IN1 9  //右轮 上
#define IN2 13  //右轮 下
#define ENA 10
#define IN5 11 //左轮 上
#define IN6 12 //左轮 下
#define ENC 6
//#define IN7 9  //水枪 正
//#define IN8 10 //水枪 负
  //led
#define P_D 5
#define P_C 4
#define P_B 3
#define P_A 2
#define P_G A0
#define P_DI A1
#define P_CLK A2
#define P_LAT A3

#define LEFT '3' //左转编码
#define RIGHT '4'//右转编码
#define GO '1'//前进编码
#define BACK '2'//后退编码
#define STOP '0'//停止编码
#define FIRE '5'
#define SPEED_SLOW 's'
#define SPEED_NOEMAL 'n'
#define SPEED_QUICK 'q'
void initCar();
void go();
void turnLeft();
void turnRight();
void back();
void stopCar();
void fire();
void set_speed(int i);
void EPrint(bool arr[][16]);
void Send(bool arr[]);
void ChooseLine(int m);
void EWrite(int wpin,bool what);

bool startscene[16][16]=
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0},

  {0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,0},
  {0,0,1,0,1,1,0,0,0,0,1,1,0,1,0,0},
  {0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},

  {0,0,1,0,0,1,1,1,1,1,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0},

  {0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
bool LED_SLOW[16][16]=   //慢
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0},
  {0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0},
  
  {0,1,0,1,1,0,1,0,0,0,0,0,0,1,0,0},
  {0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0},
  {0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0},

  {0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0},
  {1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0},

  {0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0},
  {0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0},
  {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
};

bool LED_QUICK[16][16]=   //快
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},

  {0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0},
  {0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0},
  {0,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0},
  {0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0},

  {0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0},
  {0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0},

  {0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0},
  {0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0},
  {0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1},
};

bool LED_LEFT[16][16]=   //左
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

  {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

bool LED_RIGHT[16][16]=   //右
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},

  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

bool LED_FORWARD[16][16]=   //前
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0},

  {0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

bool LED_BACKWARD[16][16]=   //后
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},

  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0},

  {0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0},
  {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int ledNum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN5,OUTPUT);
  pinMode(IN6,OUTPUT);
//  pinMode(IN7,OUTPUT);
//  pinMode(IN8,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENC,OUTPUT);

  pinMode(P_D,OUTPUT);
  pinMode(P_C,OUTPUT);
  pinMode(P_B,OUTPUT);
  pinMode(P_A,OUTPUT);
  pinMode(P_G,OUTPUT);
  pinMode(P_DI,OUTPUT);
  pinMode(P_CLK,OUTPUT);
  pinMode(P_LAT,OUTPUT);
  initCar();
}

void loop() {
   if(Serial.available()>0){
      char ch = Serial.read();
      if(ch == GO){
         //前进
         go();
      }else if(ch == BACK){
         //后退
         back();
      }else if(ch == LEFT){
         //左转
         turnLeft();
      }else if(ch == RIGHT){
        //右转
        turnRight();
      }else if(ch == STOP){
        //停车
        stopCar();
      }
//      else if(ch == FIRE){
//        //开火
//        fire();
//      }
      else if(ch == SPEED_SLOW){
        set_speed(100);
        ledNum=1;
      }
      else if(ch == SPEED_NOEMAL){
        set_speed(150);
        ledNum = 0;
      }
      else if(ch == SPEED_QUICK){
        set_speed(255);
        ledNum=2;
      }
    }
     if(ledNum == 1)
      EPrint(LED_SLOW);
     else if(ledNum == 2)
      EPrint(LED_QUICK);
     else if(ledNum == 3)
      EPrint(LED_LEFT);
     else if(ledNum == 4)
      EPrint(LED_RIGHT);  
     else 
      EPrint(startscene);

}

void initCar(){
  //默认全是低电平 停止状态
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);
  digitalWrite(IN5,LOW);   
  digitalWrite(IN6,LOW);
//  digitalWrite(IN7,LOW);
//  digitalWrite(IN8,LOW);
  set_speed(255);
  EPrint(startscene);
}

void go(){
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         //右轮前进
  digitalWrite(IN5,HIGH);      
  digitalWrite(IN6,LOW);         //左轮前进
}

void turnLeft(){
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,HIGH);         //右轮前进
  digitalWrite(IN5,HIGH);      
  digitalWrite(IN6,LOW);         //左轮不动
  ledNum=3;
}

void turnRight(){
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         //右轮不动
  digitalWrite(IN5,LOW);      
  digitalWrite(IN6,HIGH);         //左轮前进
  ledNum=4;
}

void back(){
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,HIGH);        //右轮后退
  digitalWrite(IN5,LOW);      
  digitalWrite(IN6,HIGH);        //左轮后退
}

void stopCar(){
  initCar();
  ledNum=0;
}

//void fire()
//{
//  digitalWrite(IN7,HIGH);      
//  digitalWrite(IN8,LOW);
//  set_speed(255);
//  delay(1000);
//  digitalWrite(IN7,LOW);      
//}

void set_speed(int i)
{
  analogWrite(ENA,i);
  analogWrite(ENC,i);
}

void EPrint(bool arr[][16])
{
  for(int i=0;i<16;i++)
  {
    digitalWrite(P_G,HIGH);
    Send(arr[i]);
    digitalWrite(P_LAT,HIGH);
    delayMicroseconds(1);
    digitalWrite(P_LAT,LOW);
    delayMicroseconds(1);
    ChooseLine(i);
    digitalWrite(P_G,LOW);
    delayMicroseconds(100);
  }
}

void Send(bool arr[])
{
  digitalWrite(P_CLK,LOW);
  delayMicroseconds(1);
  digitalWrite(P_LAT,LOW);
  delayMicroseconds(1);
  for(int i=0;i<16;i++)
  {
    EWrite(P_DI,!arr[15-i]);
    delayMicroseconds(1);
    digitalWrite(P_CLK,HIGH);
    delayMicroseconds(1);
    digitalWrite(P_CLK,LOW);
    delayMicroseconds(1);
  }
}

void ChooseLine( int m)
{  
  switch(m)
  {
    case 0:     
      digitalWrite(P_D, LOW);digitalWrite(P_C, LOW);digitalWrite(P_B, LOW);digitalWrite(P_A, LOW);          
      break;
    case 1:         
      digitalWrite(P_D, LOW);digitalWrite(P_C, LOW);digitalWrite(P_B, LOW);digitalWrite(P_A, HIGH);     
      break;
    case 2:         
      digitalWrite(P_D, LOW);digitalWrite(P_C, LOW);digitalWrite(P_B, HIGH);digitalWrite(P_A, LOW);     
      break;
    case 3:         
      digitalWrite(P_D, LOW);digitalWrite(P_C, LOW);digitalWrite(P_B, HIGH);digitalWrite(P_A, HIGH);    
      break;
    case 4:
      digitalWrite(P_D, LOW);digitalWrite(P_C, HIGH);digitalWrite(P_B, LOW);digitalWrite(P_A, LOW);     
      break;
    case 5:
      digitalWrite(P_D, LOW);digitalWrite(P_C, HIGH);digitalWrite(P_B, LOW);digitalWrite(P_A, HIGH);    
      break;
    case 6:
      digitalWrite(P_D, LOW);digitalWrite(P_C, HIGH);digitalWrite(P_B, HIGH);digitalWrite(P_A, LOW);    
      break;
    case 7:
      digitalWrite(P_D, LOW);digitalWrite(P_C, HIGH);digitalWrite(P_B, HIGH);digitalWrite(P_A, HIGH);     
      break;
    case 8:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, LOW);digitalWrite(P_B, LOW);digitalWrite(P_A, LOW);     
      break;
    case 9:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, LOW);digitalWrite(P_B, LOW);digitalWrite(P_A, HIGH);    
      break;  
    case 10:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, LOW);digitalWrite(P_B, HIGH);digitalWrite(P_A, LOW);    
      break;
    case 11:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, LOW);digitalWrite(P_B, HIGH);digitalWrite(P_A, HIGH);     
      break;
    case 12:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, HIGH);digitalWrite(P_B, LOW);digitalWrite(P_A, LOW);    
      break;
    case 13:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, HIGH);digitalWrite(P_B, LOW);digitalWrite(P_A, HIGH);     
      break;
    case 14:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, HIGH);digitalWrite(P_B, HIGH);digitalWrite(P_A, LOW);     
      break;
    case 15:
      digitalWrite(P_D, HIGH);digitalWrite(P_C, HIGH);digitalWrite(P_B, HIGH);digitalWrite(P_A, HIGH);    
      break;
    default: 
      break;  
  }
}

void EWrite(int wpin,bool what)
{
  if(what)
  {
    digitalWrite(wpin,HIGH);
  }
  else
  {
    digitalWrite(wpin,LOW);
  }
}

