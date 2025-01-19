//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 32.1
4x4_Keypad_display
http//www.keyes-robot.com
*/
#include <Keypad.h>
const byte ROWS = 4; // 定义行4
const byte COLS = 4; // 定义列4 
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
// 将4*4键盘的行端口连接到控制板上相应的数字IO
byte rowPins[ROWS] = {2,3,4,5};
//将4*4键盘的列端口连接到控制板上相应的数字IO
byte colPins[COLS] = {6,7,8,9};
// 从键盘类库调用相应函数
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey();
if (key != NO_KEY){
Serial.println(key);
}
}
//**********************************************************************************
