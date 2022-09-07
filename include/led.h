#ifndef LED_H
#define LED_H

class Led {
protected:
  byte pin;
  bool state;
  void write();

public:
  Led(byte pin);
  bool is_on();
  void toggle();
  void turn_on();
  void turn_off();
};

#endif
