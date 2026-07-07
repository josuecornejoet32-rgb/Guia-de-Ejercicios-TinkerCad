#include <Adafruit_NeoPixel.h>

#define NEOPIN 2
#define NEOPIN1 3
#define NEOPIN2 4
#define CANT_PIXEL 12

Adafruit_NeoPixel Ring(CANT_PIXEL, NEOPIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel Ring1(CANT_PIXEL, NEOPIN1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel Ring2(CANT_PIXEL, NEOPIN2, NEO_RGB + NEO_KHZ800);

bool avanzar = true;
int ledActual = 0;

int colores[12][3] = {
  {0,255,0},
  {255,0,0},
  {0,0,255},
  {0,255,255},
  {255,0,255},
  {255,255,0},
  {255,255,255},
  {255,100,100},
  {100,100,255},
  {100,255,100},
  {100,255,255},
  {255,100,255}
};

void setup()
{
  pinMode(NEOPIN, OUTPUT);
  pinMode(NEOPIN1, OUTPUT);
  pinMode(NEOPIN2, OUTPUT);
  Ring.begin();
  Ring.clear();
  Ring.show();
  Ring1.begin();
  Ring1.clear();
  Ring1.show();
  Ring2.begin();
  Ring2.clear();
  Ring2.show();
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{
  for (int i = 0; i < 12; i++)
  {
    Ring.setPixelColor(i, colores[i][0], colores[i][1], colores[i][2]);
    Ring.show();
    delay(500);

    Ring.setPixelColor(i, 0, 0, 0);
    Ring.show();
  }

  delay(1000);
  while (true)
  {
    Ring1.setPixelColor(ledActual, 0, 255, 0);
    Ring1.show();
    delay(250);

    Ring1.setPixelColor(ledActual, 0, 0, 0);
    Ring1.show();

    if (avanzar)
    {
      if (ledActual == 11)
      {
        avanzar = false;
        ledActual--;
      }
      else
      {
        ledActual++;
      }
    }
    else
    {
      if (ledActual == 0)
      {
        break;
      }
      else
      {
        ledActual--;
      }
    }
  }

  ledActual = 0;
  avanzar = true;
  delay(1000);
  for (int i = 0; i < 12; i += 2)
  {
    Ring2.setPixelColor(i, random(256), random(256), random(256));
  }
  Ring2.show();
  delay(500);

  for (int i = 0; i < 12; i += 2)
  {
    Ring2.setPixelColor(i, 0, 0, 0);
  }

  for (int i = 1; i < 12; i += 2)
  {
    Ring2.setPixelColor(i, random(256), random(256), random(256));
  }
  Ring2.show();
  delay(500);

  for (int i = 1; i < 12; i += 2)
  {
    Ring2.setPixelColor(i, 0, 0, 0);
  }
  Ring2.show();
}
