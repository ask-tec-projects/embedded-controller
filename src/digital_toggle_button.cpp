#include <Arduino.h>
#include <digital_toggle_button.h>

DigitalToggleButton::DigitalToggleButton(byte pin, bool state) {
  this->button = new DigitalButton(pin);
  this->state = state;
  this->last_state = state;
}

bool DigitalToggleButton::is_on() { return state; }

void DigitalToggleButton::tick() {
  /* bool current_state = digitalRead(pin) == HIGH; */
  /* if (current_state != last_state) { */
  /* state = current_state; */
  /* } */
}
