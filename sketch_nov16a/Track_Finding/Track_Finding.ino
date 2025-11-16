#include <AFMotor.h>
int linetracking = 13; // Declaration of the sensor input pin
int value; // Temporary variable


// timing and state
unsigned long counter    = 0;    // ms spent in current sweep phase
unsigned long lastMillis = 0;    // last loop time
int sub_state            = 0;    // 0 = sweep right, 1 = sweep left
const unsigned long X    = 1000;  // base time in ms
int speed = 255;
int sweepFactor = 1;
int MAX_SWEEP_FACTOR = 5;

AF_DCMotor motorl = AF_DCMotor(1, MOTOR12_64KHZ);
AF_DCMotor motorr = AF_DCMotor(2, MOTOR12_64KHZ);

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


void setup () {
  delay(5000);
  pinMode(linetracking, INPUT); // Initialization sensor pin
  digitalWrite(linetracking, HIGH); // Activation of internal pull-up resistor
  Serial.begin(9600); // Initialization of the serial monitor
  Serial.println("KY-033 Linetracking");
  motorr.setSpeed(speed);
  motorl.setSpeed(speed);

  lastMillis = millis();

}
   
void loop () {

  // --- timing ---
  unsigned long now = millis();
  unsigned long dt  = now - lastMillis;
  lastMillis = now;
  counter += dt;

  value = digitalRead(linetracking);
  bool lineDetected = (value == HIGH);
  
  if (lineDetected) {
    Serial.println("Line recognized");
    startMotors();
    sub_state = 0;
    sweepFactor = 1;
    counter = 0;
    return;
  }
  
  if (sub_state == 0) {
    stopMotorl();
    startMotorr();
    // Sweep right 
    Serial.println("sweepingright");
    if (counter > X * sweepFactor) {
        sub_state = 1;
        counter = 0;
    }
  }
  else if (sub_state == 1) {
    stopMotorr();
    startMotorl();
    Serial.println("Sweeping left");
    if (counter >   X * (sweepFactor+1)) {
        sub_state = 0;
        counter = 0;
      if (sweepFactor < MAX_SWEEP_FACTOR){
        sweepFactor = sweepFactor + 2;
      }
    }

  } 
  
}
    
  





