#include "KamelI2C.h"
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>


int kamelI2Copen(int devId) {
	const char *device ;
	int fd;

	//device = "/dev/i2c-0" ;
	device = "/dev/i2c-1" ;

	if((fd = open(device, O_RDWR)) < 0)
		return -1;

	if (ioctl (fd, I2C_SLAVE, devId) < 0)
		return -1;

	return fd;
}
