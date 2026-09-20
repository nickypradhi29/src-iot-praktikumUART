#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(5000);
  Serial2.begin(115200);
  Serial.println("Masukkan text: (maks 16 karakter)");

  while (Serial.available() > 0) {
    Serial.read();
  }
  while (Serial2.available() > 0) {
    Serial2.read();
  }
}

void loop() {

  if (Serial.available()) {
    String data = "";
    // baca data input dari serial monitor sampai menemukan karakter '\n' (enter)
    data = Serial.readStringUntil('\n');
    data.trim();  // buang \r atau spasi/whitespace sisa di ujung

    Serial2.println(data);

    Serial.println("ESP-1 mengirim data:");
    Serial.println(data);

    delay(500); //tunggu 0.5 detik sebelum membaca balasan dari node 2

    if (Serial2.available()) {
      String data = "";
      data = Serial2.readStringUntil('\n');
      data.trim(); // buang \r atau spasi/whitespace sisa di ujung

      Serial.println("ESP-2 Konfirmasi data diterima:");
      Serial.println(data);
    }
  }

  Serial.println("Masukkan text (maksimal 16 karakter): ");
}
