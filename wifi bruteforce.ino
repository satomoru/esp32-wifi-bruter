#include <WiFi.h>

const char* ssid = "test";
const char* passwords[] = {"password1", "12345678", "password3", "password4", "password5"};
const int num_passwords = sizeof(passwords) / sizeof(passwords[0]);

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < num_passwords; i++) {
    Serial.print("Trying password: ");
    Serial.println(passwords[i]);

    WiFi.begin(ssid, passwords[i]);

    int attempt = 0;
    while (WiFi.status() != WL_CONNECTED && attempt < 10) {
      delay(1000);
      Serial.print(".");
      attempt++;
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println();
      Serial.println("Connected!");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      break;
    } else {
      Serial.println();
      Serial.println("Failed to connect.");
    }
  }
}

void loop() {
 
}
