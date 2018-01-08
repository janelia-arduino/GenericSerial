// ----------------------------------------------------------------------------
// Server.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef _SERVER_H_
#define _SERVER_H_
#include <GenericSerial.h>


class Server
{
public:
  Server(GenericSerialBase &serial);
  void setSerial(GenericSerialBase &serial);
  void begin(long baud);
  Stream &getStream();
private:
  GenericSerialBase *generic_serial_ptr_;
};

#endif
