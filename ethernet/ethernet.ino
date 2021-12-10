/*  Web Server Example*/

#include <SPI.h>
#include <Ethernet.h>

float voltage;
float temp;
boolean LED_status = 0;

byte mac[] = {0xDE, 0xAA, 0xBC, 0xEC, 0xFE, 0xFF}; // Enter a MAC address
IPAddress ip(172, 16, 231, 231); // Enter a MAC address and IP address
// The IP address will be dependent on your local network

EthernetServer server(80); // Initialize the Ethernet server library

void setup() {
  Serial.begin(9600); // Open serial communications and wait for port to open:
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");
  Ethernet.begin(mac, ip); // start the Ethernet connection and the server:

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {  // Check for Ethernet hardware present
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. ");
    while (true) {
      delay(1); // do nothing without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

      pinMode(2, OUTPUT);       // LED on pin 2
      digitalWrite(2, HIGH);
      delay(1000);

  server.begin();  // start the server
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  EthernetClient client = server.available(); // listen for incoming clients
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {

    voltage = analogRead(A1); //Get the raw value from A1
    voltage = (voltage/1023)*5000;//Convert raw value to mV
    temp = voltage /10,0; //Convert  mV to temperature

      
      if (client.available()) {
        char c = client.read();
        //Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
     client.println("<!DOCTYPE html>");
     client.println("<html>");
     client.println("<head>");
     client.println("<title>Arduino Temperature</title>");
     client.println("</head>");
     client.println("<body>");
     client.println("<h1>TEMPERATURE</h1>");
     client.print("<p>Room temparature is ");
     client.print("<b>");
     client.print(temp);
     client.print("</b>");
     client.println(" degrees C");
     client.println("</p>");
     client.println("</body>");
     client.println("</html>");
     client.println("<br />");

          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
