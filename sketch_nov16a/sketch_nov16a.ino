#include <AFMotor.h>
int linetracking = 13; // Declaration of the sensor input pin
int value; // Temporary variable
AF_DCMotor motorl = AF_DCMotor(4, MOTOR12_64KHZ);

AF_DCMotor motorr = AF_DCMotor(3, MOTOR12_64KHZ);

void startMotorl() {
  motorl.run(FORWARD);
}
void startMotorr(){
    motorr.run(FORWARD);
}

void startMotors(){
  motorr.run(FORWARD);
  motorl.run(FORWARD);
}

void stopMotorl() {
  motorl.run(RELEASE);
}
void stopMotorr(){
    motorr.run(RELEASE);
}

void stopMotors(){
  motorr.run(RELEASE);
  motorl.run(RELEASE);
}
void lineSweep(){
  value = digitalRead(linetracking)
  
  startMotorr()
  while ()){
    value = digitalRead()
    
  }


}
void setup () {
  pinMode(linetracking, INPUT); // Initialization sensor pin
  digitalWrite(linetracking, HIGH); // Activation of internal pull-up resistor
  Serial.begin(9600); // Initialization of the serial monitor
  Serial.println("KY-033 Linetracking");
}
   
void loop () {
  timeSinceLastRun = time();
  timeSinceStart = timeSinceStart + timeSinceLastRun;
  counter = counter + timeSinceLastRun;

  value = digitalRead(linetracking);
  // If a signal could be detected, this is displayed on the serial monitor.
  if (value == HIGH) {
    Serial.println("Line recognized");
    startMotors();
  }

  if (value == LOW){
   
    
  }
    
  
    



  



}




