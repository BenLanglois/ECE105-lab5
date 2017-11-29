int input;
bool receivedInput = false;
unsigned long startTime;

#define MOTOR1PWM 5
#define MOTOR1DIR 7
#define MOTOR1BRK 12


#define MOTOR2PWM 6
#define MOTOR2DIR 8
#define MOTOR1BRK 13


void setup() {
  Serial.begin(9600);

  // Set pins
  pinMode(MOTOR1PWM, OUTPUT);
  pinMode(MOTOR2PWM, OUTPUT);
  pinMode(MOTOR1DIR, OUTPUT);
  pinMode(MOTOR2DIR, OUTPUT);
  pinMode(MOTOR1BRK, OUTPUT);
  pinMode(MOTOR2BRK, OUTPUT);


  digitalWrite(MOTOR1DIR, HIGH);
  digitalWrite(MOROR2DIR, HIGH);
  digitalWrite(MOTOR1BRK, HIGH);
  digitalWrite(MOROR2BRK, HIGH);
  digitalWrite(MOTOR1PWM, 0);
  digitalWrite(MOROR2PWM, 0);

  
  Serial.println("Enter a motor speed!");
} 


void loop() {
  if (receivedInput == false) { // Take input from user
    if (Serial.available() > 0) {
      input = (Serial.readString()).toInt();

      if (0 <= input <= 255) Serial.println("Enter a valid integer between 0 and 255.");
      else {
        Serial.println("Running motors!");
        receivedInput = true;
        
        digitalWrite(MOTOR1BRK, LOW);
        digitalWrite(MOROR2BRK, LOW);
        
        analogWrite(MOTOR1PWM, input);
        analogWrite(MOTOR2PWM, input);
        startTime = millis();
      }
    }
    
  } else { // Run motor for 10 seconds
    if (millis() > startTime + 10000) { // 10 seconds has passed
      recievedInput = false;
      Serial.println("Enter a new motor speed!");
        
      analogWrite(MOTOR1PWM, 0);
      analogWrite(MOTOR2PWM, 0);
      
      digitalWrite(MOTOR1BRK, HIGH);
      digitalWrite(MOROR2BRK, HIGH);
    }
  }
}
