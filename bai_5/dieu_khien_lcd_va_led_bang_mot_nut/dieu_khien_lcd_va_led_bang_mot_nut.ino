#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int btn = 1;
int led = 0;
int number_of_times = 0;
unsigned long pre_status_btn = LOW;
void setup() {
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  unsigned long cur_status_btn = digitalRead(btn);
  number_of_times = number_of_times % 2;
  if(cur_status_btn == LOW && pre_status_btn == HIGH)
  {
    number_of_times++;
  }
  if(number_of_times == 0)
  {
    digitalWrite(led,LOW);
    lcd.clear();
    lcd.display();
    lcd.setCursor(1,1);
    lcd.print("...");
  }
  else
  {
    lcd.noDisplay();
    digitalWrite(led,HIGH);
  }
  pre_status_btn = cur_status_btn;
}
