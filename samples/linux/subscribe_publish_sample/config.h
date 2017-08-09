#include "../../../deviceName.h"
#define UserName "padmanabham.pakki@gmail.com" //your user name in website

#define timePeriod 6 //change the time delay as you required for sending actuator values to paasmer cloud

char* feedname[]={"feed1","feed5"}; //feed names you use in the website

char* feedtype[]={"actuator","sensor"}; //modify with the type of feeds i.e., actuator or sensor

int feedpin[]={3,8}; //modify with the pin numbers which you connected devices (actuator or sensor)

char* connectiontype[] = {"GPIO","zigbee"};

#define zigbeePort "/dev/ttyUSB0"
