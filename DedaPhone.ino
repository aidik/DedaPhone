#include <A6lib.h>

#ifndef ESP8266
#define D0 0
#define D5 8
#define D6 7
#endif

// Instantiate the library with TxPin, RxPin.
A6lib A6l(D6, D5);

int R = D1;
int G = D2;
int B = D7;

String Alice = "420602123456";    //red
String Bob = "420603123456";      //green
String Chuck = "420604123456";    //blue
String Dan = "420605123456";      // pink
String Eve = "420606123456";      // yellow
String Last = "";

void setup() {

  pinMode(R, OUTPUT);     // Set R pin as an output
  pinMode(G, OUTPUT);     // Set G pin as an output
  pinMode(B, OUTPUT);     // Set B pin as an output

  digitalWrite(R, HIGH);   // LED Off
  digitalWrite(G, HIGH);   // LED Off
  digitalWrite(B, HIGH);   // LED Off
  
    Serial.begin(115200);
    Serial.println("START");

    delay(1000);

    A6l.blockUntilReady(9600);
    Serial.println("Blocade OFF.");
    rainbow(3);
}

void loop() {
    Serial.println("Checking call status...");
    callInfo cinfo = A6l.checkCallStatus();
    Serial.println("Call status checked.");
    Serial.println("Number");    
    Serial.println(cinfo.number);
    int sigStrength = A6l.getSignalStrength();
    Serial.print("Signal strength percentage: ");
    Serial.println(sigStrength);

    if (cinfo.number == Alice || cinfo.number == Bob || cinfo.number == Chuck || cinfo.number == Dan || cinfo.number == Eve) {
      Last = cinfo.number;
      Serial.println("Number Saved");
      delay(7000);
      A6l.hangUp();
    }

  
      if (Last == Alice) {
        red();
      } else if (Last == Bob) {
        green();
      } else if (Last == Chuck) {
        blue();
      } else if (Last == Dan) {
        pink();
      } else if (Last == Eve) {
        yellow();
      }
  delay(1000);
}

void white() {
      //white
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
}

void red() {
      //red
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
}

void green() {
      //green
      digitalWrite(R, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
}

void blue() {
      //blue
      digitalWrite(R, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
}

void pink() {
      //pink
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
}

void yellow() {
      //yellow
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
}

void black() {          
      digitalWrite(R, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
}

void rainbow(int times) {
  int i = 0;
  while (i < times){
    white();
    delay(250);
    red();
    delay(250);
    green();
    delay(250);
    blue();
    delay(250);
    pink();
    delay(250);
    yellow();
    delay(250);
    i++;
  }
    black();
}  


