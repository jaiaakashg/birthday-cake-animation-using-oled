#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();

  // Print the birthday message
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.print("Happy");
  display.setCursor(10, 30);
  display.print("Birthday");
  display.setCursor(10, 50);
  display.print("To You");
  display.display();

  delay(2000); // Wait for 2 seconds

  // Clear the display
  display.clearDisplay();
  display.display();

  // Draw the cake
  drawCake();
  display.display();
}

void loop() {
  // Nothing to do here
}

void drawCake() {
  // Base of the cake
  display.drawRect(30, 40, 70, 20, SSD1306_WHITE);
  display.fillRect(30, 40, 70, 20, SSD1306_WHITE);

  // Middle layer of the cake
  display.drawRect(40, 30, 50, 10, SSD1306_WHITE);
  display.fillRect(40, 30, 50, 10, SSD1306_WHITE);

  // Top layer of the cake
  display.drawRect(50, 20, 30, 10, SSD1306_WHITE);
  display.fillRect(50, 20, 30, 10, SSD1306_WHITE);

  // Candles
  for (int i = 0; i < 3; i++) {
    int x = 55 + (i * 10);
    display.drawLine(x, 20, x, 15, SSD1306_WHITE);
  }

  // Candle flames
  for (int i = 0; i < 3; i++) {
    int x = 55 + (i * 10);
    display.drawCircle(x, 14, 2, SSD1306_WHITE);
    display.fillCircle(x, 14, 2, SSD1306_WHITE);
  }
}

