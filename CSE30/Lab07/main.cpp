#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Time.h"
using namespace std;

bool getTimeFromUser(Time& time){
	string input;
	getline (cin, input);

	string sHours;
	string sMinutes;
	string sSeconds;
	int counter = 0;
	
	sHours = input.substr(0, input.find(":", 0));
	for (int i = 0; i < sHours.size(); i++){
		if ((sHours[i] >= 'a' && sHours[i] <= 'z') || (sHours[i] >= 'A' && sHours[i] <= 'Z')){
			return false;
		}
	}
	time.setHours (atoi(sHours.c_str()));
	if (time.getHours() < 0 || time.getHours() >= 24){
		return false;
	}

	sMinutes = input.substr(input.find(":", 0) + 1, input.find(":", input.find(":", 0) + 1));
	for (int i = 0; i < sMinutes.size(); i++){
		if ((sMinutes[i] >= 'a' && sMinutes[i] <= 'z') || (sMinutes[i] >= 'A' && sMinutes[i] <= 'Z')){
			return false;
		}
	}
	time.setMinutes (atoi(sMinutes.c_str()));
	if (time.getMinutes() < 0 || time.getMinutes() >= 60){
		return false;
	}

	sSeconds = input.substr(input.find(":", input.find(":", 0) + 1) + 1);
	for (int i = 0; i < sSeconds.size(); i++){
		if ((sSeconds[i] >= 'a' && sSeconds[i] <= 'z') || (sSeconds[i] >= 'A' && sSeconds[i] <= 'Z')){
			return false;
		}
	}
	time.setSeconds (atoi(input.substr(input.find(":", input.find(":", 0) + 1) + 1).c_str()));
	if (time.getSeconds() < 0 || time.getSeconds() >= 60){
		return false;
	}
	if (sSeconds == "\0"){
		return false;
	}

	for (int i = 0; i < input.size(); i++){
		if (input.at(i) == ':'){
			counter++;
		}
	}
	if (counter != 2){
		return false;
	}
	return true;
}

void print24Hour(Time &time){
	cout << setfill('0') << setw(2) << time.getHours() << ":" << setfill('0') << setw(2) << time.getMinutes() << ":" << setfill('0') << setw(2) << time.getSeconds();
}

int main(){
	Time start;
	Time end;
	// take in the start time
	cout << "Enter the start time for the lecture (format is HH:MM:SS): ";

	if (getTimeFromUser(start) == true){

		cout << "Enter the end time for the lecture (Format is HH:MM:SS): ";

		if (getTimeFromUser(end) == true){
			cout << "The lecture starts at ";
			print24Hour(start);
			cout << " and ends at ";
			print24Hour(end);
		} else {
			cout << "The end time entered is invalid!\n";
		}
	} else {
		cout << "The start time entered is invalid!\n";
	}

	return 0;
}