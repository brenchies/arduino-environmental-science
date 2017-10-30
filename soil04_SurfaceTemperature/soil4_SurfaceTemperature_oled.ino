
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  mlx.begin();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
}

void loop() {

  // draw temp reading
  oledTemp();
  Serial.print("Surface temp : ");
  Serial.print(mlx.readObjectTempC());
  Serial.println(" *C");
  delay(2000);
  display.clearDisplay();
  
}

void oledTemp(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.print(mlx.readObjectTempC()); display.println(" C");
  display.display();
  delay(1);
}
