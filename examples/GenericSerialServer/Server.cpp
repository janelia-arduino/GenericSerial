// ----------------------------------------------------------------------------
// Server.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "Server.h"


Server::Server(GenericSerialBase &serial)
{
  setSerial(serial);
}

void Server::setSerial(GenericSerialBase &serial)
{
  generic_serial_ptr_ = &serial;
}

void Server::begin(long baud)
{
  generic_serial_ptr_->begin(baud);
}

Stream& Server::getStream()
{
  return generic_serial_ptr_->getStream();
}
