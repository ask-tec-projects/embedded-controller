#ifndef DIGITAL_BUTTON_H
#define DIGITAL_BUTTON_H

class DigitalButton {
protected:
  unsigned char pin;
  bool state;

public:
  DigitalButton(unsigned char pin);
  bool is_pressed();
  void tick();
};

#endif
