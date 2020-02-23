#include <SoftwareSerial.h>
//pengirim
SoftwareSerial mySerial(D0,D1);//RXTX
void setup(){
  mySerial.begin(9600);
 
  
  }
void loop(){
  mySerial.println('0');
  delay(500);
  mySerial.println('1');
  delay(500);
  
  }


