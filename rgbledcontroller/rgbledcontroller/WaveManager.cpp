#include "stdafx.h"
#include "WaveManager.h"


using namespace std;

WaveManager::WaveManager()
{
	format.wFormatTag = WAVE_FORMAT_PCM;
	format.nChannels = 1;
	format.nSamplesPerSec = 48000;
	format.wBitsPerSample = 16;
	format.nBlockAlign = format.nChannels*format.wBitsPerSample/8;
	format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;
	format.cbSize = 0;
}

int WaveManager::Record(int length) {
	waveInOpen(&handle, 0, &format, 0, 0, WAVE_FORMAT_DIRECT| CALLBACK_NULL);
	buffer.lpData = NULL;
	buffer.dwBufferLength = 0;
	buffer.dwBytesRecorded = 0;
	buffer.dwUser = 0;
	buffer.dwFlags = 0;
	buffer.dwLoops = 0;
	buffer.dwBufferLength = format.nAvgBytesPerSec*length / 1000;
	buffer.lpData = (LPSTR)GlobalAlloc(0, buffer.dwBufferLength);
	waveInPrepareHeader(handle, &buffer, sizeof(buffer));
	waveInAddBuffer(handle, &buffer, sizeof(buffer));
	waveInStart(handle);
	Sleep(length);
	waveInStop(handle);
	waveInClose(handle);
	return buffer.dwBytesRecorded;
}

LPSTR WaveManager::GetBuffer() {
	return buffer.lpData;
}

int WaveManager::GetSamplerate() {
	return format.nSamplesPerSec;
}

WaveManager::~WaveManager()
{
  
}

