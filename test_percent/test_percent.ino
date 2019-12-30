int Pin1 = A0;
int OUT1 = 2;

/*
int Pin2 = A1;
int OUT2 = 3;
*/

float value1 = 0;
float value2 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(OUT1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(OUT1, HIGH);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("MOISTURE LEVEL - Sensor 1 :");
  value1 = analogRead(Pin1);
  Serial.println("Moisture: ");
  Serial.println(value1);
  value1= map(value1,650,200,0,100);
  Serial.print("Moisture: ");
  Serial.print(value1);
  Serial.println("%");
  

  Serial.println();
  delay(1000);
}
