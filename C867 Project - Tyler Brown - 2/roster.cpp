#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "roster.h"

roster::roster() {}						// CONSTRUCTOR

roster::~roster() {						// DESTRUCTOR
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) { // Check for nullptr at requested array slot
			delete classRosterArray[i];
		}
	}
}

// Parse information provided by comma delimited table -> calls "add" function
void roster::parse(string row) {
		size_t rhs = row.find(",");
		rosStudentID = row.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosFirstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosLastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosEmailAddress = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosAge = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosCompletionDays1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosCompletionDays2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosCompletionDays3 = stoi(row.substr(lhs, rhs - lhs));

		int rosCompletionDays[3] = { rosCompletionDays1,rosCompletionDays2,rosCompletionDays3 };

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		rosStrDegreeProgram = row.substr(lhs, rhs - lhs);

		DegreeProgram psDegreeProgram;
		if (rosStrDegreeProgram == "SECURITY") {
			psDegreeProgram = DegreeProgram::SECURITY;
		}
		else if (rosStrDegreeProgram == "NETWORK") {
			psDegreeProgram = DegreeProgram::NETWORK;
		}
		else if (rosStrDegreeProgram == "SOFTWARE") {
			psDegreeProgram = DegreeProgram::SOFTWARE;
		}
		else {
			psDegreeProgram = DegreeProgram::NONE;
		}
		
		add(rosStudentID, rosFirstName, rosLastName, rosEmailAddress, rosAge,
			rosCompletionDays, psDegreeProgram);
}

// Set up new student profile and add to class roster
void roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int completionDays[3], DegreeProgram degreeProgram) {

	student* rosStudent = new student(studentID, firstName, lastName, emailAddress, age,
		completionDays, degreeProgram);
	
	classRosterArray[nextStudent++] = rosStudent;

}

// Remove student from class roster per the requested student ID
void roster::remove(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) { // Check for nullptr at requested array slot
				cout << "The student with the ID: " << studentID << " was not found." << endl;
			}
		else {
			string reqStudentID = classRosterArray[i]->GetStudentID();
			
			if (reqStudentID == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
			}
		}
	}
}

// Print class roster providing information of each student (email address not included)
void roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) { // Check for nullptr at requested array slot
			classRosterArray[i]->print();
		}
	}
}

// Determine and print average days in course per the requested student ID
void roster::printAverageCompletionDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		
		if (classRosterArray[i] != nullptr) { // Check for nullptr at requested array slot
			string reqStudentID = classRosterArray[i]->GetStudentID();

			if (reqStudentID == studentID) {
				int* compDaysArray = classRosterArray[i]->GetCompletionDays();
				int avgCompDays = (compDaysArray[0] + compDaysArray[1] + compDaysArray[2]) / 3;

				cout << "Student ID: " << reqStudentID << ", average days in course is: " << avgCompDays << endl;
			}
		}
	}
}

// Determine and print invalid email addresses
void roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) { // Check for nullptr at requested array slot
			string invalidEmail = classRosterArray[i]->GetEmailAddress();

			if (invalidEmail.find(" ") != string::npos) {
				cout << invalidEmail << " - is invalid." << endl;
			}
			if (invalidEmail.find("@") == string::npos) {
				cout << invalidEmail << " - is invalid." << endl;
			}
			if ((invalidEmail.find(".com") == string::npos) &&
				(invalidEmail.find(".net") == string::npos) &&
				(invalidEmail.find(".edu") == string::npos)) {

				cout << invalidEmail << " - is invalid." << endl;
			}
		}
	}
}

// Print list of students per the requested degree program
void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	// Convert from DegreeProgram enum to associated string name
	string degreeString;
	if (degreeProgram == DegreeProgram::SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "NONE";
	}
	
	cout << "Showing students in degree program: " << degreeString << endl << endl;
	for (int i = 0; i < 5; i++) {
				
		if (classRosterArray[i] != nullptr) { // Check for nullptr at requested array slot
			DegreeProgram reqDegProgram = classRosterArray[i]->GetDegreeProgram();

			if (reqDegProgram == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
}