#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
unsigned long long pre_time = 0;
int btn = 8;
int led_green = 9;
int led_yellow = 10;
int led_red = 11;
int lm_35 = A0;
int pre_btn = LOW;
int choose = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(lm_35,INPUT);
  pinMode(btn,INPUT);
  pinMode(led_green,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_red,OUTPUT);
}

void loop() {
  unsigned long long cur_time = millis();
  if(cur_time == 0)
  {
    pre_time = 0;
  }
  float reading = analogRead(lm_35);
  float voltage = reading * 5.0 / 1024.0;
  float temp_c = voltage * 100;
  float temp_f = (temp_c * 1.8) + 32;
  int cur_btn = digitalRead(btn);
  lcd.setCursor(0,0);
  choose = choose % 2;
  if(cur_btn == HIGH && pre_btn == LOW)
  {
    choose++;
  }
  if(cur_time - pre_time >= 500)
  {
    if(choose == 0)
    {
      lcd.clear();
      lcd.print("Temp: ");
      lcd.print(temp_c);
      lcd.print(" C");
    }
    else
    {
      lcd.clear();
      lcd.print("Temp: ");
      lcd.print(temp_f);
      lcd.print(" F");
    }
    pre_time = cur_time;
  }
  if(temp_c < 17)
  {
    turnOff();
    digitalWrite(led_green,HIGH);
  }
  else if(temp_c >= 17 && temp_c <= 30)
  {
    turnOff();
    digitalWrite(led_yellow,HIGH);
  }
  else
  {
    turnOff();
    digitalWrite(led_red,HIGH);

  }
  pre_btn = cur_btn;
}
void turnOff()
{
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow,LOW);
  digitalWrite(led_red,LOW);
}