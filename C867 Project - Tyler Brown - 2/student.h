#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class student
{
	public:
		// MUTATORS ---------------------------------------------------------------------------------------------------
		student();
		student(string studentID, string firstName, string lastName, string emailAddress,
			int age, int completionDays[3], DegreeProgram degreeProgram);

		~student();

		void SetStudentID(string studentID);

		void SetFirstName(string firstName);
		void SetLastName(string lastName);

		void SetEmailAddress(string emailAdress);
		void SetAge(int age);

		void SetCompletionDays(int* completionDays);

		void SetDegreeProgram(DegreeProgram degreeProgram);

		// ACCESSORS --------------------------------------------------------------------------------------------------
		string GetStudentID() const;

		string GetFirstName() const;
		string GetLastName() const;

		string GetEmailAddress() const;

		int GetAge() const;

		int* GetCompletionDays() const;

		DegreeProgram GetDegreeProgram() const;

		void print() const;

	private:
		string stdStudentID;
		string stdFirstName;
		string stdLastName;
		string stdEmailAddress;
		int stdAge;
		int stdCompletionDays[3];
		DegreeProgram stdDegreeProgram;
};