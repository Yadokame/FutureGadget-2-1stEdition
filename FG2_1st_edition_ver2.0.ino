#define pin_sensor A0
#define pin_LED 2

int min = 1023;
int max = 0;
int x = 0;
int out = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pin_LED,OUTPUT);
  x = analogRead(pin_sensor);
  min = x;
  max = x;
}

void loop(){
  x = analogRead(pin_sensor);
  if(x < min){
    min = x;
  }else if(x > max){
    max = x;
  }
  out = ((x - min)/(max - min))*255;

  Serial.print("x = ");
  Serial.print(x);
  Serial.print("\tmin = ");
  Serial.print(min);
  Serial.print("\tmax = ");
  Serial.print(max);
  Serial.print("\tout = ");
  Serial.println(out);

  analogWrite(pin_LED,out);
}
