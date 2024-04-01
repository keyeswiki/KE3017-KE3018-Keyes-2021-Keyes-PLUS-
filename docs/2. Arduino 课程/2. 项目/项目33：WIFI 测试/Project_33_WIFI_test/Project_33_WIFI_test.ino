//**********************************************************************************
/*
Keyes 2021入门学习套件
Project 33
WIFI test
http//www.keyestudio.com 
*/
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

#ifndef STASSID
//#define STASSID "your-ssid"
//#define STAPSK  "your-password"
#define STASSID "ChinaNet-2.4G-0DF0"  //用户Wifi名称
#define STAPSK  "ChinaNet@233"   //用户Wifi密码
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// 端口80的TCP服务器将响应HTTP请求
WiFiServer server(80);

void setup(void) {
  Serial.begin(115200);

  // 连接WiFi网络
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // 等待连接
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // 设置mDNS响应器:
  // - 在本例中，第一个参数是域名
  //   完全限定域名为“esp8266.local”
  // - 第二个参数是IP地址
  //   我们通过WiFi网络发送IP地址
  if (!MDNS.begin("esp8266")) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");

  // 启动TCP (HTTP)服务器
  server.begin();
  Serial.println("TCP server started");

  // 添加服务器到 MDNS-SD
  MDNS.addService("http", "tcp", 80);
}

void loop(void) {

  MDNS.update();

  // 检查客户端是否已连接
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("");
  Serial.println("New client");

  // 等待来自客户端的数据有效
  while (client.connected() && !client.available()) {
    delay(1);
  }

  // 读取HTTP请求的第一行
  String req = client.readStringUntil('\r');

  // HTTP请求的第一行如下所示 "GET /path HTTP/1.1"
  // Retrieve the "/path" part by finding the spaces
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
    Serial.print("Invalid request: ");
    Serial.println(req);
    return;
  }
  req = req.substring(addr_start + 1, addr_end);
  Serial.print("Request: ");
  Serial.println(req);
  client.flush();

  String s;
  if (req == "/") {
    IPAddress ip = WiFi.localIP();
    String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
    s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
    s += ipStr;
    s += "</html>\r\n\r\n";
    Serial.println("Sending 200");
  } else {
    s = "HTTP/1.1 404 Not Found\r\n\r\n";
    Serial.println("Sending 404");
  }
  client.print(s);

  Serial.println("Done with client");
}
//**********************************************************************************
