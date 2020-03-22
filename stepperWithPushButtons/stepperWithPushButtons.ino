
/* Stepper controlled by push buttons
 *
 */
int dirPin = 2;
int stepperPin = 3;

int counterClockWisePin = 8;   // choose the input pin (for a pushbutton)
int clockwisePin = 4;   // choose the input pin (for a pushbutton)

int counterClockWise = 0;     // variable for reading the pin status
int clockWise = 0;


void setup() {
  pinMode(dirPin, OUTPUT);
  pinMode(stepperPin, OUTPUT);
  pinMode(counterClockWisePin, INPUT);    
  pinMode(clockwisePin, INPUT);    
}

void step(boolean dir,int steps){
  digitalWrite(dirPin,dir);
  for(int i=0;i<steps;i++){
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(500);
  }
}


void loop(){
  counterClockWise = digitalRead(counterClockWisePin);  // read input counterClockWiseue
  clockWise = digitalRead(clockwisePin);  // read input counterClockWise

  if (counterClockWise == HIGH) {        
    step(false,1);
  } else if (clockWise == HIGH) {
    step(true,1);
  }
}
 
