// rgbledcontroller.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "SoundProcessor.h"
#include "WaveManager.h"


using namespace std;

int main()
{
	WaveManager *wm = new WaveManager();
	SoundProcessor *sp = new SoundProcessor();
	char q;
	while (true) {
		int length = wm->Record(100);
		short * buffer = wm->GetBuffer();
		int samplerate = wm->GetSamplerate();
		int freq = sp->GetFrequency(buffer, length, samplerate);
		cout << freq << endl;
	}
}








