#pragma once

#include "stdafx.h"
#include "Windows.h"
#include <iostream>


class WaveManager
{
public:
	WaveManager();
	~WaveManager();
	int Record(int length);
	short * GetBuffer();
	int GetSamplerate();
private:
	WAVEFORMATEX format; //the format to use at recording
	WAVEHDR buffer;
	HWAVEIN handle;
};
