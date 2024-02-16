
 int switchPin1 = 2; 
 int switchPin2 = 4; 

int leftSwitchPin = 3;
int rightSwitchPin = 4;

 int leftVoltagePin = A0; 
 int rightVoltagePin = A1; 


 int leftMotorPin = 6; 
 int rightMotorPin = 5; 

void setup() {
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  
  
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  
 
  pinMode(leftSwitchPin, INPUT);
  pinMode(rightSwitchPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  
 int switchState1 = digitalRead(switchPin1);
 int switchState2 = digitalRead(switchPin2);
 
  int leftSwitchState1 = digitalRead(leftSwitchPin);
  int rightSwitchState2 = digitalRead(rightSwitchPin);

int leftVoltage = map(analogRead(leftVoltagePin), 0, 1023, 0, 255);
  
int rightVoltage = map(analogRead(rightVoltagePin), 0, 1023, 0, 255);
  
  if(switchState1 == 1){
    (leftSwitchState1 == 1);
     digitalWrite(leftMotorPin, 1);
    analogWrite(leftMotorPin, leftVoltage);
    } else {
    digitalWrite(leftMotorPin, 0);
  }

  if(switchState2 == 1){ 
    (rightSwitchState2 == 1);
    digitalWrite(rightMotorPin, 1); 
    analogWrite(rightMotorPin, rightVoltage);
  } else {
    digitalWrite(rightMotorPin, 0);
  }
  
  if (Serial.available() > 0) {
    char reading = Serial.read();
    if (reading == 'L') {
      digitalWrite(leftMotorPin, 1);
    } else if (reading == 'R') {
      digitalWrite(rightMotorPin, 1); 
    } else if (reading == 'S') {
      digitalWrite(leftMotorPin, 0); 
      digitalWrite(rightMotorPin, 0); 
    }
  }
}
