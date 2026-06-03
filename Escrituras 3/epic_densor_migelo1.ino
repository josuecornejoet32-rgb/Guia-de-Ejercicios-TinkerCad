#include <LiquidCrystal.h>

LiquidCrystal lcd(4,5,10,11,12,13);

int luz;
float Temp;
int mov;

int dur;
float dist;
float TMP;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(6, INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  luz = analogRead(A2);

  luz = map(luz, 713, 1022, 100, 0);
  
  TMP = analogRead(A0);
  
  TMP = map(TMP, 20, 358, -40, 125);

  mov = digitalRead(6);


  digitalWrite(8, HIGH);
  delayMicroseconds(10);

  digitalWrite(8, LOW);

  dur = pulseIn(7, HIGH);

  dist = dur * 0.034 / 2;

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("L:");
  lcd.print(luz);

  lcd.print(" T:");
  lcd.print(TMP);

  lcd.setCursor(0, 1);

  lcd.print("D:");
  lcd.print(dist);

  Serial.print("Luz: ");
  Serial.print(luz);

  Serial.print(" Temp: ");
  Serial.print(TMP);

  Serial.print(" Mov: ");
  Serial.print(mov);

  Serial.print(" Dist: ");
  Serial.println(dist);



  noTone(9);

  if (luz < 20)
  {
    if (mov == HIGH)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      tone(9, 1000);

    }
        else
    {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      noTone(9);

    }

    if (TMP > 39)
    {
      digitalWrite(2, HIGH);

      tone(9, 2000);
      delay(500);

      noTone(9);
    }
 else
    {
  digitalWrite(2,LOW);
    }
  }
  if (luz < 20)
  {
    if (dist < 100)
    {
    digitalWrite(2, HIGH);
    tone(9, 1500);
    }
    else
    {
      digitalWrite(2,LOW);
      noTone(9);
    }
  }

  delay(500);
}