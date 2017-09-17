#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

struct Time {
	int hours;
	int minutes;
	int seconds;
	string line;
}start, end;

bool getTimeFromUser(Time& time){
	string sHours;
	string sMinutes;
	string sSeconds;
	int counter = 0;
	
	sHours = time.line.substr(0, time.line.find(":", 0));
	for (int i = 0; i < sHours.size(); i++){
		if ((sHours[i] >= 'a' && sHours[i] <= 'z') || (sHours[i] >= 'A' && sHours[i] <= 'Z')){
			return false;
		}
	}
	time.hours = atoi(sHours.c_str());
	if (time.hours < 0 || time.hours >= 24){
		return false;
	}

	sMinutes = time.line.substr(time.line.find(":", 0) + 1, time.line.find(":", time.line.find(":", 0) + 1));
	for (int i = 0; i < sMinutes.size(); i++){
		if ((sMinutes[i] >= 'a' && sMinutes[i] <= 'z') || (sMinutes[i] >= 'A' && sMinutes[i] <= 'Z')){
			return false;
		}
	}
	time.minutes = atoi(sMinutes.c_str());
	if (time.minutes < 0 || time.minutes >= 60){
		return false;
	}

	sSeconds = time.line.substr(time.line.find(":", time.line.find(":", 0) + 1) + 1);
	for (int i = 0; i < sSeconds.size(); i++){
		if ((sSeconds[i] >= 'a' && sSeconds[i] <= 'z') || (sSeconds[i] >= 'A' && sSeconds[i] <= 'Z')){
			return false;
		}
	}
	time.seconds = atoi(time.line.substr(time.line.find(":", time.line.find(":", 0) + 1) + 1).c_str());
	if (time.seconds < 0 || time.seconds >= 60){
		return false;
	}
	if (sSeconds == "\0"){
		return false;
	}

	for (int i = 0; i < time.line.size(); i++){
		if (time.line.at(i) == ':'){
			counter++;
		}
	}
	if (counter != 2){
		return false;
	}
	return true;
}

void print24Hour(Time start, Time end){
	cout << "The lecture starts at ";
	cout << setfill('0') << setw(2) << start.hours << ":";
	cout << setfill('0') << setw(2) << start.minutes << ":";
	cout << setfill('0') << setw(2) << start.seconds;
	cout << " and ends at ";
	cout << setfill('0') << setw(2) << end.hours << ":";
	cout << setfill('0') << setw(2) << end.minutes << ":";
	cout << setfill('0') << setw(2) << end.seconds;
}

int main(){
	cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
	getline (cin, start.line);
	if (getTimeFromUser(start) == true){
		cout << "Enter the end time for the lecture (format is HH:MM:SS): " << endl;
		getline (cin, end.line);

		if (getTimeFromUser(end) == true){
			print24Hour(start, end);
		}else{
			cout << "The end time entered is invalid!\n";
		}
	}else{
		cout << "The start time entered is invalid!\n";
	}

	return 0;
}