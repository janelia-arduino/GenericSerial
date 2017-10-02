// ----------------------------------------------------------------------------
// GenericSerial.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef GENERIC_SERIAL_H
#define GENERIC_SERIAL_H
#include <Arduino.h>

class GenericSerialBase
{
public:
  virtual Stream &getStream() = 0;
  virtual void begin(long baudrate);
  virtual void end();
};

class GenericSerial1to3 : public GenericSerialBase
{
public:
  GenericSerial1to3(HardwareSerial &serial);
  void setSerial(HardwareSerial &serial);
  Stream &getStream();
  void begin(long baudrate);
  void end();
private:
  HardwareSerial *serial_ptr_;
};

#if defined(__AVR__) || defined(__PIC32MX__)

class GenericSerial : public GenericSerialBase
{
public:
  GenericSerial(HardwareSerial &serial);
  void setSerial(HardwareSerial &serial);
  Stream &getStream();
  void begin(long baudrate);
  void end();
private:
  HardwareSerial *serial_ptr_;
};

#else

class GenericSerial : public GenericSerialBase
{
public:
  GenericSerial(usb_serial_class &serial);
  void setSerial(usb_serial_class &serial);
  Stream &getStream();
  void begin(long baudrate);
  void end();
private:
  usb_serial_class *serial_ptr_;
};

#endif

#endif
