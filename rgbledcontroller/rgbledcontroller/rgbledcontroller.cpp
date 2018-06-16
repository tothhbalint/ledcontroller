// rgbledcontroller.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "WaveManager.h"
#include <vector>
#include <cmath>
#include "math.h"
#include "FftRealPair.h"



using namespace std;

int main()
{
	WaveManager *wm = new WaveManager();
	int l=wm->Record(100);
	LPSTR b=wm->GetBuffer();
	vector<double> real;
	vector<double> imag;
	vector<double> result;
	for (int i = 0; i < l; i++)
	{
		real.push_back(b[i]);
		imag.push_back(0);
	}
	Fft::transform(real,imag);
	for (int i = 0; i < l; i++)
	{
		result.push_back(floor(sqrt(pow(imag[i],2) + pow(real[i],2))));
	}
	int highest = (int)ceil(wm->GetSamplerate() / 15000.0);
	int lowest = (int)floor(wm->GetSamplerate() / 60.0);
	int maxindex=highest;
	double maxelement=result[highest];
	for (int i = highest+1; i < lowest; i++)
	{
		if (result[i] > maxelement) {
			maxelement = result[i];
			maxindex = i;
		}
	}
	int frequency=wm->GetSamplerate()/maxindex;
	getchar();
	
}








