#include <iostream>
#include <string>
using namespace std;

#include "student.h"


// CONSTRUCTOR ----------------------------------------------------------------------------------------------------
student::student() {	// Default constructor
	stdStudentID = "No Student ID";
	stdFirstName = "No First Name";
	stdLastName = "No Last Name";
	stdEmailAddress = "No Email Address";
	stdAge = 0;
	stdDegreeProgram = DegreeProgram::NONE;
}

student::student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int completionDays[3], DegreeProgram degreeProgram) {
	stdStudentID = studentID;
	stdFirstName = firstName;
	stdLastName = lastName;
	stdEmailAddress = emailAddress;
	stdAge = age;
	stdCompletionDays[0] = completionDays[0];
	stdCompletionDays[1] = completionDays[1];
	stdCompletionDays[2] = completionDays[2];
	stdDegreeProgram = degreeProgram;
}

student::~student() {}; // DESTRUCTOR

// SET FUNCTIONS --------------------------------------------------------------------------------------------------
void student::SetStudentID(string studentID) { stdStudentID = studentID; }

void student::SetFirstName(string firstName) { stdFirstName = firstName; }

void student::SetLastName(string lastName) { stdLastName = lastName; }

void student::SetEmailAddress(string emailAddress) { stdEmailAddress = emailAddress; }

void student::SetAge(int age) { stdAge = age; }

void student::SetCompletionDays(int* completionDays) {
	stdCompletionDays[0] = completionDays[0];
	stdCompletionDays[1] = completionDays[1];
	stdCompletionDays[2] = completionDays[2];
}

void student::SetDegreeProgram(DegreeProgram degreeProgram) { stdDegreeProgram = degreeProgram; }


// GET FUNCTIONS ---------------------------------------------------------------------------------------------------
string student::GetStudentID() const { return stdStudentID; }

string student::GetFirstName() const { return stdFirstName; }

string student::GetLastName() const { return stdLastName; }

string student::GetEmailAddress() const { return stdEmailAddress; }

int student::GetAge() const { return stdAge; }

int* student::GetCompletionDays() const { return (int*)stdCompletionDays; }

DegreeProgram student::GetDegreeProgram() const { return stdDegreeProgram; }


// Print information of individual student
void student::print() const {
	
	// Convert from DegreeProgram enum to associated string name
	string stdDegreeString;
	if (stdDegreeProgram == DegreeProgram::SECURITY) {
		stdDegreeString = "SECURITY";
	}
	else if (stdDegreeProgram == DegreeProgram::NETWORK) {
		stdDegreeString = "NETWORK";
	}
	else if (stdDegreeProgram == DegreeProgram::SOFTWARE) {
		stdDegreeString = "SOFTWARE";
	}
	else {
		stdDegreeString = "NONE";
	}

	cout << stdStudentID << "\t" << stdFirstName << "\t" << stdLastName	<< "\t" << stdAge
		<< "\t {" << stdCompletionDays[0] << "," << stdCompletionDays[1] << "," << stdCompletionDays[2] << "} \t"
		<< stdDegreeString << endl;

}