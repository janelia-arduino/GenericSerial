#include <Arduino.h>
#include <Streaming.h>
#include <Array.h>
#include <GenericSerial.h>


const long BAUDRATE = 115200;
GenericSerial generic_serial(Serial);
GenericSerial1to3 generic_serial3(Serial3);
const int SERIAL_COUNT = 2;
Array<GenericSerialBase*,SERIAL_COUNT> serial_ptr_array;

void setup()
{
  serial_ptr_array.push_back(&generic_serial);
  serial_ptr_array.push_back(&generic_serial3);

  for (unsigned int i = 0;i<serial_ptr_array.size();++i)
  {
    serial_ptr_array[i]->begin(BAUDRATE);
    serial_ptr_array[i]->getStream().flush();
  }

  delay(1000);
}


void loop()
{
  for (unsigned int i = 0;i<serial_ptr_array.size();++i)
  {
    serial_ptr_array[i]->getStream().println("Hello ");
    serial_ptr_array[i]->getStream() << "World!" << endl;
    delay(500);
  }
}
