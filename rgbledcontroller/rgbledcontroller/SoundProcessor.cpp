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

int SoundProcessor::GetFrequency(short * b,int l,int samplerate) {
	vector<double> real;
	vector<double> imag;
	const int samples = 512;
	for (int i = 20; i < 20 + samples; i++)
	{
		real.push_back(b[i]);
		imag.push_back(0);
	}

	Fft::transform(real, imag);
	for (int i = 0; i < real.size(); i++)
	{
		result.push_back(floor(sqrt(pow(imag[i], 2) + pow(real[i], 2))));
	}
	int highest = (int)ceil(samplerate / 15000.0);
	int lowest = (int)floor(samplerate / 150.0);
	int maxindex = highest;
	double maxelement = result[highest];
	for (int i = highest + 1; i < lowest; i++)
	{
		if (result[i] > maxelement&&result[i] != 1000) {
			maxelement = result[i];
			maxindex = i;
		}
	}
	int frequency = samplerate*maxindex / samples;
	real.clear();
	imag.clear();
	result.clear();
	return frequency;
}

