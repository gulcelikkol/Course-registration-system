#ifndef COURSES_H
#define COURSES_H
#include <fstream>
using namespace std;

class Course 
{
	private:
		//Array Declaration 
		string code[93];
		string course[93];
		string courseName[93];
		int credit[93];
		
	public:
		Course(); //Default Constructor 
		void showCourse(); //showCourses function 
		string getCourse(int); //getCourse function
		int getCredit(int); //getCredit function
		
};

//Default Constructor 
Course::Course()
{
	for(int i=0; i<93; i++)
	{
		code[i] = "";
		course[i] = "";
		courseName[i] = "";
		credit[i] = 0;
	}
}

//showCourses function
void Course::showCourse()
{
	ifstream inputFile;
	inputFile.open("CourseChoices.txt"); //Open the CourseChoices.txt file 
	int i = 0;
	//Read the courses from CourseChoices.txt file 
	while(inputFile && i<93) 
	{
		getline(inputFile, code[i], '\t');
		getline(inputFile, course[i], '\t');
		inputFile >> credit[i];
		courseName[i] = code[i] + " " + course[i];
		cout << (i+1) << ". " << code[i];
		cout << "\t" << course[i] << " : " << credit[i];
		cout << "\n";
		inputFile.ignore();
		i++;
	}
	inputFile.close(); //Close the CourseChoices.txt file
}

//getCourse function
string Course::getCourse(int ch)
{
	return courseName[ch];
}

//getCredit function
int Course::getCredit(int ch)
{
	return credit[ch];
}

#endif
