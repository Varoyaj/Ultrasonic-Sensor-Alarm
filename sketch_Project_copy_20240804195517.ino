#define trigPin 13
#define echoPin 12
#define Green_led 11
#define Red_led 9
#define Yellow_led 10
#define Buzzer 8
void setup(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(Green_led, OUTPUT);
pinMode(Yellow_led, OUTPUT);
pinMode(Red_led, OUTPUT);
pinMode(Buzzer, OUTPUT);
}
void loop(){
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 20 && distance > 10){
digitalWrite(Green_led,LOW);
digitalWrite(Yellow_led, HIGH);
digitalWrite(Red_led, LOW);
noTone(Buzzer);
}
else if (distance <= 10){
digitalWrite(Green_led,LOW);
digitalWrite(Yellow_led, LOW);
digitalWrite(Red_led, HIGH);
tone(Buzzer, 100);
}
else {
digitalWrite(Green_led,HIGH);
digitalWrite(Yellow_led, LOW);
digitalWrite(Red_led, LOW);
noTone(Buzzer);
}
delay(100);
}