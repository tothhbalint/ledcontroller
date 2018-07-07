#pragma once

#include <vector>
#include <fstream>

using namespace std;

class SoundProcessor
{
public:
	SoundProcessor();
	~SoundProcessor();
	int GetFrequency(short *,int,int);
	int GetAmplitude();

private:
	vector<double> result;
	int dominantFrequency;
	int dominantAmplitude;
};

