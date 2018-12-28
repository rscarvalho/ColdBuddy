#include "utils.cpp"
#include "utils.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <dht.h>
#include <math.h>

typedef U8G2_SH1106_128X64_NONAME_2_4W_SW_SPI Screen;

dht DHT;
Screen screen(U8G2_R0, Pins.SCR_CLOCK, Pins.SCR_MOSI, Pins.SCR_CS, Pins.SCR_DC);

#define READ_DELAY 2000

float tick = 0;

void printReading(float, const dht &, Screen &);
int ledSuccess();
int ledFailed();
void printError(int);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  //   Serial.println("Reading #\tTemperature\tHumidity");

  screen.begin();
  screen.setFlipMode(1);
}

void loop() {
  int chk = DHT.read11(Pins.TEMP_HUMID);
  int led_delay = 0;

  if (chk == DHTLIB_OK) {
    printReading(tick, DHT, screen);
    led_delay += ledSuccess();
  } else {
    printError(chk);
    led_delay += ledFailed();
  }
  tick += (READ_DELAY / 1000.0);

  delay(READ_DELAY - led_delay);
}

void printError(int result) {
  Serial.print("Read error: ");
  Serial.print(result);
  Serial.println("");
}

void printReading(float elapsed, const dht &sensor, Screen &screen) {
  screen.firstPage();
  char temp[128], humid[128];

  sprintf(temp, "Temperature: %d°C", (int)ceil(sensor.temperature));
  sprintf(humid, "Humidity: %d%%", (int)ceil(sensor.humidity));

  do {
    screen.setFont(u8g2_font_helvB08_te);
    screen.drawUTF8(0, 24, temp);
    screen.drawUTF8(0, 48, humid);
  } while (screen.nextPage());
}

int ledSuccess() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  return 50;
}

int ledFailed() {
  int led_delay = 0;
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    led_delay += 100;
  }
  return led_delay;
}
