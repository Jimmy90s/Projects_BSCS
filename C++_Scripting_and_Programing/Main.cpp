#include "roster.h"
int main()
{
	//string to parse
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,James,Laurie,jlaur40@wgu.edu,31,30,40,50,SOFTWARE"
	};

	const int numStudents = 5; // records student size manually
	Roster roster;//creates the roster using default parameterless constructor

	cout << "Course title: SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << std::endl;
	cout << "Programming language used: C++" << std::endl;
	cout << "Student ID: 010769546" << std::endl;
	cout << "Name: James Laurie\n" << std::endl;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;
	roster.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree type: " << degreeTypeStrings[i] << std::endl;
		roster.printByDegreeProgram((DegreeProgram)i);//Cast the int to a DegreeType
	}

	cout << "Displaying studentID with invalid email address" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days in course by studentID: " << std::endl;
	roster.printAverageDaysInCourse("A5");

	cout << "Removing student with ID A3:" << std::endl;
	roster.remove("A3");
	cout << std::endl;

	cout << "Removing student with ID A3:" << std::endl;
	roster.remove("A3");
	cout << std::endl;
	
	
}