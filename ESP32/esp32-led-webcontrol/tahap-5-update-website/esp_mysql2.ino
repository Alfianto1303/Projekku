#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "WIFIKU1";
const char* password = "gajahmada6";

const char* server = "http://192.168.100.16/website/get_led_status.php"; // Ganti IP dengan IP server lokal kamu
const int ledPin = 2; // D4 pada NodeMCU

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("\nTerhubung ke WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, server);
    int httpCode = http.GET();
    if (httpCode == 200) {
      String payload = http.getString();
      int status_led = payload.toInt();
      digitalWrite(ledPin, status_led ? HIGH : LOW);
      Serial.print("Status LED: ");
      Serial.println(status_led);
    }else {
      Serial.println("Tidak Terhubung ke Database");
      Serial.println(httpCode);
    }
    http.end();
  }
  delay(3000); // cek setiap 3 detik
}