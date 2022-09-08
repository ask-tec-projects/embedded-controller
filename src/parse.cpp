#include <Ethernet.h>
#include <WString.h>
#include <parse.h>

String parse_http_request(EthernetClient client) {
  String request = String();
  while (client.available()) {
    char c = client.read();
    request += c;
  }
  return request;
}

String parse_http_request_path(String request) {
  String path = String();
  signed short i = 0;
  while (request[i] != '/') {
    i++;
  }
  while (request[i] != ' ') {
    path += request[i];
    i++;
  }
  return path;
}
