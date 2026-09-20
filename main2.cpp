#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200); // pin default untuk Serial2 adalah RX2 = 16, TX2 = 17
  Serial2.setTimeout(5000);

  //setting koneksi LCD
  Wire.begin(21, 22); // nilai default 21,22 I2C
  // Inisialisasi LCD
  lcd.init();
  // Menyalakan lampu latar (backlight)
  lcd.backlight();
  // Menampilkan teks di baris pertama (kolom 0, baris 0)
  lcd.setCursor(0, 0);
  lcd.print("Halo, ESP32!");
  // Menampilkan teks di baris kedua (kolom 0, baris 1)
  lcd.setCursor(0, 1);
  lcd.print("Siap Menerima Data");
}

void loop() {
  String data = "";

  if (Serial2.available()) {
    data = Serial2.readStringUntil('\n');
    data.trim();
    lcd.clear();

    //menampilkan data di LCD
    // Menampilkan teks di baris pertama (kolom 0, baris 0)
    lcd.setCursor(0, 0);
    lcd.print("Data diterima:");

    // Menampilkan teks di baris kedua (kolom 0, baris 1)
    lcd.setCursor(0, 1);
    lcd.print(data); // buang \r atau spasi/whitespace sisa di ujung

    //kirim konfirmasi ke esp-1 data diterima
    Serial2.println(data);
  }
}