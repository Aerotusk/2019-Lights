#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(72, 6, NEO_GRB + NEO_KHZ800);
//My strip has 72 pixels, and is connected to pin 6
int blyat = 0;
int leave = 0;
void setup()
{
  Serial.begin(9600);
  strip.begin();
  strip.show();
}
