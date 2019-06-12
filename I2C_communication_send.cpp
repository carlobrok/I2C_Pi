#include <iostream>
#include <thread>
#include <wiringPiI2C.h>


using namespace std;

int main() {

	int arduino_fd = wiringPiI2CSetup(0x08);

	if(arduino_fd == -1) {
		cout << "Error in opening i2c bus to arduino" << endl;
		return -1;
	}

	while(1) {

		cout << wiringPiI2CWrite (arduino_fd, 1) << endl;

		std::this_thread::sleep_for(1s);
	}
}
