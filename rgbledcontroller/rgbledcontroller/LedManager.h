#pragma once
class LedManager
{
public:
	LedManager();
	~LedManager();
	void getColor();
	void HSVtoRGB();
	void setColor();
private:
	int hue;
	int saturation;
	int value;
	
	int red;
	int green;
	int blue;
};

