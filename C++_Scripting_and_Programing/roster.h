#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];//Not declared dynamically
public:
	void parse(string row);
	void add(string bID,
		string bFirstName,
		string bLastName,
		string bEmail,
		int bage,
		int bprice1,
		int bprice2,
		int bprice3,
		DegreeProgram bdegreeType);
	void printAll();//calls the print() method in Student class for each student
	void printByDegreeProgram(DegreeProgram bt);//DegreeType is passed in
	void printInvalidEmails();//Each student's email needs an @ and . 
	void printAverageDaysInCourse(string studentID);//average days
	void remove(string studentID);//find the student with supplied ID and remove 
	~Roster();
};