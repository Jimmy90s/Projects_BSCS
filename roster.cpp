#include "roster.h"
void Roster::parse(string studentdata)//parse out each row one at a time
{
	DegreeProgram bt = NETWORK;//default value
	if (studentdata.at(1) == '1' || studentdata.at(1) == '4') bt = SECURITY;//the second character tells us the degree type
	else if (studentdata.at(1) == '5' || studentdata.at(1) == '3') bt = SOFTWARE;
	

	int rhs = studentdata.find(",");
	string bID = studentdata.substr(0, rhs);//extract the substring in front of the comma

	int lhs = rhs + 1;//move past the previous comma
	rhs = studentdata.find(",", lhs);
	string ttl = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	string aut = studentdata.substr(lhs, rhs - lhs);//last name

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	string em = studentdata.substr(lhs, rhs - lhs);//email

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	int ag = stod(studentdata.substr(lhs, rhs - lhs));// age

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	int p1 = stod(studentdata.substr(lhs, rhs - lhs));//first day - convert to double
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int p2 = stod(studentdata.substr(lhs, rhs - lhs));//second day
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int p3 = stod(studentdata.substr(lhs, rhs - lhs));//third day

	add(bID, ttl, aut, em, ag, p1, p2, p3, bt);//days go in separately
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	//Put days back into an array for constructor 
	double parr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	//make be student object. lastindex starts at -1 and not 0
	//prefix for us ++
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName ,emailAddress,age, parr, degreeprogram);//use full constructor
}

//display all students using tab-separated output
void Roster::printAll()
{
	Student::printHeader();//quick way to do this part
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDays()[0]; cout << '\t';
		cout << classRosterArray[i]->getDays()[1]; cout << '\t';
		cout << classRosterArray[i]->getDays()[2]; cout << '\t';
		cout << degreeTypeStrings[classRosterArray[i]->getDegreeType()] << std::endl;
	}
}

//dispay only students which match given degree type
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeType() == degreeprogram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

// Each students email must contain either @ or .
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string bID = (classRosterArray[i]->getEmailAddress());
		if ((bID.find('@') == string::npos && bID.find('.') == string::npos) || (bID.find(' ') != string::npos || bID.find('.') == string::npos || bID.find('@') == string::npos))
		{
			any = true;
			cout << classRosterArray[i]->getID() << ": " << bID << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID)
		{
			cout << classRosterArray[i]->getID() << ": ";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3 << std::endl;
		}
	}
	cout << std::endl;
}

void Roster::remove(string studentID)//student removed comes in as a parameter
{
	bool success = false;//assume it's not here
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;//found
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];//swap it with last student
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;//last student no longer visible, not deleted
		}
	}
	if (success)
	{
		cout << studentID << " removed from repository." << std::endl << std::endl;
		this->printAll();//display the students
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] == nullptr;
	}
}