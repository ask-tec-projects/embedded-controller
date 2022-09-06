#include <Ethernet.h>
#include <SPI.h>

#ifndef MAIN_H
#define MAIN_H

byte MAC_ADDR[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x02};
IPAddress IP_ADDR(192, 168, 1, 1);

void setup();
void loop();

#endif
