int RPWM = 10;
int LPWM = 11;

int Speed = 255;

void setup() {
  // actuator
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:


  analogWrite(RPWM, 0);
  analogWrite(LPWM, Speed);

  delay (20000);

  // analogWrite(RPWM, Speed);
  // analogWrite(LPWM, 0);

  // delay (20000);  
  
  // analogWrite(RPWM, 0);
  // analogWrite(LPWM, 0);


}
