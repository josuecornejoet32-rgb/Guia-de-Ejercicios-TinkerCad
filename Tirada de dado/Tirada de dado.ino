#include <Adafruit_NeoPixel.h>

#define buzzer 3
#define boton1 5
#define NEOPIN1 2
#define NEOPIN2 4
#define CANT_PIXEL1 24

#define length(a,b) sizeof(a)/sizeof(b)

Adafruit_NeoPixel Flex1 = Adafruit_NeoPixel(CANT_PIXEL1, NEOPIN1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel Flex2 = Adafruit_NeoPixel(CANT_PIXEL1, NEOPIN2, NEO_RGB + NEO_KHZ800);

bool estadoBoton = false;
bool ultimo = false;

int uno[] = {9, 13, 18, 19, 20, 21, 22, 23};

int dos[] = {
  0, 11, 12, 23, 22, 21, 14, 9,
  2, 3, 4, 5, 6, 17, 18
};

int tres[] = {
  0, 11, 12, 23, 22, 21, 14, 9,
  2, 20, 19, 18, 5, 6, 17
};

int cuatro[] = {
  0, 1, 2, 9, 14, 21, 22, 23,
  20, 19, 18
};

int cinco[] = {
  0, 11, 12, 23,
  1, 2, 9, 14,
  21, 20, 19, 18, 17, 6, 5
};

int seis[] = {
  0, 11, 12, 23,
  1, 2, 3, 4, 9, 14,
  21, 20, 19, 18, 17, 6, 5
};

int todos[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
  12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
  22, 23
};

int cantidades[] = {
  length(uno, int),
  length(dos, int),
  length(tres, int),
  length(cuatro, int),
  length(cinco, int),
  length(seis, int)
};

int* numeros[] = {
  uno, dos, tres, cuatro, cinco, seis
};

void setup()
{
  pinMode(boton1, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(NEOPIN1, OUTPUT);
  pinMode(NEOPIN2, OUTPUT);

  Flex1.begin();
  Flex1.clear();
  Flex1.show();

  Flex2.begin();
  Flex2.clear();
  Flex2.show();

  Serial.begin(9600);

  randomSeed(analogRead(A0));
}

void loop()
{
  bool boton = digitalRead(boton1);

  if (boton == HIGH && ultimo == LOW)
  {
    estadoBoton = true;
    delay(50);
  }

  ultimo = boton;

  if (estadoBoton)
  {
    int dado1 = random(1, 7);
    int dado2 = random(1, 7);

    for (int i = 0; i < 8; i++)
    {
      int random1 = random(1, 7);
      int random2 = random(1, 7);

      Flex1.clear();
      Flex2.clear();

      for (int j = 0; j < cantidades[random1 - 1]; j++)
      {
        Flex1.setPixelColor(
          numeros[random1 - 1][j],
          0, 255, 255
        );
      }

      for (int j = 0; j < cantidades[random2 - 1]; j++)
      {
        Flex2.setPixelColor(
          numeros[random2 - 1][j],
          0, 255, 255
        );
      }

      Flex1.show();
      Flex2.show();

      delay(120 - (i * 10));
    }

    Flex1.clear();
    Flex2.clear();

    for (int i = 0; i < cantidades[dado1 - 1]; i++)
    {
      Flex1.setPixelColor(
        numeros[dado1 - 1][i],
        0, 255, 255
      );
    }

    for (int i = 0; i < cantidades[dado2 - 1]; i++)
    {
      Flex2.setPixelColor(
        numeros[dado2 - 1][i],
        0, 255, 255
      );
    }

    Flex1.show();
    Flex2.show();

    Serial.print("Dado 1: ");
    Serial.println(dado1);

    Serial.print("Dado 2: ");
    Serial.println(dado2);

    Serial.print("Suma: ");
    Serial.println(dado1 + dado2);

    if (dado1 + dado2 == 7)
    {
      Serial.println("GANASTE");

      for (int j = 0; j < 6; j++)
      {
        for (int i = 0; i < 24; i++)
        {
          Flex1.setPixelColor(i, 0, 255, 255);
          Flex2.setPixelColor(i, 0, 255, 255);
        }

        Flex1.show();
        Flex2.show();

        tone(buzzer, 1000);

        delay(200);

        Flex1.clear();
        Flex2.clear();

        Flex1.show();
        Flex2.show();

        noTone(buzzer);

        delay(200);
      }
    }
    else
    {
      Serial.println("NO GANASTE");
    }

    estadoBoton = false;

    while (digitalRead(boton1) == HIGH)
    {
    }

    delay(50);
  }
}