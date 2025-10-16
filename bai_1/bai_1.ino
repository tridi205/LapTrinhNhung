int list_btn [10] = {0,1,2,3,4,5,6,7,8,9};
void setup() {
  for(int i = 0; i<10; i++)
  {
    pinMode(list_btn[i], OUTPUT);
  }

}

void loop() {
  for(int i = 0; i<10; i++)
  {
    int rnd = random(0,999);
    if(rnd % 2 == 1)
    {
      digitalWrite(list_btn[i],HIGH);
    }
    else
    {
      digitalWrite(list_btn[i],LOW);
    }
    delay(200);
  }

}
