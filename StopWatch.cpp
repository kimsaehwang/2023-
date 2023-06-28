#include "StopWatch.h"

time_t StopWatch::getStart()
{
    return time_t();
}

time_t StopWatch::getEnd()
{
    return time_t();
}

StopWatch::StopWatch()
{
    startTime = endTime = clock();
}

StopWatch::~StopWatch()
{
}

void StopWatch::start()
{
    startTime = clock();
}

void StopWatch::stop()
{
    endTime = clock();
}

time_t StopWatch::getElapsedTime()
{
    double re;
    re = (double)(endTime - startTime);
    return re;
}
