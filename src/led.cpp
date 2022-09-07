#include <Arduino.h>
#include <led.h>

Led::Led(byte pin) {
  this->state = false;
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

bool Led::is_on() { return this->state; }

void Led::write() { digitalWrite(this->pin, this->state ? HIGH : LOW); }

void Led::toggle() {
  this->state = !this->state;
  write();
}

void Led::turn_on() {
  this->state = true;
  write();
}

void Led::turn_off() {
  this->state = false;
  write();
}
