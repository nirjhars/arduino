int Pin1 = A0;
int OUT1 = 2;


int Pin2 = A1;
int OUT2 = 3;

int Pin3 = A2;
int OUT3 = 4;

int Pin4 = A3;
int OUT4 = 4;

float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(OUT1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(OUT1, HIGH);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  value1 = analogRead(Pin1);
  value1= map(value1,650,200,0,100);
  Serial.print(value1);
  Serial.println("%");
   if (value1<50)
   {
    Serial.print('H');
   }
   else{
  Serial.print('L');
  }
 
  delay(1000);
}
