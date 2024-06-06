#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h> 
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <TimeLib.h>                 
#include <ESPmDNS.h>
#define SDA_PIN 36
#define SCL_PIN 35
unsigned long previousMillis = 0; // will store last time the display was updated
const long interval = 500; // interval at which to refresh the display (milliseconds)

const char* ssid = "SSID";
const char* password = "PASSWORD";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", -14400, 60000);

char Time[] = "00:00";  // Array now only for hour and minute
byte last_second, second_, minute_, hour_;
U8G2_SSD1306_64X32_1F_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); 

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_logisoso22_tf);  // Large, readable font that fits two digits well
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  timeClient.begin();
}

void loop(void) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Save the last time you updated the display

  timeClient.update();
  unsigned long unix_epoch = timeClient.getEpochTime();
  second_ = second(unix_epoch);
  if (last_second != second_) {
    minute_ = minute(unix_epoch);
    hour_ = hour(unix_epoch);
    if (hour_ >= 0 && hour_ < 7) {
    u8g2.setContrast(1);  // Dim the display for night time
  } else {
    u8g2.setContrast(255);  // Full brightness during the day
  }
    if (hour_ == 0) {
      hour_ = 12;  // Adjust if you prefer 12-hour format without AM/PM
    } else if (hour_ > 12) {
      hour_ -= 12;  // Adjust if you prefer 12-hour format without AM/PM
    }

    Time[4] = minute_ % 10 + 48;  // Update time string
    Time[3] = minute_ / 10 + 48;
    Time[1] = hour_ % 10 + 48;
    Time[0] = hour_ / 10 + 48;

    last_second = second_;
    u8g2.clearBuffer();
    u8g2_prepare();
    u8g2.drawStr(0, 5, Time);  // Centered hour and minute
    u8g2.sendBuffer();
    }
  }
}
