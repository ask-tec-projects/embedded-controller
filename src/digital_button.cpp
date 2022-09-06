#include <Arduino.h>
#include <digital_button.h>

DigitalButton::DigitalButton(byte pin) : pin(pin) {
  state = false;
  pinMode(pin, INPUT);
}

bool DigitalButton::is_pressed() { return state; }

void DigitalButton::tick() { state = digitalRead(pin) == HIGH; }
