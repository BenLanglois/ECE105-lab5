int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
} 

void loop() {
  if (Serial.available() > 0) { //https://www.arduino.cc/en/Serial/Read
      // read the incoming byte:
      incomingByte = Serial.read();

      // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
   }
}
