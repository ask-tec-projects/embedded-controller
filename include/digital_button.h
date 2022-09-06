#ifndef DIGITAL_BUTTON_H
#define DIGITAL_BUTTON_H

class DigitalButton {
protected:
  byte pin;
  bool state;

public:
  DigitalButton(byte pin);
  bool is_pressed();
  void tick();
};

#endif
