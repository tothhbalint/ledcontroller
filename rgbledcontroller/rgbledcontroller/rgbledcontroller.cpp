// rgbledcontroller.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Windows.h"
#include <MMSystem.h>
#include "IOstream"




using namespace std;

int main()
{
	int samplerate = 48000;
	const int NUMPTS = 48000 * 2;
	HWAVEIN phwi;
	LPTSTR fault;
	short int pitch;
	short int waveindata[NUMPTS];
	int avg;
	float sum = 0.0;
	DWORD volume;

	WAVEFORMATEX format;
	format.wFormatTag = WAVE_FORMAT_PCM;
	format.nChannels = 1;
	format.nSamplesPerSec = samplerate;
	format.nAvgBytesPerSec = samplerate * 2;
	format.nBlockAlign = 2;
	format.wBitsPerSample = 16;
	format.cbSize = 0;

	WAVEHDR buffer;
	buffer.lpData = (LPSTR)waveindata;
	buffer.dwBufferLength = NUMPTS / 10;
	buffer.dwBytesRecorded = 0;
	buffer.dwUser = 0;
	buffer.dwFlags = 0;
	buffer.dwLoops = 0;

	waveInOpen(&phwi, 0, &format, 0, 0, WAVE_FORMAT_DIRECT);
	waveInPrepareHeader(phwi, &buffer, sizeof(buffer));
	waveInAddBuffer(phwi, &buffer, sizeof(buffer));
	waveInStart(phwi);
	while (true) {
		waveInAddBuffer(phwi, &buffer, sizeof(buffer));
		cout << waveindata[4799] << endl;

	}
	waveInClose(phwi);




}




