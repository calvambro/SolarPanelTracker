int RPWM = 10;
int LPWM = 11;
int Speed = 255;

void setup() {
  // put your setup code here, to run once:
  //configure motor driver as an output
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Speed = 255;
  analogWrite(RPWM, 0);
  analogWrite(LPWM, Speed);
  
  delay(2000); // 2 Seconds
  
  // Stop Actuator
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);

  delay(2000); // 2 Seconds

  //Retract Actuator at Half Speed
  Speed = 127;
  analogWrite(RPWM, Speed);
  analogWrite(LPWM, 0);
  
  delay(2000); // 2 Seconds
  
  // Stop Actuator
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);

  delay(2000); // 2 Seconds


}
