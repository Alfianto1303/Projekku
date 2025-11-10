#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid = "HPKU";
const char* password = "12345678";

bool EspLedState = false;

int led = 2;

void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("koneksi ke wifi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("terkoneksi");
  Serial.println(WiFi.localIP());

  server.on("/esp", HTTP_GET, getEspLed);

  server.on("/esp", HTTP_POST, setEspLed);

  server.begin();
  Serial.println("Server Menyala");
}

void loop() {
  server.handleClient();

}

void setEspLed() {
  EspLedState = !EspLedState;
  digitalWrite(led, EspLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", EspLedState ? "ON" : "OFF");
}

void getEspLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", EspLedState ? "ON" : "OFF");
}