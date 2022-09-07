#include <Ethernet.h>
#include <parse.h>

char *parse_http_request_path(EthernetClient client) {
  while (client.read() != '/') {
  }

  char *buffer;
  size_t buffer_size = 1;
  buffer[0] = '/';
  buffer[1] = '\0';

  while (true) {
    char c = client.read();
    Serial.print(c);
    if (c == ' ') {
      break;
    }
    buffer[buffer_size] = c;
    buffer[buffer_size + 1] = '\0';
    buffer_size++;
  }

  return buffer;
}
