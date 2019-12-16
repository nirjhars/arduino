int Pin1 = A0;
int OUT1 = 2;

int Pin2 = A1;
int OUT2 = 3;

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
  Serial.println(value1);

  Serial.print("MOISTURE LEVEL - Sensor 2 :");
  value2 = analogRead(Pin2);
  Serial.println(value2);

  if (value2>500)
  {
    digitalWrite(OUT1, LOW);
    Serial.print("Start pump");
  }
  else 
  {
    if (value1>500)
    {
      digitalWrite(OUT1, LOW);
      Serial.print("Continue pump");
    }
    else
    {
      digitalWrite(OUT1, HIGH);
      Serial.print("stop pump");
    }
  }
  
  Serial.println();
  delay(1000);
}
