#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Time{
	int hour;
	int minutes;
	int seconds;
};

struct Course{
	string name;
	int credits;
	bool majorRequirement;
	double avgGrade;
	string days;
	Time startTime;
	Time endTime;
};

bool getTimeFromUser (Time& time, string input) {

	string hour;
	string seconds;
	string minutes;
	string find=":";
	int ind=0;

	hour=input.substr(0,input.find(":"));
	minutes=input.substr(input.find(":")+1);
	minutes=input.find((":")-input.find_last_of(":"));	
	seconds=input.substr( (input.find(":")+1)-(input.find(":")-input.find_last_of(":")));
	seconds=input.length()-input.find(":");
	time.hour = atoi(hour.c_str());
	time.minutes = atoi(minutes.c_str());
	time.seconds = atoi(seconds.c_str());

	for (int i=0; i<input.length(); i++) {
		if(input.substr(i,1)==find) {
			ind++;
		}
	}
	
	if (ind !=2){
		return false;
	}
	
	if (input.substr(input.length()-4,2)=="am" || input.substr(input.length()-4,2)=="pm") {
	
		return false;
	}
	if (input.substr(input.length()-4,2)=="AM" || input.substr(input.length()-4,2)=="PM") {
	
		return false;
	}
	if (time.hour > 23 || time.hour < 0) {
	
		return false;
	}
	if (time.minutes > 59 || time.minutes < 0) {
	
		return false;
	}
	if (time.seconds > 59 || time.seconds < 0) {
		
		return false;
	}
	return true;
}

int print24Hour(Time &sTime, Time &eTime) {
	if (sTime.hour>12){
		sTime.hour -=12;
		cout << "Lecture time: " << sTime.hour << ":" << setfill('0') << setw(2) << sTime.minutes << ":" << setfill('0') << setw(2) << sTime.seconds << " pm";
	}
	else if (sTime.hour == 0){
		sTime.hour=12;
		cout << "Lecture Time: " << sTime.hour << ":" << setfill('0') << setw(2) << sTime.minutes << ":" << setfill('0') << setw(2) << sTime.seconds << " am";
	}
	else{
		cout << "Lecture Time: " << sTime.hour << ":" << setfill('0') << setw(2) << sTime.minutes << ":" << setfill('0') << setw(2) << sTime.seconds << " am";
	}
	if (eTime.hour>12){
		eTime.hour-=12;
		cout << " - " << eTime.hour << ":" << setfill('0') << setw(2) << eTime.minutes << ":" << setfill('0') << setw(2) << eTime.seconds << " pm" << endl;
	}
	else if (eTime.hour == 0){
		eTime.hour=12;
		cout << " - " << eTime.hour << ":" << setfill('0') << setw(2) << eTime.minutes << ":" << setfill('0') << setw(2) << eTime.seconds << " am" << endl;
	}
	else{
		cout << " - " << eTime.hour << ":" << setfill('0') << setw(2) << eTime.minutes << ":" << setfill('0') << setw(2) << eTime.seconds << " am" << endl;
	}
}	

int main(){
	bool s, e;
	string start;
	string end;
	string avg;
	string credit;
	string major;
	string line;

	Time startTime, endTime;
	
	ifstream lab_6("in.txt");

    getline(lab_6, line);
    int num_courses = atoi(line.c_str());
    
    Course my_courses[num_courses];
    for (int i=0; i<num_courses; i++){
        getline (lab_6, my_courses[i].name);
		getline (lab_6, credit);
		my_courses[i].credits=atoi(credit.c_str());
		
		getline (lab_6, major);
				
		if (major == "1"){
			my_courses[i].majorRequirement = true;
		} else {
			my_courses[i].majorRequirement = false;
		}

		getline (lab_6, avg);
		my_courses[i].avgGrade=atof(avg.c_str());
		
		getline (lab_6, my_courses[i].days);
		
		getline (lab_6, start);
		s=getTimeFromUser(my_courses[i].startTime, start);
		getline (lab_6, end);
		e=getTimeFromUser(my_courses[i].endTime, end); 
	}

	lab_6.close();

	cout << "----------------------------" << endl; 
	cout << "SCHEDULE OF STUDENT" << endl;
	cout << "----------------------------" << endl;

	for (int i=0; i<num_courses;i++){
		cout << "COURSE " << i+1 << ": " << my_courses[i].name << endl; 
		cout << "Note: ";
		
		if (my_courses[i].majorRequirement == 1){
			cout <<  "This course is a major requirement!" << endl;
		} else {
			cout << "This course is not a major requirement..." << endl;
		}
		
		cout << "Number of Credits: " << my_courses[i].credits << endl;
		cout << "Days of Lectures: " << my_courses[i].days << endl;
		
		print24Hour(my_courses[i].startTime, my_courses[i].endTime);
		cout << "Stat: on average students get " << my_courses[i].avgGrade << "% in this course." << endl;
		cout << "-----------------------"<< endl;
		        
    }
}