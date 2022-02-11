#include
Servo myServo;
int POT = a4;
int reading, newPos, currMap, num;

void setup (){
  myServo.attach(3);
  pinMode(POT,INPUT);
  Serial.begin(9600); 
}
int readPot(){
  int curr;
  if(curr != reading){
    reading = analogRead(POT);
    curr = reading;
  }
  return curr;
}
void mapServo(int pos){
  int curr;
  num= map(pos, 0, 1023, 0, 180);
  myServo.write(num);
  delay(50);
}
void loop(){
  newPos = readPot();
  mapServo(newPos);

  if (currMap!= newPos){
    Serial.print("Pot Position = ");
    Serial.print(newPos);
    Serial.print(" Servo Angle = ");
    currMap = newPos;
  }
}
