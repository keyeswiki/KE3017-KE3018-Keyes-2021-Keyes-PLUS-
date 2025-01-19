//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 31.1
Read_the_door_card_number_value
http//www.keyes-robot.com
*/
#include <Wire.h>
#include "MFRC522_I2C.h"

// 0x28是SDA上的i2c地址。如果不匹配，请用i2c 扫描仪检查您的地址.
MFRC522 mfrc522(0x28);   // 创建MFRC522实例.

void setup() {
  Serial.begin(115200);           // 初始化与PC的串行通信
  Wire.begin();                   // 初始化I2C
  mfrc522.PCD_Init();             // 初始化 MFRC522
  ShowReaderDetails();            // 显示PCD - MFRC522读卡器详细信息
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop() {
  // 寻找新的卡片，如果存在并选择一个.
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // 选中其中一个门卡。UID和SAK都为mfrc522.uid.
  
  // 转储 UID
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();
}

void ShowReaderDetails() {
  // 获取MFRC522软件版本
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown)"));
  Serial.println("");
  // 当返回0x00或0xFF时，通信信号可能失败
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}
//**********************************************************************************
