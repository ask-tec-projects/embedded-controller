#include <digital_toggle_button.h>

DigitalToggleButton::DigitalToggleButton(byte pin, bool state)
    : state(state) last_state(state) {
  button = new DigitalButton(pin);
}

bool DigitalButton::is_on() { return state; }

void DigitalButton::tick() {
  bool current_state = digitalRead(pin) == HIGH;
  if (current_state != last_state) {
    state = current_state;
  }
}
