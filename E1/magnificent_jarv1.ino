void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{

  analogWrite(2, 255);

  delay(500);

  analogWrite(2, 0);

  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);

  delay(500);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);

  analogWrite(3, 255);
  analogWrite(4, 255);

  delay(500);

  analogWrite(3, 0);
  analogWrite(4, 0);

  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
}