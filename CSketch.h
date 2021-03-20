////////////////////////////////////////////////////////////////
// CSketch.h
// Definintion of class CSketch
// Member function are defined in CSketch.cpp
// Created Feb 09, 2021 by Laurel Kinahan 
////////////////////////////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "CControl.h"
#include "CBase4618.h"
#include <Windows.h>
#include <iostream>

using namespace std;
#define RGB_RED 39
#define RGB_GRN 38
#define RGB_BLU 37
#define LED_ON 255
#define LED_OFF 0
#define BUTTON_1 33
#define BUTTON_2 32
#define JOY_X 2
#define JOY_Y 26

enum TYPE
{
	DIGITAL = 0, ///< 0
	ANALOG, ///< 1
	SERVO ///< 2
};

enum COLOR
{
	RED, ///< 0
	GRN, ///< 1
	BLU ///< 2
};

enum SPECS
{
	DIMENSION_X = 1280,
	DIMENSION_Y = 720
};
/*
enum ACCEL
{
	ACCEL1MIN = 0,
	ACCEL1MAX = 400,
	ACCEL2MIN = 630,
	ACCEL2MAX = 1024
};
*/

/**
* @brief Etch-A-Sketch class
* @details This Class uses serial communication and a set of functions that inherits from CBase4618.h and draws on the MSP432 screen using the joystick
* @author Laurel Kinahan
* @date Febraury 9 2021
*/
class CSketch : public CBase4618	//< Inherited class access
{
private:

	int count = 0; ///< Tracks amount of times button has been pressed for cycling colors
	int prev_button_press = 0; ///< Tracks whether button is being held
	int current_button_press = 1; ///< Tracks whether button is being held
	bool _reset;	///< Private variable to track reset condition (TRUE - reset, FALSE - no reset)

	cv::Scalar _color = (LED_ON, LED_OFF, LED_OFF); ///< Private variable to track drawing color
	cv::Point curr_pt; ///< Tracks movement of the joystick
	cv::Point prev_pt; ///< Tracks movement of the joystick

public:
	/**
	* @brief constructor for CSketch - initializes com port and canvas
	* @param None
	* @return None
	*/
	CSketch( int comport = 3);

	/**
	* @brief destructor for CSketch - destroys object when program is closed
	* @param None
	* @return None
	*/
	~CSketch();

	/**
	* @brief Updates internal variables
	* @param None
	* @return None
	*/
	void update();

	/**
	* @brief Draws on the created image
	* @param None
	* @return None
	*/
	void draw();

	/**
	* @brief accelerometer to clear LCD screen
	* @param None
	* @return Accel value
	*/
	void readAccel();

	/**
	* @brief changes the color of the MSP432 LED
	* @param None
	* @return None
	*/
	void setLEDColor();

	/**
	* @brief checks if button is pressed
	* @param None
	* @return TRUE if reset, FALSE if not
	*/
	void resetCanvas();

	/**
	* @brief Fixes range from 0->100 to -20->20
	* @param Int of input of ADC value from 0->100
	* @return None
	*/
	int canvasFixRangeX(int input);

	/**
	* @brief Fixes range from 0->100 to -20->20
	* @param Int of input of ADC value from 0->100
	* @return None
	*/
	int canvasFixRangeY(int input);
};