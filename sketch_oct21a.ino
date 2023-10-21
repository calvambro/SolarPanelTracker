const int RPWM = 10; // up
const int LPWM = 11; // down
byte Speed = 255; // max speed

const int LDR_1 = A0; // upper
const int LDR_2 = A1;  // lower

// function min
int high = 0;

// position
int curr = 0;
int pos = 1;

int diff;

void setup() {

  // LDR sensor
  pinMode(LDR_1, INPUT);
  pinMode(LDR_2, INPUT);
  
  // actuator
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
  // read value LDR
  int LDR1_val = analogRead(LDR_1);
  int LDR2_val = analogRead(LDR_2);

  // get sensor with minimum value (high intensity)
  high = func_min(LDR1_val, LDR2_val);
  Serial.println(analogRead(LDR1_val));
  Serial.println(analogRead(LDR2_val));

  delay(2000); // 2 second

  if(high == LDR1_val){
    analogWrite(RPWM, Speed);
    analogWrite(LPWM, 0);

    diff = LDR2_val - LDR1_val;

    Serial.println("kanannnn");

    // if value LDR 1 = LDR 2 or difference < 25, then stop
    if(LDR1_val == LDR2_val || diff < 5){
        // actuator
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  Serial.begin(9600);

      delay (1000); // 10 second
    }
  }else if(high == LDR2_val){
    analogWrite(RPWM, 0);
    analogWrite(LPWM, Speed);

    diff = LDR1_val - LDR2_val;

    Serial.println("kiriiii");

    // if value LDR 1 = LDR 2 or difference < 25, then stop
    if(LDR1_val == LDR2_val || diff < 5){
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);

      delay (1000); // 10 second
    }
  }
  Serial.println("===================");

}

int func_min(int a, int b){
  
  int minVal = 9999;

  if(a < minVal){
    minVal = a;
  }

  if(b < minVal){
    minVal = b;
  }

  return minVal;

}
