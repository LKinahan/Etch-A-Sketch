////////////////////////////////////////////////////////////////
// CBase4618.h
// Definintion of class CBase
// Member function are defined in CCBase.cpp
// Created Feb 09, 2021 by Laurel Kinahan 
////////////////////////////////////////////////////////////////
#pragma once

#include "stdafx.h"

#include "CControl.h"
#include <Windows.h>
#include <iostream>

using namespace std;

/**
* @brief Generic class to be used for inheriting funtions and object data
* This class stores parent information for child classes to use
* In this project it is used by CSketch
* @author Laurel Kinahan
*/

class CBase4618
{
private:

public:
	CControl controller; ///< Matrix canvas 
	cv::Mat mCanvas; ///< CControl gamepad drawing tool
	
	/** 
	* @brief This is the class constructor
	* @param None
	* @return None
	*/
	CBase4618();

	/** 
	* @brief This is the class destructor
	* @param None
	* @return None
	*/	
	~CBase4618();

	/**
	* @brief Updates internal variables
	* @param none
	* @return none
	*/
	virtual void update();

	/**
	* @brief Draws on the created image
	* @param None
	* @return None
	*/
	virtual void draw();

	/**
	* @brief Initializes the COM port
	* @param nothing to receive
	* @return nothing to return
	*/
	void run();
};

