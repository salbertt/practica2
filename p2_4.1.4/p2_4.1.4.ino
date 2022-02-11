//Realizar los cambios necesarios para que el LED encienda 
//sii el voltaje que entra al puerto A0 es mayor a 3V
void setup(){
  Serial.begin(9600);
  pinMode(2, output);
}

void loop() {
  float volts;
  volts = analogRead(A1); // returns bit (0= 0 volts, 1024=5.0 volts)
  volts = volts * 5.0 / 1024.0; // convert bits to volts
  if (volts >= 3.0) {
    digitalWrite(2, HIGH);
    }
  else {
    digitalWrite(2, LOW);
    }

}
