// rgbledcontroller.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "WaveManager.h"
#include <vector>
#include <cmath>
#include <fstream>
#include "math.h"
#include "FftRealPair.h"
#include "SoundProcessor.h"



using namespace std;

int main()
{
	WaveManager *wm = new WaveManager();
	int l=wm->Record(200);
	short *b=(short*)wm->GetBuffer();
	vector<double> real;
	vector<double> imag;
	vector<double> result;
	ofstream realtxt;
	ofstream imagtxt;
	realtxt.open("real.txt");
	imagtxt.open("imag.txt");
	for (int i = 20; i < 20+1024; i++)
	{
		real.push_back(b[i]);
		imag.push_back(0);
	}

	
	Fft::transform(real,imag);
	for (int i = 0; i < real.size(); i++)
	{
		result.push_back(floor(sqrt(pow(imag[i],2) + pow(real[i],2))));
	}
	int highest = (int)ceil(wm->GetSamplerate() / 15000.0);
	int lowest = (int)floor(wm->GetSamplerate() / 100.0);
	int maxindex=highest;
	double maxelement=result[highest];
	for (int i = highest+1; i < lowest; i++)
	{
		if (result[i] > maxelement&&result[i]!=1000) {
			maxelement = result[i];
			maxindex = i;
		}
	}
	int frequency=wm->GetSamplerate()*maxindex/1024;
	for (int i = 0; i < real.size(); i++)
	{
		imagtxt << result[i] << endl;
		
	}
	imagtxt << endl;
	getchar();
	
}








