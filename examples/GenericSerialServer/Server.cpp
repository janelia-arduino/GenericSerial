// ----------------------------------------------------------------------------
// Server.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
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

void Server::begin(long baudrate)
{
  generic_serial_ptr_->begin(baudrate);
}

Stream& Server::getStream()
{
  return generic_serial_ptr_->getStream();
}
