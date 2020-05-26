#ifndef ESP8266_Init
#define ESP8266_Init
#include <Arduino.h>
#include <ESP8266Wifi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
class Init(){
private : {
  
}
public:{
ESP8266WebServer server(80);
const char* ssid = "WLAN-FMKZXT";
const char* password = "passwort des WLAN";
const char * url = "esp8266";
void setup();
void init-wifi();
void init-dns();
void init-server();
#endif
