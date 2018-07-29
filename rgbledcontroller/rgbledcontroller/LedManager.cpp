#include "stdafx.h"
#include "LedManager.h"
#include "SerialPort.h"
#include <iostream>


LedManager::LedManager()
{
}


LedManager::~LedManager()
{
}

void LedManager::getColor() {
	this->HSVtoRGB;
}

void LedManager::HSVtoRGB() {
}

void LedManager::setColor() {
	this->getColor();
}