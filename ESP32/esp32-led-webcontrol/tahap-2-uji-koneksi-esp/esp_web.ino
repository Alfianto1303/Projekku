#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);
const int led = 2;
bool kondisi = false;

void handleRoot() {
  String html = "<h1>Kontrol LED ESP32 (Access Point)</h1>";
  html += "<p>LED saat ini: ";
  html += (kondisi ? "ON" : "OFF");
  html += "</p>";
  html += "<a href=\"/on\"><button>NYALAKAN</button></a>";
  html += "<a href=\"/off\"><button>MATIKAN</button></a>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(led, HIGH);
  kondisi = true;
  handleRoot();
}

void handleOff() {
  digitalWrite(led, LOW);
  kondisi = false;
  handleRoot();
}

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  // ESP berfungsi sebagai pemancar
  const char* ssid = "COBA_ESP32";
  const char* password = "12345678";
  WiFi.softAP(ssid, password);

  Serial.println("Access Point aktif!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Menjalankan Websitenya
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
  Serial.println("Web Server Aktif!");
}

void loop() {
  server.handleClient();
}