#include <Arduino.h>
#include <Streaming.h>
#include <GenericSerial.h>


const long BAUD = 115200;
GenericSerial generic_serial(Serial);
GenericSerial1to3 generic_serial3(Serial3);
GenericSerialBase* generic_serial_ptr;
GenericSerialBase* generic_serial3_ptr;

void setup()
{
  generic_serial_ptr = &generic_serial;
  generic_serial3_ptr = &generic_serial3;

  generic_serial_ptr->begin(BAUD);
  generic_serial_ptr->getStream().flush();

  generic_serial3_ptr->begin(BAUD);
  generic_serial3_ptr->getStream().flush();

  delay(1000);
}


void loop()
{
  generic_serial_ptr->getStream().println("Hello ");
  generic_serial_ptr->getStream() << "World!" << endl;
  delay(500);

  generic_serial3_ptr->getStream().println("Hello ");
  generic_serial3_ptr->getStream() << "World!" << endl;
  delay(500);
}
