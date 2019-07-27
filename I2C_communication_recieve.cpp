#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "KamelI2C.h"


using namespace std;

int main() {

	int sensor_fd = kamelI2Copen(0x09);

	if(sensor_fd == -1) {
		cout << "Error in opening i2c bus to sensor arduino" << endl;
		return -1;
	}

	uint8_t in_data[2];
	bool dig_sensors[8];
	uint16_t analog_ir[1];

	while(1) {

		getSensorData(sensor_fd, dig_sensors, analog_ir);

		cout << "Digital Sensors: " << endl;
		for(int i = 0; i < 8; i++) {
			cout << i << ": " << dig_sensors[i] << endl;
		}
		cout << endl;
		cout << "Analog Sensor: " << analog_ir[0] << endl;

		this_thread::sleep_for(chrono::milliseconds(500));

	}
}
