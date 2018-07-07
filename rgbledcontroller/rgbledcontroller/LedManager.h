#pragma once
class LedManager
{
public:
	LedManager();
	~LedManager();
	void getColor();
	void setColor();
private:
	int r;
	int g;
	int b;
};

