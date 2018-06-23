#pragma once


class SoundProcessor
{
public:
	SoundProcessor();
	~SoundProcessor();
	int GetFrequency(int);
	void TestTxt();
private:
	vector<double> real;
	vector<double> imag;
	vector<double> result;
	ofstream realtxt;
	ofstream resulttxt;
	WaveManager *wm = new WaveManager();
};

