int OutPut = 13;
unsigned int frequency = 0;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int blue1;
int red1;
int green1;

int a = 0, b = 0;
int total = 1000;
void setup()
{
  lcd.init();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  Smart Wallet  ");
  lcd.setCursor(0, 1);
  lcd.print(" Circuit Digest  ");
  delay(2000);

  lcd.clear();

  pinMode(2, OUTPUT);//S0
  pinMode(3, OUTPUT);//S1
  pinMode(11, OUTPUT);//S2
  pinMode(12, OUTPUT);//S3
  pinMode(13, INPUT);//OUT

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void loop()
{
  int sensor = digitalRead(A0);
  int red1 = red();
  int blue1 = blue();
  int green1 = green();
  
   Serial.print("red1 = ");
  Serial.println(red1);
  Serial.print("blue1 = ");
  Serial.println(blue1);
 
  
//  Serial.print("green1 = ");
//  Serial.println(green1);
//  Serial.println("-----------------------------");

  if ( blue1 >= 70 && blue1 <= 100 &&  a == 0 && sensor == HIGH)
  {
    a = 1;
  }
  else if (sensor == LOW && a == 1)
  {
    a = 0;
    if (total >= 10)
    {
      lcd.setCursor(0, 1);
      lcd.print("100 TAKA!!!");
      total = total - 100;
      delay(1500);
      lcd.clear();
    }
  }
  if ( red1 >= 30 && red1 <= 50  && b == 0 && sensor == HIGH)
  {
    b = 1;
  }
  else if (sensor == LOW && b == 1)
  {
    b = 0;
    if (total >= 10)
    {
      lcd.setCursor(0, 1);
      lcd.print("10 TAKA!!!");
      total = total - 10;
      delay(1500);
      lcd.clear();
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Total Bal:");
  lcd.setCursor(11, 0);
  lcd.print(total);
  delay(1000);
}

int red()
{
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}
int blue()
{
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}
int green()
{
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  frequency = pulseIn(OutPut, LOW);
  return frequency;
}
