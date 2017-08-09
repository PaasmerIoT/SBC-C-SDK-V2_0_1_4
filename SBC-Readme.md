# PAASMER-SBC

**Paasmer IoT SDK** for Single Board Computers Running Linux and cc3200

# Optional Requisites

In order to use the Zigbee the following is required.

* Single Board Computers.

* Arduino UNO Board.

* 2 ZigBee modules.

* XCTU Software installed on your system for ZigBee configuration. XCTU software

* Lastest version of Arduino IDE to installed on your computer. Arduino software

# Installation

* Download the SDK or clone it using the command below.
```
$ git clone github.com/PaasmerIoT/SBC-C-SDK-V2_0_1_4.git
$ cd SBC-C-SDK-V2_0_1_4
```
## ZigBee Configuration (Optional)

To establish, the ZigBee protocol the 2 ZigBee modules are to configured as a Coordinator and a Router. The ZigBee at the SBC side is to be configured as a Coordinator and the one at the Arduino side as a Router. Use XCTU software to Configure the ZigBee's as explained in the `ZigBEE_config.pdf` file.

The installation part is to be done in two parts, like

* Arduino  

* SBC 
 
## Arduino 

* Connect the ZigBee Router device to the Arduino UNO as give below

| Arduino   | XBee |
| --------- | -----|
| 5V        | 5V   |
| GND       | GND  |
| TX        | RX   |
| RX        | TX   |


* Open a new Sketch, Copy and Paste from the `ZigBee.ino` file in `<Arduino Sketch_DIR>/`.

* Connect the Arduino UNO board to your system, open the Arduino IDE and click on the `TOOLS` icon, select the `Board` as **Arduino/Genuino UNO** and select the port in which the board is connected in the `Port` option. 

* Also edit the `Config.h` in the Arduino Sketch similar to our `config.h` file in SBC. The code sample is as below,

```
#define devicename "Zigbee" //your device name

#define timePeriod 2 //change the time delay as you required for sending sensor values to paasmer cloud

char feedname[][10]={"Feed1","Feed2","Feed3","feed4","feed5","feed6"};

String feedtype[]={"sensor","sensor","sensor","actuator","actuator","actuator"};

String connectiontype[]= {"GPIO","GPIO","zigbee","GPIO","GPIO","zigbee"};

int feedpin[]={2,4,5,6,32,8};
```
* Save and Run the code in Arduino UNO.

## Single Board Computer Installation

* To connect the device to Paasmer IoT Platfrom, the following steps need to be performed.

```
$ sudo ./install.sh
```
This will install all required softwares.
* To register the device to the Paasmer IoT Platform, the following command need to be executed.

```
$ sudo ./paasmerDeviceRegistration.sh
```
This will ask for the device name. Give a unique device name for your device and that must be alphanumeric[a-z A-Z 0-9].

* Upon successful completion of the above command, the following commands need to be executed.
```
echo "-->  1) sudo su "
echo "-->  2) source ~/.bashrc "
echo "-->  3) PAASMER_THING "
echo "-->  4) PAASMER_POLICY "
echo "-->  5) sed -i 's/alias PAASMER/#alias PAASMER/g' ~/.bashrc "
echo "-->  6) exit "
$ exit
```

* Go to the diectory below.
```
$ cd samples/linux/subscribe_publish_sample/
```

* Edit the config.h file to include the user name(Email), device name, feed names and GPIO pin details.

```c
#define UserName "Email Address" //your user name in website

#define timePeriod 6 //change the time delay as you required for sending actuator values to paasmer cloud

char* feedname[]={"feed1","feed2","feed3","feed4","feed5",.....}; //feed names you use in the website

char* feedtype[]={"actuator","sensor","sensor","actuator","actuator",.....}; //modify with the type of feeds i.e., actuator or sensor

int feedpin[]={3,5,7,11,13,....}; //modify with the pin numbers which you connected devices (actuator or sensor)

char* connectiontype[] = {"GPIO","GPIO","zigbee",......}; //

//#define zigbeePort "/dev/ttyUSB0" //#Uncomment this line and edit with the zigbee connected serial port if used.
```
      
* Compile the code and generate output file.
```
$ sudo make
```

* Run the code using the command below.
```
$ sudo ./subscribe_publish_sample
```

* The device would now be connected to the Paasmer IoT Platfrom and publishing sensor values are specified intervals.

## Support

The support forum is hosted on the GitHub, issues can be identified by users and the Team from Paasmer would be taking up requests and resolving them. You could also send a mail to support@paasmer.co with the issue details for quick resolution.

## Note:

The Paasmer IoT SBC-C-SDK-V2_0_1_4 utilizes the features provided by AWS-IOT-SDK for C.
