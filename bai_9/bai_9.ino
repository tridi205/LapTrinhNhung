#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 6, 5 , 4, 3);
int sensorPin = A0;
int btn_c=1;
int btn_f=2;
int pre_btn_c=LOW;
int pre_btn_f=LOW;
bool status=true;
unsigned long long pre_time=0;

void setup() {
  lcd.begin(16, 2);
  pinMode(btn_c, INPUT);
  pinMode(btn_f, INPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0/1024.0;
  float temp = voltage * 100.0; 
  float tempF = (temp*1.8)+32; 
  lcd.print(temp);
  lcd.println(" C");
}

void loop() {
  unsigned long long cur_time=millis();
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0/1024.0;
  float temp = voltage * 100.0; 
  float tempF = (temp*1.8)+32; 

  int status_btn_c=digitalRead(btn_c);
  int status_btn_f=digitalRead(btn_f);

  if(status_btn_c==HIGH&&pre_btn_c==LOW){
    status=true;
  }
  pre_btn_c=status_btn_c;

  if(status_btn_f==HIGH&&pre_btn_f==LOW){
    status=false;
  }
  pre_btn_f=pre_btn_f;

  if(cur_time-pre_time>=300){
    lcd.clear();
    lcd.setCursor(0,0);
    if(status){
      lcd.print(temp);
      lcd.println(" C");
    }else{
      lcd.print(tempF);
      lcd.println(" F");
    }
    pre_time=cur_time;
  }
}
