#pragma once
#include <ctime>

class StopWatch
{
private:
	int startTime, endTime;
public:
	time_t getStart();
	time_t getEnd();

	StopWatch();
	~StopWatch();
	void start();
	void stop();
	time_t getElapsedTime();
};
