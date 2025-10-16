int led_red = 5;
int led_yellow = 3;
int btn = 6;
int number_of_times = 0;
int pre_status_btn = LOW;
void setup() {
  pinMode(led_red,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  int cur_status_btn = digitalRead(btn);
  number_of_times = number_of_times % 5;
  if(cur_status_btn == LOW && pre_status_btn == HIGH)
  {
    number_of_times++;
  }
  switch (number_of_times)
  {
    case 1:
    {
      digitalWrite(led_red,HIGH);
      digitalWrite(led_yellow,HIGH);
      break;
    }
    case 2:
    {
      digitalWrite(led_red,LOW);
      digitalWrite(led_yellow,LOW);
      break;
    }
    case 3:
    {
      digitalWrite(led_red,LOW);
      digitalWrite(led_yellow,HIGH);
      break;
    }
    case 4:
    {
      digitalWrite(led_red,HIGH);
      digitalWrite(led_yellow,LOW);
      break;
    }
    default :
    {
      digitalWrite(led_red,LOW);
      digitalWrite(led_yellow,LOW);
    }
  }
  pre_status_btn = cur_status_btn;
}