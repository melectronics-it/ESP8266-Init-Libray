#include "ESP8266_Init"
ESP8266_Init::setup(){
  Serial.begin(9600);
  Serial.println("ESP gestartet");

}
ESP8266_Init::init-wifi(){
  WiFi.begin(ssid, password);
  Serial.print("Verbindung wird hergestellt...");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
    Serial.println();
    Serial.print("Verbindungsvorgang erfolgreich IP-Adresse: ");
    Serial.print(WiFi.localIP());
}
ESP8266_Init::init-dns(){
  if(MDNS.begin (url)){
    Serial.println("DNS(URL-Erreichbarkeit) gestartet: " + url);
  }
}
ESP8266_Init::init-server(){
  server.begin();
  server.onNotFound([](){
    server.send(404, "text/plain", "Link wurde nicht gefunden");
  });
  server.on("/", [](){
    server.send(200, "text/plain", "ESP-Startseite");
  });
}
