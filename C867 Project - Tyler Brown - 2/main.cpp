#include <iostream>
#include <string>
using namespace std;

#include "roster.h"

int main() {
	
	// Header Information
	cout << "Course Title: C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010479775" << endl;
	cout << "Name: Tyler Brown" << endl << endl;

	
	const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Tyler,Brown,tbr1841@wgu.edu,31,53,30,55,SOFTWARE" };

	roster classRoster; // Instantiate object of roster(class)

	// Define classRosterArray
	for (int j = 0; j < 5; j++) {
		classRoster.parse(studentData[j]);
	}
	
	// Display class roster
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;
	
	// Display list of invalid emails
	cout << "Displaying invalid emails:" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	
	// Display average days in course per requested student ID
	for (int j = 0; j < 5; j++) {
		classRoster.printAverageCompletionDays("A" + to_string(j+1));
	}
	cout << endl;
	
	// Display list of students in the software degree program
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	
	// Remove requested student ID from class roster
	cout << "Removing A3:" << endl << endl;
	classRoster.remove("A3");
	
	// Display class roster again (verify that requested student was deleted)
	classRoster.printAll();
	cout << endl;
	
	// Attempt to remove student ID that has already been removed
	cout << "Removing A3 again." << endl << endl;
	classRoster.remove("A3");
	cout << endl;
	
	cout << "DONE." << endl;

	return 0;
}