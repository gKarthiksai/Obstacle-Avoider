// This is a code for an obstacle avoider.
// NOTE :- This is just a circuit diagram and the mounting can be done according to the chasey of the builder.
// The curcuit making includes 2 t-grear motors, one servo motor, an ultrasonic distance sensor(HC-SR04-4pin configuration sensor),
// breadboard small and any micro controller(arduino uno is used in this case).
int in1 = 4;
int in2 = 7;
int in3 = 2;
int in4 = 3;
int ena = 6;
int enb = 5;
int trig = 8;
int echo = 9;
int distance;
long duration;
void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  analogWrite(ena,255);
  analogWrite(enb,255);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echo,HIGH);
  distance = (duration * 0.034)/2;
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" ");
  if(distance>20){
    forward();
  }
  if(distance<=20){
    change_path();
  }
}
void forward(){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
}
void change_path(){
  digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(1000);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    delay(2000);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    delay(2000);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
}
