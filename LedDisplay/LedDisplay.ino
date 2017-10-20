//The third class
long  data[]=
{
  0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,//单独一个从左至右亮
  0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,//单独一个从从右至左亮
  0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,//两边往中间亮及中间往两边亮
  0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,//从左到右依次点亮
  0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,//从右到左依次熄灭
};

void setup() {
  for(int x=3;x<11;x++) 
  {
    pinMode(x,OUTPUT);  //设置输出引脚
  }  

}

void loop() {
  for(int i=0; i<40; i++)  //分别读取不同花样灯
  {
    leddisplay(data[i]);
    delay(200);     //每个状态显示200ms
  }
  leddisplay(0x00);   //循环完毕全灭
  delay(200);

}

void leddisplay(int num)    // 将花样字模对应到端口显示
{
  /*================================================================
  先将16进制数向右移x位（num>>x），x代表了microduinoI/O口对应16进制的某位，
  0是最低位，7是最高位。再将移的数据与0x01按位与，就可以得到16进制数某位的
  数据（0或1），再将其值赋值给microduino的I/O就行。 
  =================================================================*/
  digitalWrite(3, ((num>>0)&0x01)); //第0位输出到3号口
  digitalWrite(4, ((num>>1)&0x01)); //第1位输出到4号口：第1位右移1位到最低位，按位与得到1/0       
  digitalWrite(5, ((num>>2)&0x01));
  digitalWrite(6, ((num>>3)&0x01));
  digitalWrite(7, ((num>>4)&0x01));
  digitalWrite(8, ((num>>5)&0x01));
  digitalWrite(9, ((num>>6)&0x01));
  digitalWrite(10,((num>>7)&0x01));
}
