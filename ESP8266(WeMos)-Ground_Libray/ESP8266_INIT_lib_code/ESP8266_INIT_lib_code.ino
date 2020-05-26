#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266_Init.h>
ESP8266_Init esp;

void setup() {
  esp.begin(9600);
  esp.println("ESP gestartet");
  esp.init-wifi(ssid, password);
  
  esp.print("Verbindung wird hergestellt...");
  while(esp.status() != WL_CONNECTED){
    delay(500);
    esp.print(".");
  }
  esp.println();
  esp.print("Verbindungsvorgang erfolgreich IP-Adresse: ");
  esp.print(esp.localIP());
  if(esp.begin (url)){
    esp.println("DNS(URL-Erreichbarkeit) gestartet: ");
  }
  
  server.onNotFound([](){
    server.send(404, "text/plain", "Link wurde nicht gefunden");
  });
  server.on("/", [](){
    server.send(200, "text/plain", "ESP-Startseite");
  });
  server.begin();
  }
void loop() {
server.handleClient();
}
