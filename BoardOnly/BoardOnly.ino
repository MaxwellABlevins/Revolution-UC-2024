#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 2; // Assuming button is connected to pin 2
const int maxLocations = 5; // Number of locations
const int maxOccupancy = 5; // Maximum occupancy for each location

struct Location {
  String name;
  int occupancy;
};

Location locations[maxLocations] = {
  {"Room 210A", 0},
  {"Esports Center", 0},
  {"Fourth Floor", 0},
  {"MakerSpace", 0},
  {"Conference Room", 0}
};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    assignUserToRandomLocation();
    delay(1000); // Debouncing delay
  }
}

void assignUserToRandomLocation() {
  int randomIndex = random(0, maxLocations);
  if (locations[randomIndex].occupancy < maxOccupancy) {
    locations[randomIndex].occupancy++;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Assigned to:");
    display.println(locations[randomIndex].name);
    display.display();
  } else {
    // Handle the case where location is full
    // You might want to display a message or take some other action
  }
}
