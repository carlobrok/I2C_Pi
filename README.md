# I2C_Pi

Library for I2C communication to the arduino system of the robot **Kamel**.

Also including two .cpp example files for test purposes.

The program uses the **i2c-dev.h library**. It can be installed on Linux systems with `sudo apt-get install libi2c-dev`.
This library adds many functions to write and read from I2C-bus.

## Motor functions

### kamelI2Copen
```cpp
int kamelI2Copen(int devId);
```
**Description:** this function returns a file descriptor of the opened I2C device

  **parameters** | **possible values**
  -------------|--------------------
  devId        | I2C address of the device (e.g. 0x08)
</br>

### setMotorDirPwm
```cpp
int setMotorDirPwm(int &fd, uint8_t side, uint8_t direction, uint8_t pwm);
```
**Description:** this function sets the direction and pwm rate of the given motors by sending the values over I2C to the motor-arduino

  **parameters** | **possible values**
  ---------------|--------------------
  fd             | filedescriptor returned by kamelI2Copen
  side           | *MOTOR_LEFT/ MOTOR_RIGHT / MOTOR_BOTH*
  direction      | *MOTOR_FORWARD, MOTOR_BACKWARD*
  pwm | *0 - 255*
</br>

### setMotorDirPwmBoth
```cpp
int setMotorDirPwmBoth(int &fd, uint8_t direction_left, uint8_t pwm_left, uint8_t direction_right, uint8_t pwm_right);
```
**Description:** this function sets the direction and pwm rate of **both motors** by sending the values over I2C to the motor-arduino

  **parameters**                   | **possible values**
  ---------------------------------|--------------------
  fd                               | filedescriptor returned by kamelI2Copen
  direction_left / direction_right | *MOTOR_FORWARD, MOTOR_BACKWARD*
  pwm_left / pwm_right             | *0 - 255*
</br>

### setMotorState
```cpp
int setMotorState(int &fd, uint8_t side, uint8_t state);
```
**Description:** this function sets the **given motors** to the given state by sending the values over I2C to the motor-arduino
  
  **parameters** | **possible values**
  ---------------|--------------------
  fd             | filedescriptor returned by kamelI2Copen
  side           | *MOTOR_LEFT/ MOTOR_RIGHT / MOTOR_BOTH*
  state          | *MOTOR_OFF / MOTOR_FORWARD_NORMAL / MOTOR_BACKWARD_NORMAL*
  
## Sensor functions
  
### get_bit
```cpp
bool get_bit(int8_t byte, uint8_t bit_number);
```
**Description:** Returns the indexed bit of a byte. Index is from 0 - 7, the index 0 returns the rightmost bit.

### getSensorData
```cpp
int getSensorData(int &fd, bool (&digital_sensor_data)[8], uint16_t (&analog_sensor_data)[1]);
```
**Description:** Requests the sensor data from the Arduino, evaluates the received bytes, and writes the composite sensor values into the arrays. Note: only 8 digital and 1 analog sensor values are returned in this version.
