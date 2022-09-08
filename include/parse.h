#ifndef PARSE_H
#define PARSE_H

#include <Ethernet.h>
#include <WString.h>

String parse_http_request(EthernetClient client);
String parse_http_request_path(String request);

#endif
