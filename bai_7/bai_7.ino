#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte aw[8] = {
  B01010,
  B00100,
  B00100,
  B01010,
  B10001,
  B11111,
  B10001,
  B10001
};

byte aa[8] = {
  B00100,
  B01010,
   B00100,
  B01010,
  B10001,
  B11111,
  B10001,
  B10001
};

byte dd[8] = {
  B11100,
  B01010,
  B01001,
  B11101,  
  B01001,
  B01001,
  B01010,
  B11100  
};

byte ee[8] = {  
  B00100,
  B01010,
  B11111,
  B10000,  
  B11111,  
  B10000,
  B11111,
  B00000
}; 


byte oo[8] = {
  B00100,
  B01010,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,  
  B00000
};

byte ow[8] = {
  B00110,
  B00001,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,  
  B00000
};


byte uw[8] = {
  B00110, 
  B00001,
  B10010,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000
};


void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, aw);   
  lcd.createChar(1, aa);     
  lcd.createChar(2, dd);  
  lcd.createChar(3, ee);    
  lcd.createChar(4, oo);     
  lcd.createChar(5, ow);    
  lcd.createChar(6, uw);    
}

void loop() {
  lcd.clear();
  delay(500);
  lcd.setCursor(0, 0);
  for(int i=0;i<7;i++){
    lcd.print(char(i));
    delay(500);
  }
}
