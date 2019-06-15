#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <thread>
#include "KamelI2C.h"


using namespace std;



int main() {

	int arduino_fd = kamelI2Copen(0x08);

	if(arduino_fd == -1) {
		cout << "Error in opening i2c bus to arduino" << endl;
		return -1;
	}

	while(1) {

		int data[3];

		std::this_thread::sleep_for(2s);

	}
}
