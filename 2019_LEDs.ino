#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(288, PIN, NEO_GRB + NEO_KHZ800);
int LEDirection[288];
int redLight[288];
int greenLight[288];
int state = 1;
int setting = 10;
void setup()
{
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop()
{

  blueFireRedFire();

}
void blyat()
{

  for (int i = 0; i <= setting; i++)
  {
    Serial.println(i);
    switch (state)
    {
      case 0:
        idle(1, 10);
        setting = 50;
      case 1:
        oneRedOneBlue();
        setting = 50;
        break;
      case 2:
        staticColor();
        setting = 00;
        break;
      case 3:
        rainbow(5);
        setting = 3;
        break;
      case 4:
        //          blueFireRedFire();
        setting = 0;
        break;
      case 5:
        pink();
        setting = 50;
        break;
      case 6:
        //fadeFire();//no work
        idle(3, 10);
        setting = 3;
        break;
      case 7:
        //          bluePhaseRed();

        break;
      case 8:
        blueFire();
        setting = 50;
      case 9:
        break;
        fire();
        setting = 50;
        break;
      case 10:
        idle(2, 10);
        setting = 3;//1 = Red, 2 = Cyan, 3 = Green
        break;
      case 11:
        barf(255);
        setting = 50;
        break;
    }
  }
}


void colorChoose()
{

}
void staticColor()
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0, 20, 50)); // max white 150
  }
  strip.show();
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}


uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void pink()
{
  int w = 0;
  for (w; w < strip.numPixels(); w++)
  {
    int b = random(10, 50);
    int g = random(10, 20);
    strip.setPixelColor(w, strip.Color(200, g, b));
  }
  strip.show();
  delay(50);
}


void fadeFire()
{
  int w = 0;
  for (w; w < 8; w++)
  {

    int r = redLight[w];
    int g = greenLight[w];
    if (r == 256)
    {
      r = 255;
    }
    else
    {
    }
    strip.setPixelColor(w, strip.Color((int)r, (int)g, 0));
    if (random(0, 1) == 0)
    {
      if ((LEDirection[w] == 0) && (redLight[w] > 30))
      {
        redLight[w] = (redLight[w] - 1);
      }
      else if ((LEDirection[w] == 1) && (redLight[w] < 100))
      {
        redLight[w] = (redLight[w] + 1);
      }
      else if ((LEDirection[w] == 0) && (redLight[w] <= 30))
      {
        LEDirection[w] = 1;
      }
      else if ((LEDirection[w] == 1) && (redLight[w] >= 100))
      {
        LEDirection[w] = 0;
      }
    }
    else
    {

    }
  }
  strip.show();
  delay(10);
}

void oneRedOneBlue()
{
  int w = 0;
  for (w; w < 144; w++)
  {
    int r = random(100, 255);
    strip.setPixelColor(w, strip.Color(r, random(30), 0));
    int b = random(50, 125);
    int g = random(10, 150);
    strip.setPixelColor(w + 144, strip.Color(0, g, b));
  }
  strip.show();
}

void fire()
{
  int w = 0;
  for (w; w < strip.numPixels(); w++)
  {
    int r = random(100, 255);
    strip.setPixelColor(w, strip.Color(r, random(30), 0));
  }
  strip.show();
  delay(0);
}

void blueFireRedFire()
{

  for (int i = 0; i <= 255; (i = i + 5))
  {
    for (int w = 0; w < strip.numPixels(); w++)
    {

      int b = mapf(random(30, 125), 0, 255, 0, 255 - i);
      int g = mapf(random(10, 150), 0, 255, 0, 285 - i);
      int r = mapf(random(100, 255), 0, 255, 0, i);
      strip.setPixelColor(w, strip.Color(r, g, b));
    }
    strip.show();
  }
  for (int p = 0; p <= 100; p++)
  {
    for (int w = 0; w < strip.numPixels(); w++)
    {

      int r = random(100, 255);
      strip.setPixelColor(w, strip.Color(r, random(30), 0));
    }
    strip.show();
  }
  for (int l = 255; l >= 0; l = l - 5)
  {
    for (int w = 0; w < strip.numPixels(); w++)
    {
      int b = mapf(random(30, 125), 0, 255, 0, 255 - l);
      int g = mapf(random(10, 150), 0, 255, 0, 285 - l);
      int r = mapf(random(100, 255), 0, 255, 0, l);
      strip.setPixelColor(w, strip.Color(r, g, b));
    }
    strip.show();
  }
  for (int k = 0; k <= 100; k++)
  {
    for (int w = 0; w < strip.numPixels(); w++)
    {

      int b = random(50, 125);
      int g = random(10, 150);
      strip.setPixelColor(w, strip.Color(0, g, b));
    }
    strip.show();
  }

}

float  mapf(long x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void bluePhaseRed()
{
  for (int i = 0; i < strip.numPixels(); i++)
  {


    int w = 0;
    for (w; w < strip.numPixels(); w++)
    {
      int b = random(50, 125);
      int g = random(10, 150);
      if ((w >= (i - 5)) && (w <= (i + 5)))
      {
        strip.setPixelColor(w, strip.Color(255, g, b));
      }
      else
      {
        strip.setPixelColor(w, strip.Color(0, g, b));
      }
    }
    strip.show();
    delay(0);
  }
}

void blueFire()
{
  int w = 0;
  for (w; w < strip.numPixels(); w++)
  {
    int b = random(50, 125);
    int g = random(10, 150);
    strip.setPixelColor(w, strip.Color(0, g, b));
  }
  strip.show();
  delay(0);
}
void idle(int a, int wait)
{
  int r;
  int g;
  int b;
  int re;
  int gr;
  int bl;
  switch (a)
  {
    case 1:
      r = 255;
      g = 0;
      b = 0;
      break;
    case 2:
      r = 0;
      g = 200;
      b = 150;
      break;
    case 3:
      r = 0;
      g = 125;
      b = 0 ;
      break;
    case 4:
      r = 255;
      g = 50;
      b = 127;
    case 5:
      r = 0;
      g = 20;
      b = 25;
      break;
  }
  for (int q = 255; q > 0; q = (q - 1)) // fade out
  {
    re = q;
    gr = q;
    bl = q;
    re = map(re, 0, 255, 0, r);
    gr = map(gr, 0, 255, 0, g);
    bl = map(bl, 0, 255, 0, b);
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(re, gr, bl));

    }

    strip.show();
    Serial.println(re);
    delay(wait / 1000);
  }
  delay(500);
  for (int q = 0; q < 255; q++) // fade in
  {
    Serial.println("yeet");
    re = q;
    gr = q;
    bl = q;
    re = map(re, 0, 255, 0, r);
    gr = map(gr, 0, 255, 0, g);
    bl = map(bl, 0, 255, 0, b);
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(re, gr, bl));
    }
    strip.show();
    Serial.println(re);
    delay(wait / 1000);
  }
  delay(1000);
}


int barf(int brightness)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(random(brightness), random(brightness), random(brightness)));
  }
  strip.show();
}
