#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"
#include "student.h"

class roster
{
	public:
		roster();
		~roster();

		void parse(string row);
		
		void add(string studentID, string firstName, string lastName, string emailAddress,
			int age, int completionDays[3], DegreeProgram degreeProgram);

		void remove(string studentID);

		void printAll();

		void printAverageCompletionDays(string studentID);

		void printInvalidEmails();

		void printByDegreeProgram(DegreeProgram degreeProgram);

	private:
		string rosStudentID = "No Student ID";
		string rosFirstName = "No First Name";
		string rosLastName = "No Last Name";
		string rosEmailAddress = "No Email Address";
		int rosAge = 0;
		int rosCompletionDays1 = 0;
		int rosCompletionDays2 = 0;
		int rosCompletionDays3 = 0;
		string rosStrDegreeProgram = "NONE";

		student* classRosterArray[5]; // Initialize pointer array of type "student"
		int nextStudent = 0;
};

