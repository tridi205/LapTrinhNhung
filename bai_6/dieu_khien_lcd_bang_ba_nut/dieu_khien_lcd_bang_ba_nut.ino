#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int btn_on_off = 9;
int btn_to_the_left = 8;
int btn_to_the_right = 10;
int pre_status_btn_on_off = LOW;
int pre_status_btn_to_the_left = LOW;
int pre_status_btn_to_the_right = LOW;
unsigned long pre_time = 0;
int number_of_times = 0;
int x = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(btn_on_off,INPUT);
  pinMode(btn_to_the_left,INPUT);
  pinMode(btn_to_the_right,INPUT);
}

void loop() {
  int cur_status_btn_on_off = digitalRead(btn_on_off);
  int cur_status_btn_to_the_left = digitalRead(btn_to_the_left);
  int cur_status_btn_to_the_right = digitalRead(btn_to_the_right);
  unsigned long cur_time = millis();
  number_of_times = number_of_times % 2;
  if(cur_status_btn_on_off == LOW && pre_status_btn_on_off == HIGH)
  {
    number_of_times++;
    delay(100);
  }
  if(number_of_times == 0)
  {
      lcd.display();
      lcd.setCursor(x,0);
      lcd.print("HELLO");
    if(cur_time - pre_time >= 1000)
    {
      lcd.clear();
    }
    else
    {
      pre_time = cur_time;
    }
  }
  else
  {
    lcd.noDisplay();
  }
  if(cur_status_btn_to_the_right == LOW && pre_status_btn_to_the_right == HIGH)
  {
    x+=2;
    if(x>11)
      x=10;
    printLcd();
  }
  if(cur_status_btn_to_the_left == LOW && pre_status_btn_to_the_left == HIGH)
  {
    x-=2;
    if(x<0)
      x=0;
    printLcd();
  }
  pre_status_btn_on_off = cur_status_btn_on_off;
  pre_status_btn_to_the_left = cur_status_btn_to_the_left;
  pre_status_btn_to_the_right = cur_status_btn_to_the_right;
}
void printLcd(){
      lcd.clear();
      lcd.display();
      lcd.setCursor(x,0);
      lcd.print("HELLO");
}