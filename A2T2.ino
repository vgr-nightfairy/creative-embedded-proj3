#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

const char* ssid = "VGR";
const char* password = "noodles";
char *valueString;

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

const int ledPin[] = {23, 21, 19, 18, 17, 16, 4, 15, 32, 33, 25, 26, 27, 14, 12, 13};

const int Button = 22;

const int Switch = 5;

const int Sensor = 34;
//const int Yaxis = 35;
float SensorVal = 0;

int curr = 0;
int prev = 0;

int ButtonRead = 0;
int XRead = 0;
int YRead = 0;
int SwitchRead = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_up, gateway, subnet);
  
  for (int i = 0; i < 16; i ++) {
    pinMode(ledPin[i], OUTPUT);
  }
  
  pinMode(Button, INPUT_PULLUP);
  pinMode(Switch, INPUT);
  pinMode(Xaxis, INPUT);
  pinMode(Yaxis, INPUT);

  server.begin();

} 

// the loop function runs over and over again forever
void loop() {
  ButtonRead = digitalRead(Button);
  SwitchRead = digitalRead(Switch);
  SensorRead = analogRead(Sensor);

  udp.beginPacket("192.168.1.2", 57222);
  udp.print(String(SensorRead));
  udp.endPacket();
  delay(100);

  if (ButtonRead == 0) {
    while(1);
  }


  if (SwitchRead == 0) {
    if (curr == 16) {
      for (int i = 0; i < 16; i ++) {
        digitalWrite(ledPin[i], LOW);
      }
    }
    else {
      digitalWrite(ledPin[curr], HIGH);
      if (curr != prev) {
        digitalWrite(ledPin[prev], LOW);
      }
    }
    prev = curr;
  }
  else {
    for (int i = 0; i < 16; i ++) {
      digitalWrite(ledPin[i], HIGH);
    }
    delay(1000);
    for (int i = 0; i < 16; i ++) {
      digitalWrite(ledPin[i], LOW);
    }
    delay(1000);
  }
   

  Serial.println(String(ButtonRead));
  Serial.println(String(SensorRead));
  Serial.println(String(SwitchRead));
} 
