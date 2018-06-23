#include "stdafx.h"
#include "SoundProcessor.h"
#include "WaveManager.h"
#include <vector>
#include <cmath>
#include <fstream>
#include "math.h"
#include "FftRealPair.h"

using namespace std;

SoundProcessor::SoundProcessor()
{
}


SoundProcessor::~SoundProcessor()
{
}

int SoundProcessor::GetFrequency(int frequency) {
	int l = wm->Record(200);
	short *b = (short*)wm->GetBuffer();
	for (int i = 20; i < 20 + 1024; i++)
	{
		real.push_back(b[i]);
		imag.push_back(0);
	}

	Fft::transform(real, imag);
	for (int i = 0; i < real.size(); i++)
	{
		result.push_back(floor(sqrt(pow(imag[i], 2) + pow(real[i], 2))));
	}
	int highest = (int)ceil(wm->GetSamplerate() / 15000.0);
	int lowest = (int)floor(wm->GetSamplerate() / 100.0);
	int maxindex = highest;
	double maxelement = result[highest];
	for (int i = highest + 1; i < lowest; i++)
	{
		if (result[i] > maxelement&&result[i] != 1000) {
			maxelement = result[i];
			maxindex = i;
		}
	}
	int frequency = wm->GetSamplerate()*maxindex / 1024;
	for (int i = 0; i < real.size(); i++)
	{
		resulttxt << result[i] << endl;

	}
	return frequency;
}

void SoundProcessor::TestTxt() {
	realtxt.open("real.txt");
	resulttxt.open("result.txt");
	for (int i = 0; i < real.size(); i++)
	{
		realtxt << real[i] << endl;
	}
}
