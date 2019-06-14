#include <iostream>
#include <thread>
//#include <wiringPiI2C.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

using namespace std;

int arduinoI2Copen(int devId) {
//	int rev = piGpioLayout();
	const char *device ;
	int fd;

//	if (rev == 1)
//		device = "/dev/i2c-0" ;
//	else
	device = "/dev/i2c-1" ;

	if((fd = open(device, O_RDWR)) < 0) {
		return -1;
	}

	if (ioctl (fd, I2C_SLAVE, devId) < 0)
		return -1;

	return fd;
}


int main() {

	int arduino_fd = arduinoI2Copen(8);

	if(arduino_fd == -1) {
		cout << "Error in opening i2c bus to arduino" << endl;
		return -1;
	}

	while(1) {

		//cout << wiringPiI2CRead(arduino_fd) << endl;

		std::this_thread::sleep_for(2s);

	}
}
