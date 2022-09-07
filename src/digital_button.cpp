#include <Arduino.h>
#include <digital_button.h>

DigitalButton::DigitalButton(byte pin) {
  this->pin = pin;
  this->state = false;
  pinMode(pin, INPUT);
}

bool DigitalButton::is_pressed() { return this->state; }

void DigitalButton::tick() { this->state = digitalRead(this->pin) == HIGH; }
