// Images
#include "introPic.h"
#include "sunrisePic.h"
#include "sunsetPic.h"

// Screen Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c  //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay() {
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setRotation(0);
}

void showIntro() {
  display.drawBitmap(0, 0, introPic, 128, 64, SH110X_WHITE);
  display.display();
  delay(3000);
}

void showSunrise() {
  // Increment PokemonId

  // Update apiUrl with the new PokemonId

  display.setCursor(1, 1);
  display.setTextWrap(true);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.print("PokemonId:" + String(PokemonId));
  display.setCursor(1, 10);
  display.print("Name:" + (pokemonName));
  display.setCursor(1, 30);
  display.print("Type:" + (pokemonType1));
  display.setCursor(80, 30);
  display.print(pokemonType2);
  display.setCursor(1, 40);
  display.print("Game:" + (pokemonGame));
  display.setTextSize(2);
  display.setCursor(1, 50);
  display.print("Pokedex");
  display.display();
}


void showSleep() {
  display.drawBitmap(0, 0, sleepingPikachu, 128, 64, SH110X_WHITE, SH110X_BLACK);
  display.display();
}

void clearDisplay() {
  display.clearDisplay();
}