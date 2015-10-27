#include "Arduino.h"
#include "Streaming.h"
#include "GenericSerial.h"
#include "Server.h"


const int BAUDRATE = 9600;
GenericSerial generic_serial(Serial);
Server server(generic_serial);

void setup()
{
  server.begin(BAUDRATE);
  server.getStream().flush();
  delay(1000);
}


void loop()
{
  server.getStream().println("Hello ");
  server.getStream() << "World!" << endl;
  delay(500);
}
