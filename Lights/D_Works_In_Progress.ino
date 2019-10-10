/*
 * Works in progress. 
 * TODO: fadeFire doesn't work at all, and it's been a year since I 
 * messed around with it. Maybe I'll get back to it at some point,
 * because I think it is a really cool idea. 
 */
int LEDirection[288];
int redLight[288];
int greenLight[288];



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
