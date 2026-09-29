int leds[] = {8, 9, 10};
int boton = 2;
int sensor = A0;

int valorSensor = 0;
int estadoBoton = 0;

void encenderLeds()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
}

void apagarLeds()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < 3; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(boton, INPUT);
}

void loop()
{
  valorSensor = analogRead(sensor);
  estadoBoton = digitalRead(boton);

  Serial.print("Valor del sensor: ");
  Serial.println(valorSensor);

  if (estadoBoton == HIGH)
  {
    encenderLeds();
  }
  else
  {
    apagarLeds();
  }

  if (valorSensor < 300)
  {
    Serial.println("Hay poca luz");
  }
  else
  {
    Serial.println("Hay bastante luz");
  }

  delay(500);
}
