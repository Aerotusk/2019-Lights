/* Idle functions, such as rainbow and idle
*  TODO: make the idle(a, wait) into idle(r,g,b,wait)
*/

void idle(int r, int g, int b, int wait)
{
  int re;
  int gr;
  int bl;
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



void rainbow(int wait)
{

  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    if (checkForSerial())
    {
      goto leaveOne;
    }
    strip.show();
    delay(wait);
  }
leaveOne:
  delay(0);
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



void staticColor(int r, int g, int b)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(r, g, b)); // max white 150
  }
  strip.show();
}
