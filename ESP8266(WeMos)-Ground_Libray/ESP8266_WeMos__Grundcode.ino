#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

const char* ssid = "WLAN-FMKZXT";
const char* password = "passwort des WLAN";
const char * url = "zentrale";
void setup() {
  Serial.begin(9600);
  Serial.println("ESP gestartet");
  WiFi.begin(ssid, password);
  
  Serial.print("Verbindung wird hergestellt...");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Verbindungsvorgang erfolgreich IP-Adresse: ");
  Serial.print(WiFi.localIP());
  if(MDNS.begin (url)){
    Serial.println("DNS(URL-Erreichbarkeit) gestartet: ");
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
