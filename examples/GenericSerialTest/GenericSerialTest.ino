#include <Arduino.h>
#include <Streaming.h>
#include <GenericSerial.h>


const long BAUD = 115200;
GenericSerial generic_serial(Serial);
GenericSerial1to3 generic_serial3(Serial3);

void setup()
{
  generic_serial.begin(BAUD);
  generic_serial.getStream().flush();

  generic_serial3.begin(BAUD);
  generic_serial3.getStream().flush();

  delay(1000);
}


void loop()
{
  generic_serial.getStream().println("Hello ");
  generic_serial.getStream() << "World!" << endl;
  delay(500);

  generic_serial3.getStream().println("Hello ");
  generic_serial3.getStream() << "World!" << endl;
  delay(500);
}
