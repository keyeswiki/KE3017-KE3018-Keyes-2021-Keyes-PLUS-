//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 35.2
WIFI smart home
http//www.keyestudio.com 
*/
#include <DHT.h>
DHT dht(2, 11);

#include<Servo.h>
Servo myservo;

char wifiData;
int distance1;
String dis_str;

const int dhtPin = 2;
const int relayPin = 5;
const int IN1 = A2;
const int IN2 = A3;
const int trigPin = 12;
const int echoPin = 13;
const int servoPin = 9;

int ip_flag = 1;
int ultra_state = 1;
int temp_state = 1;
int humidity_state = 1;

void setup() {
  Serial.begin(9600);
  pinMode(dhtPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //关闭电风扇
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(relayPin, LOW); //关闭继电器

  myservo.attach(9);

  dht.begin();
}

void loop() {
  if(Serial.available() > 0)
  {
    wifiData = Serial.read();
//    Serial.println(wifiData);
    
    if(wifiData == '*')
    {
      ip_flag = 0;
    }

    if(ip_flag == 1)
    {
      //String ip_addr = Serial.readStringUntil('#');
      Serial.print(wifiData);
      if(wifiData == '#')
      {
        Serial.println("");
      }
      delay(100);
    }
  }

  switch(wifiData)
    {
      case 'a': digitalWrite(relayPin, HIGH); break;
      case 'b': digitalWrite(relayPin, LOW); break;
      case 'c': myservo.write(180); delay(200); break;
      case 'd': myservo.write(0); delay(200); break;
      case 'e': digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); break;
      case 'f': digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); break;
      case 'g': while(ultra_state>0)
                  {
                    Serial.print("Distance = "); 
                    Serial.print(checkdistance());
                    Serial.println("#"); 
                    ultra_state = 0;
                  }
                  break;
      case 'h': ultra_state = 1; break;
      case 'i': while(temp_state>0)
                {
                  Serial.print("Temperature = "); 
                  Serial.print(dht.readTemperature());
                  Serial.println("#");
                  temp_state = 0;
                }
                break;
      case 'j': temp_state = 1; break;
      case 'k': while(humidity_state > 0)
                {
                  Serial.print("Humidity = "); 
                  Serial.print(dht.readHumidity());
                  Serial.println("#");
                  humidity_state = 0;
                }
                break;
      case 'l': humidity_state = 1; break;
    }
  
}

int checkdistance() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  int distance = pulseIn(13, HIGH) / 58;
  
  delay(10);
  return distance;
}
//**********************************************************************************
