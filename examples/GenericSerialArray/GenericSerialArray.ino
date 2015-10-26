#include "Arduino.h"
#include "Streaming.h"
#include "Array.h"
#include "GenericSerial.h"


const int BAUDRATE = 9600;
GenericSerial generic_serial(Serial);
GenericSerial1to3 generic_serial3(Serial3);
const int SERIAL_COUNT = 2;
// Array<GenericSerialBase*,SERIAL_COUNT> serial_ptr_array;
GenericSerialBase* serial_ptr_array[SERIAL_COUNT];

void setup()
{
  serial_ptr_array[0] = &generic_serial;
  serial_ptr_array[1] = &generic_serial3;
  // serial_ptr_array.push_back(&generic_serial);
  // serial_ptr_array.push_back(&generic_serial3);

  // for (unsigned int i = 0;i<serial_ptr_array.size();++i)
  for (unsigned int i = 0;i<SERIAL_COUNT;++i)
  {
    serial_ptr_array[i]->getSerial().begin(BAUDRATE);
    serial_ptr_array[i]->getSerial().flush();
  }

  delay(1000);
}


void loop()
{
  // for (unsigned int i = 0;i<serial_ptr_array.size();++i)
  for (unsigned int i = 0;i<SERIAL_COUNT;++i)
  {
    serial_ptr_array[i]->getSerial().println("Hello ");
    serial_ptr_array[i]->getSerial() << "World!" << endl;
    delay(500);
  }
}
