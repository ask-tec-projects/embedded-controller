#include <Ethernet.h>
#include <digital_button.h>
#include <main.h>

EthernetServer HTTP_SERVER(80);
DigitalButton button(2);

void setup() {
  Ethernet.begin(MAC_ADDR, IP_ADDR);
  HTTP_SERVER.begin();
}

void loop() {
  EthernetClient client = HTTP_SERVER.available();
  button.tick();
  if (!client) {
    return;
  }
  boolean line_blank = true;
  while (client.connected()) {
    if (!client.available()) {
      continue;
    }

    char c = client.read();
    if (c == '\n' && line_blank) {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      if (button.is_pressed()) {
        client.println("<html><body><h1>HTTP 1.1 200 OK</h1></body></html>");
      } else {
        client.println(
            "<html><body><h1>HTTP 1.1 201 CREATED</h1></body></html>");
      }

      break;
    }
    if (c == '\n') {
      line_blank = true;
    } else if (c != '\r') {
      line_blank = false;
    }
  }
  delay(1);
  client.stop();
}
