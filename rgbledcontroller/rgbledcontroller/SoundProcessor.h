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

private:
	vector<double> result;
	int dominantFrequency;
	int dominantAmplitude;
};

