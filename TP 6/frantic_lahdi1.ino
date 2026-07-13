#define luz 6
#define motor 5
#define sensor 4
int lectTemp = A1;

void setup()
{
  pinMode(luz, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int PIR = digitalRead(sensor);
  // temp sensor
  int temp = analogRead(lectTemp);
  float volt = temp * 5.0 / 1023.0;
  int tempf = (volt - 0.5) * 100;
  
  Serial.println(tempf);
  
  // motor
  if (tempf > 50)
  {
    digitalWrite(motor, 255);
  }
  else
  {
    if (PIR == 1 && tempf == 30)
    {
      digitalWrite(luz, 255);
      digitalWrite(motor, 150);
    }
    else
    {
      if (PIR == 1 && tempf <= 15)
      {
        digitalWrite(luz, 255);
        digitalWrite(motor, 50);
      }
      else
      {
        if (PIR == 1)
        {
          digitalWrite(luz, 255);
          digitalWrite(motor, 0);
        }
        else
        {
          digitalWrite(luz, 0);
        }
         digitalWrite(motor, 0);
      }
    }
  }
}