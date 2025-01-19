//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 32.2
4x4_keyboard_control_LED
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
// 将4*4键盘的列端口连接到控制板上相应的数字IO
byte colPins[COLS] = {6,7,8,9};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13;
boolean blink = false;
void setup(){
Serial.begin(9600);
pinMode(ledPin, OUTPUT); // 设置数字引脚为输出
digitalWrite(ledPin, HIGH); // 设置LED亮
keypad.addEventListener(keypadEvent); //为这个小键盘添加EventListener
}
void loop(){
char key = keypad.getKey();
if (key != NO_KEY) {
Serial.println(key);
}
if (blink){
digitalWrite(ledPin,!digitalRead(ledPin));
delay(100);
}
}
//处理一些特殊事件
void keypadEvent(KeypadEvent key){
switch (keypad.getState()){
case PRESSED:
switch (key){
case '#': digitalWrite(ledPin,!digitalRead(ledPin)); break;
case '*':
digitalWrite(ledPin,!digitalRead(ledPin));
break;
}
break;
case RELEASED:
switch (key){
case '*':
digitalWrite(ledPin,!digitalRead(ledPin));
blink = false;
break;
}
break;
case HOLD:
switch (key){
case '*': blink = true; break;
}
break;
}
}
//**********************************************************************************
