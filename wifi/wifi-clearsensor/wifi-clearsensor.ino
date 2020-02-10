
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <WiFiClientSecure.h> 

/* Set these to your desired credentials. */

const char *ssid = "------";  //ENTER YOUR WIFI SETTINGS
const char *password = "-----";
const char *host = "script.google.com";
const int httpsPort = 443 ;
const int OUT1 = 2;

WiFiClientSecure client; 
String GAS_ID ="-------";

int value; //Sensor reading


//=======================================================================
//                    Power on setup
//=======================================================================
 
void setup() {
  Serial.begin(11520);
  
  int attemptcount = 0;
  String str_attemptcount = String(attemptcount, DEC);
  
  pinMode(OUT1, OUTPUT);  
  digitalWrite(OUT1, HIGH); //Set pump off
 
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue
  delay(1000);
  WiFi.mode(WIFI_STA);        //Disable hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println(str_attemptcount);
  Serial.print("Connecting");
  // Wait for connection & - attempt to connect in twenty times
  while ((WiFi.status() != WL_CONNECTED) && (attemptcount < 20)) {
    delay(500);  
    str_attemptcount = String(attemptcount, DEC);
    Serial.println(str_attemptcount + ".");
    attemptcount++ ;
  }
  
 if (WiFi.status() != WL_CONNECTED)
 {
  Serial.print("Internet connection not working");
 }
 else{
  //If connection successful show IP address in serial monitor
  Serial.print("Connected to " + ssid + " IP Address: " + WiFi.localIP());  //debug statement
 }
}
 
//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  value = analogRead(0);
  Serial.println("Value =" + value);
  //if sensor reading is more than 500 - turn on pump
  if (value>500){
      digitalWrite(OUT1, LOW);
  } else{
      digitalWrite(OUT1, HIGH);
  }
  sendData(value);
  delay(10000);
}

//Send data to google Doc
void sendData(int val){
  Serial.print("Connecting to ");
  Serial.println(host);
//Debug - test connection to google doc url
 if (!client.connect(host,httpsPort))
  {
    Serial.println("connection failed");
    return;
  }
  int val_soil = 0 ; 
  String string_clear = String(val, DEC);
  String string_soil = String(val_soil, DEC);

  String url = "https://script.google.com/macros/s/" + GAS_ID + "/exec?SensorSoil=" + string_soil + "&SensorClear=" + string_clear;
  Serial.print("requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
          "Host: " + host + "\r\n" +
          "User-Agent: BuildFailureDetectorESP8266\r\n" +
          "Connection: close\r\n\r\n");
          
  Serial.println("request sent");
  while (client.connected()){
    String line = client.readStringUntil('\n');
    if (line == "\r"){
      Serial.println("Headers received");
      break;
    }
  }
  
  String line = client.readStringUntil('\n');
  Serial.println("closing connection");
}
