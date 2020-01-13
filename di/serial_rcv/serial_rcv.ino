int OUT1 = 2;
int incomingByte;      // a variable to read incoming serial data into
int OUT2 = 3;

float value1 = 0;
float value2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(OUT1, OUTPUT);
  digitalWrite(OUT1, HIGH);
  delay(500);
}

void loop() {
 if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    Serial.println(incomingByte);

    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(OUT1, LOW);
      Serial.println("Start pump");      
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(OUT1, HIGH);
      Serial.println("Stop pump");      
    }
  }
}
