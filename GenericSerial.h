// ----------------------------------------------------------------------------
// GenericSerial.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef GENERIC_SERIAL_H
#define GENERIC_SERIAL_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#if defined(__AVR__) || defined(__PIC32MX__)

class GenericSerial
{
public:
  GenericSerial();
  GenericSerial(HardwareSerial &serial);
  void setSerial(HardwareSerial &serial);
  HardwareSerial &getSerial();
private:
  HardwareSerial *serial_ptr_;
};

#else

class GenericSerial
{
public:
  GenericSerial();
  GenericSerial(usb_serial_class &serial);
  void setSerial(usb_serial_class &serial);
  GenericSerialBase &getSerial();
private:
  usb_serial_class *serial_ptr_;
};

#endif

#endif
