int led = 1;
int btn_up = 2;
int btn_down = 3;
int time = 500;
unsigned long long pre_time = 0;
int pre_btn_up = LOW;
int pre_btn_down = LOW;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(btn_up,INPUT);
  pinMode(btn_down,INPUT);
}

void loop() {
  unsigned long long cur_time = millis();
  int cur_btn_up = digitalRead(btn_up);
  int cur_btn_down = digitalRead(btn_down);
  if(cur_btn_up == LOW && pre_btn_up == HIGH)
  {
    if(time > 1000)
      time = 1000;
    time+=100;
  }
  if(cur_btn_down == LOW && pre_btn_down == HIGH)
  {
    if(time < 100)
      time = 100;
    time-=100;
  }
  if(cur_time - pre_time <= time)
  {
    digitalWrite(led,HIGH);
  }
  else if(cur_time - pre_time <= time*2)
  {
    digitalWrite(led,LOW);
  }
  else
  {
    pre_time = cur_time;
  }
  pre_btn_up = cur_btn_up;
  pre_btn_down = cur_btn_down;
}
