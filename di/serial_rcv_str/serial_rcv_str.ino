int Pin1 = A0;
int OUT1 = 2;
int incomingByte;      // a variable to read incoming serial data into

int Pin2 = A1;
int OUT2 = 3;

float value1 = 0;
float value2 = 0;

char str1[4];

void setup() {
  Serial.begin(9600);
  
  pinMode(OUT1, OUTPUT);
  digitalWrite(OUT1, HIGH);
  delay(500);
}

void loop() {
int i = 0; 
  if (Serial.available()) 
  {
    delay(100); //allows all serial sent to be received together - 
    //only four characters will read
    while(Serial.available() && i<4) 
    {
      str1[i++] = Serial.read();
    }
    str1[i++]='\0';
  }
  if(i>0) {
    Serial.println(str1);
  }
}
