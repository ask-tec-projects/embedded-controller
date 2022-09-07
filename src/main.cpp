#include <Ethernet.h>
#include <led.h>
#include <main.h>

EthernetServer HTTP_SERVER(80);
Led led(13);

void setup() {
  Serial.begin(9600);
  Ethernet.begin(MAC_ADDR, IP_ADDR);
  HTTP_SERVER.begin();
  Serial.println("Init complete");
}

void loop() {
  EthernetClient client = HTTP_SERVER.available();
  if (!client) {
    return;
  }

  Serial.println("Request received");
  led.turn_on();
  boolean line_blank = true;
  int i = 0;

  while (client.connected()) {
    i++;
    Serial.print("Connected ");
    Serial.println(i);
    if (!client.available()) {
      continue;
    }

    char c = client.read();
    Serial.print(c);
    if (c == '\n' && line_blank) {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html><body><h1>HTTP 1.1 200 OK</h1></body></html>");

      break;
    }
    if (c == '\n') {
      line_blank = true;
      Serial.print('\n');
    } else if (c != '\r') {
      line_blank = false;
    }
  }
  delay(1);
  client.stop();
  Serial.println("Response sent");
  led.turn_off();
}
