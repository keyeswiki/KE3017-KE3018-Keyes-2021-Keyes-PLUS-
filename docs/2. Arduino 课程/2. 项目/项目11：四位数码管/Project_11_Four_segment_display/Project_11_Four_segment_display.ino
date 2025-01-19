//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 11
Four_segment_display
http//www.keyes-robot.com
*/
#include "TM1650.h"
#define CLK A5    //TM1650引脚定义，也可以更改为其他端口       
#define DIO A4
TM1650 DigitalTube(CLK,DIO);

void setup(){
  //DigitalTube.setBrightness();  //设置亮度，0- 7，默认:2
  //DigitalTube.displayOnOFF();   //显示开启或关闭，0=关闭显示，1=打开显示，默认为1
  for(char b=1;b<5;b++){
    DigitalTube.clearBit(b);      //清除数码管第几位.
  }
  DigitalTube.displayDot(1,true); //显示数码管第一个点.
  DigitalTube.displayDot(2,true);
  DigitalTube.displayDot(3,true);
  DigitalTube.displayDot(4,true);
  DigitalTube.displayBit(3,0);    //显示数码管第几位数字; 位数=1---4  数字=0---9
}

void loop(){
  for(int num=0; num<10; num++){
    DigitalTube.displayBit(1,num);
    DigitalTube.displayBit(2,num);
    DigitalTube.displayBit(3,num);
    DigitalTube.displayBit(4,num);
    delay(1000);
  }
}
//**********************************************************************************
