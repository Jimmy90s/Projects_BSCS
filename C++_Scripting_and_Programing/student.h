#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student 
{
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize];
	DegreeProgram degreeType;
public:
	Student();//parameterless constructor - sets to defualt values - always write this
	
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeType);
	//Full const
	~Student();//destructor

	//getters aka accessors
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeType();

	//setters aka mutators
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeType(DegreeProgram degreeType);

	static void printHeader();//dispay header for the data to follow
	void print();//displays 'this' student's data

};
