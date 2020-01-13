int Pin1 = A0;
int OUT1 = 2;

float value1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Pin1, INPUT);
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
