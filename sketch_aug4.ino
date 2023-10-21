int sensor_1 = A0;
int sensor_2 = A1;
int sensor_3 = A2;
int RPWM = 10;
int LPWM = 11;
byte speed = 255;
int min;
int curr_pos;
int pos = 1;

void setup() {
  
  //input for ldr sensor
  pinMode(sensor_1, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(sensor_3, INPUT);

  //configure motor driver as an output
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int input_1 = analogRead(sensor_1);
  int input_2 = analogRead(sensor_2);
  int input_3 = analogRead(sensor_3);


  // Speed = 255;
  // analogWrite(RPWM, 0);
  // analogWrite(LPWM, Speed);
  
  // delay(2000); // 2 Seconds
  
  // // Stop Actuator
  // analogWrite(RPWM, 0);
  // analogWrite(LPWM, 0);

  // delay(2000); // 2 Seconds

  // Retract Actuator at Half Speed
  // Speed = 127;
  // analogWrite(RPWM, Speed);
  // analogWrite(LPWM, 0);
  
  // delay(2000); // 2 Seconds
  
  // // Stop Actuator
  // analogWrite(RPWM, 0);
  // analogWrite(LPWM, 0);

  // delay(2000); // 2 Seconds

  min = func_min(input_1, input_2, input_3);

  Serial.println(analogRead(sensor_1));
  Serial.println(analogRead(sensor_2));
  Serial.println(analogRead(sensor_3));
  Serial.println("======================");
  delay(2000);
  
  if(pos == 1){
    
    if(min == input_2){
      analogWrite(RPWM, 0);
      analogWrite(LPWM, speed);
      
      delay(21000);
    
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);

      curr_pos = input_2;

    } else if(min == input_3){
      analogWrite(RPWM, 0);
      analogWrite(LPWM, speed);
      
      delay(43000);
    
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);

      curr_pos = input_3;

    }

    pos = curr_pos;

  } else if(pos == 2){
    
    if(min == input_1){
      analogWrite(LPWM, speed);
      analogWrite(RPWM, 0);

      delay(21000);

      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);      

      curr_pos = input_1;

    } else if(min == input_3){
      analogWrite(RPWM, 0);
      analogWrite(LPWM, speed);
      
      delay(21000);
    
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);

      curr_pos = input_3;
    }

    pos = curr_pos;

  } else if(pos == 3){
    
    if(min == input_1){
      analogWrite(LPWM, speed);
      analogWrite(RPWM, 0);

      delay(43000);

      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);      

      curr_pos = input_1;

    }else if(min == input_2){
      analogWrite(LPWM, speed);
      analogWrite(RPWM, 0);

      delay(21000);

      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);      

      curr_pos = input_2;
    }
    
    pos = curr_pos;
    
  }

  
  // Serial.print("1");

}

int func_min(int a, int b, int c){

  int small = 9999;

  if(a < small){
    small =  a;
  }
  if(b < small){
    small =  b;
  }
  if(c < small){
    small =  c;
  }  

  return small;

}
