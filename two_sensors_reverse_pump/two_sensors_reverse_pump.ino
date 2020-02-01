int Pin1 = A0;  //sensor which is higher in height
int OUT1 = 2;

int Pin2 = A1;  //sensor which is lower in height
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
  //Sensor -2 is lower one - A1, Sensor -1 is higher one - A0
  Serial.print("MOISTURE LEVEL - Sensor 1 :");
  value1 = analogRead(Pin1);
  Serial.println(value1);

  Serial.print("MOISTURE LEVEL - Sensor 2 :");
  value2 = analogRead(Pin2);
  Serial.println(value2);

  if (value2>500)
  {
    digitalWrite(OUT1, LOW);
    Serial.println("Water level too low - RED");
    Serial.print("Start pump");
    digitalWrite(OUT2, HIGH);
  } else 
    { 
      if (value1>500)
      {
        digitalWrite(OUT1, LOW);
        Serial.println("Water level okay but still keep the pump on - YELLOW");
        Serial.print("Start pump");
        digitalWrite(OUT2, HIGH);
      } else 
        { 
          if (value1 >= 350)
          {
          digitalWrite(OUT1, HIGH);
          Serial.println("Water level fine");
          Serial.println("Stop filling pump");
          Serial.println("Stop draining pump");
          digitalWrite(OUT2, HIGH);
          }
          else
          {
            digitalWrite(OUT1, HIGH);
            Serial.println("Water level fine");
            Serial.println("Stop filling pump");
            Serial.println("Start draining water");
            digitalWrite(OUT2, LOW);
          }
        }
    }
  delay(1000);
}
