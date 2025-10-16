#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


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

byte ef[8] = {  
  B01000,
  B00100,
  B11111,
  B10000,  
  B11111,  
  B10000,
  B11111,
  B00000
};

byte es[8] = {  
  B00010,
  B00100,
  B11111,
  B10000,  
  B11111,  
  B10000,
  B11111,
  B00000
};

byte of[8] = {
  B01000,
  B00100,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,  
  B00000
};

byte os[8] = {
  B00010,
  B00100,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,  
  B00000
};


int btn_e=6;
int btn_o=7;
int btn_f=8;
int btn_s=9;


int pre_btn_e=LOW;
int pre_btn_o=LOW;
int pre_btn_f=LOW;
int pre_btn_s=LOW;

int pre_key=0;
int cur_key=0;

int x=0, y=0;


int lastType=0; 

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0, ee);
  lcd.createChar(1, oo);
  lcd.createChar(2, ef);
  lcd.createChar(3, es);
  lcd.createChar(4, of);
  lcd.createChar(5, os);

  pinMode(btn_e,INPUT);
  pinMode(btn_o,INPUT);
  pinMode(btn_f,INPUT);
  pinMode(btn_s,INPUT);
  lcd.clear();
}

void loop() {
  int e = digitalRead(btn_e);
  int o = digitalRead(btn_o);
  int f = digitalRead(btn_f);
  int s = digitalRead(btn_s);

  if(e==HIGH && pre_btn_e==LOW){
     cur_key=1; 
     xuLyPhim();
  }
  pre_btn_e=e;

  if(o==HIGH && pre_btn_o==LOW){ 
    cur_key=2; 
    xuLyPhim();
  }
  pre_btn_o=o;

  if(f==HIGH && pre_btn_f==LOW){ 
    cur_key=3; 
    xuLyPhim();
  }
  pre_btn_f=f;

  if(s==HIGH && pre_btn_s==LOW){ 
    cur_key=4; 
    xuLyPhim();
  }
  pre_btn_s=s;
}

void xuLyPhim(){

  bool canCombine = (lastType == 1 || lastType == 2);

  if(pre_key==1 && cur_key==1 && canCombine){ 
    ghiDe(byte(0)); lastType=3;
  }
  else if(pre_key==1 && cur_key==3 && canCombine){ 
    ghiDe(byte(2)); lastType=5;
  }
  else if(pre_key==1 && cur_key==4 && canCombine){ 
    ghiDe(byte(3)); lastType=6;
  }
  else if(pre_key==2 && cur_key==2 && canCombine){ 
    ghiDe(byte(1)); lastType=4;
  }
  else if(pre_key==2 && cur_key==3 && canCombine){
    ghiDe(byte(4)); lastType=7;
  }
  else if(pre_key==2 && cur_key==4 && canCombine){ 
    ghiDe(byte(5)); lastType=8;
  }
  else {
    lcd.setCursor(x, y);
    switch(cur_key){
      case 1: lcd.print("E"); lastType=1; break;
      case 2: lcd.print("O"); lastType=2; break;
      case 3: lcd.print("F"); lastType=0; break;
      case 4: lcd.print("S"); lastType=0; break;
    }
    x++;
    if(x>=16){x=0; y=(y+1)%2;}
  }

  pre_key=cur_key;
}

void ghiDe(byte c){
  if(x>0) x--;
  lcd.setCursor(x, y);
  lcd.write(c);
  x++;
  if(x>=16){x=0; y=(y+1)%2;}
}
