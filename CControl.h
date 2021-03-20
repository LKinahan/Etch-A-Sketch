////////////////////////////////////////////////////////////////
// CControl.h
// Definintion of class CControl
// Member function are defined in CControl.cpp
// Created Jan 29, 2021 by Laurel Kinahan 
////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include "Serial.h"

/**
*
* @brief Control Class
*
* This class is meant to contain all information and
* functions related to serial communication with the
* embedded system.
*
* @author Laurel Kinahan
*
*/
class CControl {
private:
	Serial _com; ///< Serial port object
public:

	/**
	* @brief Initializes the COM port
	* @param comport The value of the comport to be used
	* @return nothing to return
	*/
	void init_com(int comport);

	/**
	* @brief Enables accessing the current state of an I/O pin
	* @param type The type of data to be received
	* @param channel The channel used to receive the data
	* @param &result The current result of the data
	* @return true if COM was successful, false if COM was unsuccessful
	*/
	bool get_data(int type, int channel, int& result);

	/**
	* @brief Enables setting the data state of an I/O pin
	* @param type The type of data to be sent
	* @param channel The channel used to set the data
	* @param val The value of the data
	* @return true if COM was successful, false if COM was unsuccessful
	*/
	bool set_data(int type, int channel, int val);

	/**
	* @brief Enables access to the position of the joystick
	* @param nothing
	* @return nothing to return
	*/
	float get_analog(int channel);

	/**
	* @brief Enables access to the push state of a button
	* @param nothing
	* @return nothing to return
	*/
	void get_digital(int channel);

	/**
	* @brief Enables access to a debounced button
	* @param nothing
	* @return nothing to return
	*/
	bool get_button(int channel);

	/**
	* @brief Enables access to the servo's angle
	* @param nothing
	* @return true if button is pushed
	*/
	void get_servo(void);
};