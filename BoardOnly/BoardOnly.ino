#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int buttonPin = 6; // Assuming button is connected to pin 2
const int maxLocations = 4; // Number of locations
const int maxOccupancy = 4; // Maximum occupancy for each location

struct Location {
  String name;
  int occupancy;
};

Location locations[maxLocations] = {
  {"Room 210A", 0},
  {"MakerSpace", 0},
  {"Esports Center", 0},
  {"Fourth Floor", 0},
};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  display.setRotation(2);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  if (digitalRead(buttonPin) == HIGH ){
    assignUserToRandomLocation();
    delay(500); // Debouncing delay
  }
}

void assignUserToRandomLocation() {
  
  // Filter out full locations
  int availableLocations[maxLocations];
  int numAvailableLocations = 0;
  
  for (int i = 0; i < maxLocations; i++) {
    if (locations[i].occupancy < maxOccupancy) {
      availableLocations[numAvailableLocations++] = i;
    }
  }
  

  if (numAvailableLocations > 0) {
    int randomIndex = random(0, numAvailableLocations);
    int selectedLocationIndex = availableLocations[randomIndex];
    
    // Assign user to the selected location
    locations[selectedLocationIndex].occupancy++;
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Assigned to:");
    display.println(locations[selectedLocationIndex].name);
    display.print("Occupancy: ");
    display.println(locations[selectedLocationIndex].occupancy);
    display.display();
  }
  else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("All rooms full.");
    display.display();
   }
}


