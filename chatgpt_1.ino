const int sensor_1 = A0;
const int sensor_2 = A1;
const int sensor_3 = A2;
const int RPWM = 10;
const int LPWM = 11;
const byte speed = 255;

int minSensorValue;
int currentPosition;
int targetPosition;

int input_1, input_2, input_3;

void setup() {
  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(sensor_3, INPUT);
  
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  input_1 = analogRead(sensor_1);
  input_2 = analogRead(sensor_2);
  input_3 = analogRead(sensor_3);

  minSensorValue = func_min(input_1, input_2, input_3);

  // Determine the target position based on the minimum sensor value
  if (minSensorValue == input_1) {
    targetPosition = 1;
  } else if (minSensorValue == input_2) {
    targetPosition = 2;
  } else {
    targetPosition = 3;
  }

  moveToTargetPosition();
}

int func_min(int a, int b, int c) {
  return min(min(a, b), c);
}

void moveToTargetPosition() {
  if (currentPosition != targetPosition) {
    if (targetPosition == 1) {
      moveActuatorTo(input_1);
    } else if (targetPosition == 2) {
      moveActuatorTo(input_2);
    } else if (targetPosition == 3) {
      moveActuatorTo(input_3);
    }
    currentPosition = targetPosition;
  }
}

void moveActuatorTo(int positionValue) {
  if (positionValue == input_1) {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, speed);
    delay(21000);
  } else if (positionValue == input_2) {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, speed);
    delay(21000);
  } else if (positionValue == input_3) {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, speed);
    delay(43000);
  }
  
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}
