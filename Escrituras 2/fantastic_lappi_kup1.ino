bool z = true;

bool x = LOW;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(13, OUTPUT);

  pinMode(3, INPUT);

  Serial.begin(9600);
}

void loop()
{
  bool q = digitalRead(3);

  if (q == HIGH && x == LOW)
  {
    z = !z;

    delay(200);
  }

  x = q;

  int v = analogRead(A3);

  int m = map(v, 0, 1023, 0, 3000);

  int r = (analogRead(A0) * 255.0) / 1023.0;

  int g = (analogRead(A1) * 255.0) / 1023.0;

  int b = (analogRead(A2) * 255.0) / 1023.0;

  Serial.print("Tiempo: ");
  Serial.println(m / 1000.0);

  Serial.print("R:");
  Serial.println(r);

  Serial.print("G:");
  Serial.println(g);

  Serial.print("B:");
  Serial.println(b);

  Serial.println("----------------");

  if (z == true)
  {
    analogWrite(5, r);

    analogWrite(6, b);

    analogWrite(9, g);

    digitalWrite(13, HIGH);

    delay(100);

    digitalWrite(13, LOW);

    delay(m);

    analogWrite(5, 0);

    analogWrite(6, 0);

    analogWrite(9, 0);

    delay(100);

    analogWrite(5, r);

    analogWrite(6, b);

    analogWrite(9, g);

    delay(100);

    analogWrite(5, 0);

    analogWrite(6, 0);

    analogWrite(9, 0);

    delay(100);

    analogWrite(5, r);

    analogWrite(6, b);

    analogWrite(9, g);

    delay(100);
  }

  else
  {
    analogWrite(5, 0);

    analogWrite(6, 0);

    analogWrite(9, 0);
  }
}