/*  Any light codes that flash the lights around a certain specification. 
 *  Obviously, this includes fire and blueFire, but lights such as pink and
 *  barf technically fit this, too.
 * 
 * 
 * TODO: Consolidate static fire functions into one function,
 * and make it something like fire(red), fire(blue), fire(pink), etc.
 */
void fire()
{
  int w = 0;
  for (w; w < strip.numPixels(); w++)
  {
    int r = random(50, 150);
    strip.setPixelColor(w, strip.Color(r, random(30), 0));
  }
  strip.show();
  delay(50);
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
  delay(50);
}



void pink()
{
  int w = 0;
  for (w; w < strip.numPixels(); w++)
  {
    int b = random(10, 70);
    int g = random(10, 35);
    int r = random(150, 200);
    strip.setPixelColor(w, strip.Color(r, g, b));
  }
  strip.show();
  delay(50);
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



int barf(int brightness)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(random(brightness), random(brightness), random(brightness)));
  }
  strip.show();
}



void blueFireRedFire()
{
  while (0 == 0)
  {
    for (int i = 0; i <= 255; (i = i + 5))
    {
      for (int w = 0; w < strip.numPixels(); w++)
      {

        int b = mapf(random(30, 125), 0, 255, 0, 255 - i);
        int g = mapf(random(10, 150), 0, 255, 0, 285 - i);
        int r = mapf(random(50, 150), 0, 255, 0, i);
        strip.setPixelColor(w, strip.Color(r, g, b));
      }
      if (checkForSerial())
      {
        goto leave;
      }
      strip.show();
      delay(15);

    }
    for (int p = 0; p <= 100; p++)
    {
      for (int w = 0; w < strip.numPixels(); w++)
      {

        int r = random(50, 150);
        strip.setPixelColor(w, strip.Color(r, random(30), 0));
      }
      if (checkForSerial())
      {
        goto leave;
      }
      strip.show();
      delay(30);
    }
    for (int l = 255; l >= 0; l = l - 5)
    {
      for (int w = 0; w < strip.numPixels(); w++)
      {
        int b = mapf(random(30, 125), 0, 255, 0, 255 - l);
        int g = mapf(random(10, 150), 0, 255, 0, 285 - l);
        int r = mapf(random(50, 150), 0, 255, 0, l);
        strip.setPixelColor(w, strip.Color(r, g, b));
      }
      if (checkForSerial())
      {
        goto leave;
      }
      strip.show();
      delay(15);
    }
    for (int k = 0; k <= 100; k++)
    {
      for (int w = 0; w < strip.numPixels(); w++)
      {

        int b = random(50, 125);
        int g = random(10, 150);
        strip.setPixelColor(w, strip.Color(0, g, b));
      }
      if (checkForSerial())
      {
        goto leave;
      }
      strip.show();
      delay(30);
    }
  }
leave:
  delay(0);
}
