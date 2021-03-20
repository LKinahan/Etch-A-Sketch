////////////////////////////////////////////////////////////////
// CSketch.cpp for Lab 4 - ELEX 4618
// Member function definitions for class CSketch that 
//     
// Created Feb 09, 2021 by Laurel Kinahan 
////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "CSketch.h"
#include "CBase4618.h"
#include <string>

using namespace std;

CControl controller;

CSketch::CSketch(int comport)
{
	controller.init_com(comport);
	curr_pt = cv::Point(DIMENSION_X * controller.get_analog(JOY_X), -1 * (DIMENSION_Y * controller.get_analog(JOY_Y)) + DIMENSION_Y);
	mCanvas = cv::Mat::zeros(DIMENSION_Y, DIMENSION_X, CV_8UC3);
}


CSketch::~CSketch()
{
	controller.set_data(DIGITAL, RGB_RED, LED_OFF);
	controller.set_data(DIGITAL, RGB_GRN, LED_OFF);
	controller.set_data(DIGITAL, RGB_BLU, LED_OFF);
}


void CSketch::resetCanvas()
{
	controller.get_button(BUTTON_1);
}


void CSketch::readAccel()
{
	int fill;
	int accelmax = 90;
	int accelmin = 0;

	cv::Point accel;
	enum { accely = 13, accelx };

	//controller.get_analog(accelx, fill, accel.x);
	//controller.get_analog(accely, fill, accel.y);

	if (accel.x > accelmax || accel.y > accelmax || accel.x < accelmin || accel.y < 0)
	{
	_reset = FALSE;
	}
}

void CSketch::draw(void)
{
#define LINE_THICKNESS 5

	if (_reset == TRUE)
	{
		_reset = FALSE;
		mCanvas = cv::Mat::zeros(DIMENSION_Y, DIMENSION_X, CV_8UC3);
		
	}
	else
	{
		cv::line(mCanvas, curr_pt, prev_pt, _color, LINE_THICKNESS);
		cv::imshow("Etch-A-Sketch", mCanvas);
	}
	cv::waitKey(1);
}

void CSketch::update()
{
	if (controller.get_button(BUTTON_1))
		_reset = TRUE;

	prev_pt = curr_pt;
	prev_button_press = current_button_press;

	curr_pt = cv::Point(DIMENSION_X * controller.get_analog(JOY_X), (-1 * (DIMENSION_Y * controller.get_analog(JOY_Y)) + DIMENSION_Y));
	curr_pt = cv::Point((curr_pt.x * 1.5) - DIMENSION_X / 4, (curr_pt.y * 1.5) - DIMENSION_Y / 4);

	current_button_press = controller.get_button(BUTTON_2);

	if (curr_pt.y > DIMENSION_Y)
		curr_pt.y = DIMENSION_Y - 1;
	if (curr_pt.y < 0)
		curr_pt.y = 0;
	if (curr_pt.x > DIMENSION_X)
		curr_pt.x = DIMENSION_X - 1;
	if (curr_pt.x < 0)
		curr_pt.x = 0;

	if (current_button_press == 0 && prev_button_press == 1)
	{
		if (count % 3 == RED)
		{
			_color = (cv::Scalar(LED_OFF, LED_OFF, LED_ON));
			controller.set_data(DIGITAL, RGB_RED, LED_ON);
			controller.set_data(DIGITAL, RGB_BLU, LED_OFF);
			controller.set_data(DIGITAL, RGB_GRN, LED_OFF);
		}
		else if (count % 3 == GRN)
		{
			_color = (cv::Scalar(LED_ON, LED_OFF, LED_OFF));
			controller.set_data(DIGITAL, RGB_RED, LED_OFF);
			controller.set_data(DIGITAL, RGB_BLU, LED_ON);
			controller.set_data(DIGITAL, RGB_GRN, LED_OFF);
		}
		else if (count % 3 == BLU)
		{
			_color = (cv::Scalar(LED_OFF, LED_ON, LED_OFF));
			controller.set_data(DIGITAL, RGB_RED, LED_OFF);
			controller.set_data(DIGITAL, RGB_BLU, LED_OFF);
			controller.set_data(DIGITAL, RGB_GRN, LED_ON);
		}
		count++;
	}
}
