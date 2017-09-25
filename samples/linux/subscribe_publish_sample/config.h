#include "../../../details.h"

#define timePeriod 6 //change the time delay as you required for sending actuator values to paasmer cloud

char* feedname[]={"feed1","feed5"};  //Do not provide any spaces for the feeds.

char* feedtype[]={"actuator","sensor"}; //modify with the type of feeds i.e., actuator or sensor

int feedpin[]={3,8}; //modify with the pin numbers which you connected devices (actuator or sensor)

char* connectiontype[] = {"GPIO","zigbee"};

#define zigbeePort "/dev/ttyUSB0"  // comment this line if Zigbee is Used

#define bluetoothDiscover  0

#define wifiDiscover  0
