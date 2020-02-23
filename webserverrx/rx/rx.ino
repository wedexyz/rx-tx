#include <SoftwareSerial.h>
//penerima


SoftwareSerial mySerial(0,1);//rxtx
int led1 =3;
int led2 =4;
int led3 =5;
int led4 =6;
int led5 =7;
void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
mySerial.begin(9600);
}

void loop() {
  char c;
  if(mySerial.available()>0){
    c=mySerial.read();
    if(c=='0'){
      digitalWrite(led1,LOW);
    }
    if(c=='1'){
      digitalWrite(led1,HIGH);
    }
     if(c=='2'){
      digitalWrite(led2,LOW);
    }
    if(c=='3'){
      digitalWrite(led2,HIGH);
    }
     if(c=='4'){
      digitalWrite(led3,LOW);
    }
    if(c=='5'){
      digitalWrite(led3,HIGH);
    }
     if(c=='6'){
      digitalWrite(led4,LOW);
    }
    if(c=='7'){
      digitalWrite(led4,HIGH);
    }
     if(c=='8'){
      digitalWrite(led5,LOW);
    }
    if(c=='9'){
      digitalWrite(led5,HIGH);
    }
  }
}
