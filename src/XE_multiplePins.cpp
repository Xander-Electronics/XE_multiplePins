/*
  This file is part of the XE_multiplePins library.
  Copyright (c) 2021-2022 Xander Electronics. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "XE_multiplePins.h"

void multiplePinMode(const int *pins, const int numberOfPins, uint8_t mode) {
  for (uint8_t i  = 0; i < numberOfPins; i++) {
    if (mode == INPUT_PULLUP) pinMode(pins[i], INPUT_PULLUP);
    else if (mode == OUTPUT) pinMode(pins[i], OUTPUT);
    else pinMode(pins[i], INPUT);
  }
}

void multipleDigitalWrite(const int *pins, const int numberOfPins, uint16_t number) {
  for (uint8_t i = 0; i < numberOfPins; i++) {
    if (number & (1 << i)) {
      digitalWrite(pins[i], HIGH);
    }
    else {
      digitalWrite(pins[i], LOW);
    }
  }
}

uint64_t multipleDigitalRead(const int *pins, const int numberOfPins) {
  uint16_t value = 0;
  for (uint8_t i = 0; i < numberOfPins; i++) {
    if (digitalRead(pins[i])) {
      value += (uint16_t) (1 << i);
    }
  }
  return value;
}

void multipleAnalogRead(const int *pins, const int numberOfPins, int *values) {
  for (uint8_t i = 0; i < numberOfPins; i++) {
    values[i] = analogRead(pins[i]);
    Serial.println(values[i]);
  }
}

void multipleAnalogWrite(const int *pins, const int numberOfPins, uint8_t* values) {
  for (uint8_t i = 0; i < numberOfPins; i++) {
    analogWrite(pins[i], values[i]);
  }
}

