#include "Time.h"

Time::Time(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::~Time(){}

void Time::setHours(int hr){
	hours = hr;
}

void Time::setMinutes(int min){
	minutes = min;
}

void Time::setSeconds(int sec){
	seconds = sec;
}

int Time::getHours(){
	return hours;
}

int Time::getMinutes(){
	return minutes;
}

int Time::getSeconds(){
	return seconds;
}