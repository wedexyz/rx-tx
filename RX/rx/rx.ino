#include <SoftwareSerial.h>
//penerima

SoftwareSerial mySerial(0,1);//rxtx
void setup() 
{
  pinMode(3,OUTPUT);
mySerial.begin(9600);
}

void loop() {
  char c;
  if(mySerial.available()>0){
    c=mySerial.read();
    if(c=='1'){
      digitalWrite(3,HIGH);
    }
    if(c=='0'){
      digitalWrite(3,LOW);
    }
  }
}
