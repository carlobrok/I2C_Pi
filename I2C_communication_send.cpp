#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <thread>
#include <linux/i2c-dev.h>
#include "KamelI2C.h"

using namespace std;

int main() {

	int arduino_fd = kamelI2Copen(0x08);

	if(arduino_fd == -1) {
		cout << "Error in opening i2c bus to arduino" << endl;
		return -1;
	}

	while(1) {
		//cout << endl;
		uint8_t motor = rand() % 2;
		//uint16_t combined = 0;
		//combined += motor;
		//cout << (int)motor << "  " << bitset<8>(motor) << "  " << bitset<16>(combined) << endl;
		uint8_t direction = rand() % 2;
		//combined += direction << 1;
		//cout << (int)motor << "  " << bitset<8>(direction) << "  " << bitset<16>(combined) << endl;
		uint8_t value = rand() % 255;
		//combined += value << 2;
		//cout << (int)motor << "  " << bitset<8>(value) << "  " << bitset<16>(combined) << endl;
		////uint16_t binary_value = motor << 7;
		////binary_value += direction << 6;
		////binary_value += value << 5;
		///*cout <<    wiringPiI2CWrite (arduino_fd, binary_value)/* << endl*/;
		////cout << endl;
		////cout << "Motor: " << (int)motor << "  " << bitset<8>(motor) << endl;
		////cout << "Direction: " << (int)direction << "  " << bitset<8>(direction) << endl;
		////cout << "Value: " << (int)value << "  " << bitset<8>(value) << endl;
		////cout << "Zusammengesetzter Wert: " << binary_value << "  " << bitset<16>(binary_value) << endl;
		std::this_thread::sleep_for(0.075s);

		uint8_t data[3] = {motor, direction, value};
		cout << (int)data[0] << " " << (int)data[1] << " " << (int)data[2] << endl;
		i2c_smbus_write_block_data(arduino_fd, 0, 3, data);
	}
}

