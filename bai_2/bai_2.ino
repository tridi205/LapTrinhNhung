int list_led_red[2] = {0,3};
int list_led_yellow[2] = {1,4};
int list_led_green[2] = {2,5};
unsigned long long pre_time = 0;
void setup() {
  for(int i = 0; i<2; i++)
  {
    pinMode(list_led_red[i],OUTPUT);
    pinMode(list_led_yellow[i],OUTPUT);
    pinMode(list_led_green[i],OUTPUT);
  }
}

void loop() {
  unsigned long long cur_time = millis();
  if(cur_time - pre_time <= 1000)
  {
    turnOffAllLed();
    digitalWrite(list_led_red[0],HIGH);
    digitalWrite(list_led_green[1],HIGH);
  }
  else if(cur_time - pre_time <= 1100)
  {
    turnOffAllLed();
    digitalWrite(list_led_yellow[0],HIGH);
    digitalWrite(list_led_yellow[1],HIGH);
  }
  else if(cur_time - pre_time <= 2100)
  {
    turnOffAllLed();
    digitalWrite(list_led_red[1],HIGH);
    digitalWrite(list_led_green[0],HIGH);
  }
  else
  {
    pre_time = cur_time;
  }
}
void turnOffAllLed(){
    for(int i = 0; i<2; i++)
  {
    digitalWrite(list_led_red[i],LOW);
    digitalWrite(list_led_yellow[i],LOW);
    digitalWrite(list_led_green[i],LOW);
  }
}
