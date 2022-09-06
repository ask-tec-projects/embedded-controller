#ifndef DIGITAL_TOGGLE_BUTTON_H
#define DIGITAL_TOGGLE_BUTTON_H

#include <digital_button.h>

class DigitalToggleButton {
protected:
  DigitalButton *button;
  bool state;
  bool last_state;

public:
  DigitalToggleButton(byte pin, bool state);
  bool is_on();
  void tick();
};

#endif
