/*
    Functions that are referenced by other functions
*/



float  mapf(long x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



boolean checkForSerial()
{
  if (Serial.available())
  {
    blyat = Serial.read();
    return true;
  }
  else
  {
    return false;
  }
}


void computerLights()
{
  if (Serial.available())
  {
    blyat = Serial.read();
  }
  if (blyat == 0)
  {
    fire();
  }
  else if (blyat == 1)
  {
    blueFire();
  }
  else if (blyat == 2)
  {
    pink();
  }
  else if (blyat == 3)
  {
    blueFireRedFire();
  }
  else if (blyat == 4)
  {
    rainbow(10);
  }
  else if (blyat == 5)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
  }
}
