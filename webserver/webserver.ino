#include <SoftwareSerial.h>
#include <ESP8266WebServer.h>
SoftwareSerial mySerial(D0,D1);
//RXTX
//pengirim
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
<center>
<button><a href="ledOn1" target="myIframe">L1 ON</a></button>
<button><a href="ledOff1" target="myIframe">L1 OFF</a></button>
<hr>
<button><a href="ledOn2" target="myIframe">L2 ON</a></button>
<button><a href="ledOff2" target="myIframe">L2 OFF</a></button>
<hr>
<button><a href="ledOn3" target="myIframe">L3 ON</a></button>
<button><a href="ledOff3" target="myIframe">L3 OFF</a></button>
<hr>
<button><a href="ledOn4" target="myIframe">L4 ON</a></button>
<button><a href="ledOff4" target="myIframe">L4 OFF</a></button>
<hr>
<button><a href="ledOn5" target="myIframe">L5 ON</a></button>
<button><a href="ledOff5" target="myIframe">L5 OFF</a></button>
<hr>
<iframe name="myIframe" width="100" height="25" frameBorder="0">
</center>
</body>
</html>
)=====";
                                                       
IPAddress    apIP(42, 42, 42, 42);                                  
const char *ssid = "WEDEX";
//const char *password = "12345678";
ESP8266WebServer server(80);

void handleRoot() {
  mySerial.begin(9600);
    String s = MAIN_page; 
      server.send(200, "text/html", s); 
        mySerial.println('1');  delay(500);
         mySerial.println('0');
      
}
void handleLEDoff1() { 
  mySerial.begin(9600);
    mySerial.println('0');
      server.send(200, "text/html", "OFF1"); 
    }
    void handleLEDon1() { 
        mySerial.begin(9600);
          mySerial.println('1');
            server.send(200, "text/html", "ON1");
      }
      void handleLEDoff2() { 
         mySerial.begin(9600);
          mySerial.println('2');
            server.send(200, "text/html", "OFF2"); 
      }
    void handleLEDon2() { 
        mySerial.begin(9600);
            mySerial.println('3');
              server.send(200, "text/html", "ON2");
      }
      void handleLEDoff3() { 
        mySerial.begin(9600);
            mySerial.println('4');
              server.send(200, "text/html", "OFF3"); 
}
    void handleLEDon3() { 
      mySerial.begin(9600);
        mySerial.println('5');
           server.send(200, "text/html", "ON3");
      }
   void handleLEDoff4() { 
      mySerial.begin(9600);
        mySerial.println('6');
          server.send(200, "text/html", "OFF4"); 
      }
    void handleLEDon4() { 
      mySerial.begin(9600);
        mySerial.println('7');
          server.send(200, "text/html", "ON4");
      }

       void handleLEDoff5() { 
      mySerial.begin(9600);
        mySerial.println('8');
          server.send(200, "text/html", "OFF5"); 
      }
    void handleLEDon5() { 
      mySerial.begin(9600);
        mySerial.println('9');
          server.send(200, "text/html", "ON5");
      }



void setup() {
 WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   
  WiFi.softAP(ssid
  //, password
  );

  
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);    
     server.on("/ledOff1", handleLEDoff1);
         server.on("/ledOn1", handleLEDon1); 
           server.on("/ledOff2", handleLEDoff2);
              server.on("/ledOn2", handleLEDon2); 
                server.on("/ledOff3", handleLEDoff3);
                  server.on("/ledOn3", handleLEDon3);
                       server.on("/ledOff4", handleLEDoff4);
                          server.on("/ledOn4", handleLEDon4);
                              server.on("/ledOff5", handleLEDoff5);
                                server.on("/ledOn5", handleLEDon5);

                server.begin();

}

void loop() {
  server.handleClient();
}
