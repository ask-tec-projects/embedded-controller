#ifndef LED_H
#define LED_H

class Led {
protected:
  unsigned char pin;
  bool state;
  void write();

public:
  Led(unsigned char pin);
  bool is_on();
  void toggle();
  void turn_on();
  void turn_off();
  void set(bool state);
};

#endif
