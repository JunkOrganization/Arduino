#define P_D 5
#define P_C 4
#define P_B 3
#define P_A 2
#define P_G A0
#define P_DI A1
#define P_CLK A2
#define P_LAT A3
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

void setup() {
  pinMode(P_D,OUTPUT);
  pinMode(P_C,OUTPUT);
  pinMode(P_B,OUTPUT);
  pinMode(P_A,OUTPUT);
  pinMode(P_G,OUTPUT);
  pinMode(P_DI,OUTPUT);
  pinMode(P_CLK,OUTPUT);
  pinMode(P_LAT,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  EPrint(startscene);
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
