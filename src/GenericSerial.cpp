// ----------------------------------------------------------------------------
// GenericSerial.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "GenericSerial.h"


GenericSerial1to3::GenericSerial1to3(HardwareSerial &serial)
{
  setSerial(serial);
}

void GenericSerial1to3::setSerial(HardwareSerial &serial)
{
  serial_ptr_ = &serial;
}

Stream& GenericSerial1to3::getStream()
{
  return *serial_ptr_;
}

void GenericSerial1to3::begin(long baud)
{
  serial_ptr_->begin(baud);
}

void GenericSerial1to3::end()
{
  serial_ptr_->end();
}

void GenericSerial::begin(long baud)
{
  serial_ptr_->begin(baud);
}

void GenericSerial::end()
{
  serial_ptr_->end();
}

#if defined(__AVR__) || defined(__PIC32MX__)

GenericSerial::GenericSerial(HardwareSerial &serial)
{
  setSerial(serial);
}

void GenericSerial::setSerial(HardwareSerial &serial)
{
  serial_ptr_ = &serial;
}

Stream& GenericSerial::getStream()
{
  return *serial_ptr_;
}

#else

GenericSerial::GenericSerial(usb_serial_class &serial)
{
  setSerial(serial);
}

void GenericSerial::setSerial(usb_serial_class &serial)
{
  serial_ptr_ = &serial;
}

Stream& GenericSerial::getStream()
{
  return *serial_ptr_;
}

#endif
