//**********************************************************************************
/*
Keyes 2021入门学习套件 
Project 10
one_segment_display
http//www.keyes-robot.com
*/
// 设置每段的IO引脚
int a=7;// 设置a段数字引脚为7
int b=6;// 设置b段数字引脚为6
int c=5;// 设置c段数字引脚为5
int d=10;//设置d段数字引脚为10
int e=11;//设置e段数字引脚为11
int f=8;//数字f段数字引脚为8
int g=9;//设置g段数字引脚为9
int dp=4;//设置dp段数字引脚为4
void digital_0(void) // 显示数字0
{
unsigned char j;
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
digitalWrite(dp,LOW);
}
void digital_1(void) //显示数字1
{
unsigned char j;
digitalWrite(c,HIGH);// 将5脚设为高电平，点亮c段led
digitalWrite(b,HIGH);// 点亮b段led
for(j=7;j<=11;j++)// 关闭其它段led
digitalWrite(j,LOW);
digitalWrite(dp,LOW);// 关闭dp段led
}
void digital_2(void) // 显示数字2
{
unsigned char j;
digitalWrite(b,HIGH);
digitalWrite(a,HIGH);
for(j=9;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(c,LOW);
digitalWrite(f,LOW);
}
void digital_3(void) // 显示数字3
{digitalWrite(g,HIGH);
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(dp,LOW);
digitalWrite(f,LOW);
digitalWrite(e,LOW);
}
void digital_4(void) // 显示数字4
{digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
digitalWrite(a,LOW);
digitalWrite(e,LOW);
digitalWrite(d,LOW);
}
void digital_5(void) // 显示数字5
{
unsigned char j;
digitalWrite(a,HIGH);
digitalWrite(b, LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e, LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
}
void digital_6(void) // 显示数字6
{
unsigned char j;
for(j=7;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
}
void digital_7(void) // d显示数字7
{
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
for(j=8;j<=11;j++)
digitalWrite(j,LOW);
}
void digital_8(void) // 显示数字8
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
}
void digital_9(void) // 显示数字9
{
unsigned char j;
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e, LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
}
void setup()
{
int i;// 设置变量i
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);// 设置引脚4-11为“输出”
}
void loop()
{
while(1)
{
digital_9();// 显示数字9
delay(1000); // 等待1秒
digital_8();// 显示数字8
delay(1000); // 等待1秒
digital_7();// 显示数字7
delay(1000); // 等待1秒
digital_6();// 显示数字6
delay(1000); // 等待1秒
digital_5();// 显示数字5
delay(1000); // 等待1秒
digital_4();// 显示数字4
delay(1000); // 等待1秒
digital_3();// 显示数字3
delay(1000); // 等待1秒
digital_2();// 显示数字2
delay(1000); // 等待1秒
digital_1();// 显示数字1
delay(1000);// 等待1秒
digital_0();// 显示数字0
delay(1000);// 等待1秒
}}
//**********************************************************************************
