#include <LiquidCrystal.h>

// Thay đổi chân nếu bạn nối khác
const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Bitmap 5x8 cho 7 chữ: Ă, Â, Đ, Ê, Ô, Ơ, Ư
byte chuA_breve[8] = {
  B01010, // dấu breve
  B00100, // đỉnh A
  B01010,
  B10001,
  B11111,
  B10001,
  B10001,
  B00000
};

byte chuA_hat[8] = {
  B00100, // mũ ^
  B01010,
  B10001,
  B10001,
  B11111,
  B10001,
  B10001,
  B00000
};

byte chuD_stroke[8] = {
  B11110,
  B10001,
  B10001,
  B11110, // gạch ngang giữa (stroke)
  B10001,
  B10001,
  B11110,
  B00000
};

byte chuE_hat[8] = {
  B00100, // mũ ^
  B01010,
  B11111,
  B10000,
  B11110,
  B10000,
  B11111,
  B00000
};

byte chuO_hat[8] = {
  B00100, // mũ ^
  B01010,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte chuO_horn[8] = {
  B00010, // móc/horn bên phải
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte chuU_horn[8] = {
  B00010, // móc/horn bên phải (Ư)
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  // Tạo custom chars (index 0..6)
  lcd.createChar(0, chuA_breve);   // Ă
  lcd.createChar(1, chuA_hat);     // Â
  lcd.createChar(2, chuD_stroke);  // Đ
  lcd.createChar(3, chuE_hat);     // Ê
  lcd.createChar(4, chuO_hat);     // Ô
  lcd.createChar(5, chuO_horn);    // Ơ
  lcd.createChar(6, chuU_horn);    // Ư

  
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  for(int i=0i<7;i++){
     lcd.write(byte(i)); 
      lcd.print(" ");
  }
  delay(1000);
}