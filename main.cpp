#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Course.h"
#include "Grade.h"
#include "NumberList.h"
#define nullptr NULL
using namespace std;

//Function Prototypes
void studentBio(string &, string &, int &, int &);
void Display(string, string, int, int);
void studentGrade(double&);
int InputValidation1(int&);
int InputValidation2(int&);

//Main Function
int main()
{
	//Declaring Variables 
	string Name, icNum, name;
	int matricNum, year, ch, choice, cre, total = 0;
	double GPAaverage;
	char n, del_choice;
	
	//Calling studentBio function
	studentBio(Name, icNum, matricNum, year);
	system("cls");

    //Course class Declaration
	Course s; 
	//Define a NumberList objects
	NumberList <string> list1;
	NumberList <int> list2;
	
	//menu
	cout << "------------------------------------------------------";
	cout << " \nWELCOME TO Central@USM" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "\nYou may register courses" << endl; 
	cout <<	"and calculate and view your Grade Point Average (GPA) via this system." << endl;
	cout <<	"Choose from below :-" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "1. Course Registration for Next Semester" << endl;
	cout << "2. Grade Point Average (GPA) Calculator for Current Semester" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "-> ";
	cin >> ch;
	system("cls");
	
	if(ch == 1)
	{
		cout << "\n--COURSE REGISTRATION--\n";
		s.showCourse(); //Calling showCourses function from Course class 
	
		do
		{
			cout << "\nEnter the course number from the above list: ";
			cout << "\n-> ";
			cin >> choice;
			//Store getCourse function to name variable
			name = s.getCourse(choice-1);
			//Store getCredit function to cre variable
			cre = s.getCredit(choice-1);
			//Store the NumberList objects in the list
			list1.appendNode(name);
			list2.appendNode(cre);
			cout << "Subject added to the list.";	
			//Calculating Total Credits
			total = total+cre;
			cout << "\n\nDo you wish to add another subject? (Enter Y = Yes / N = no):";
			cin >> n;
			
		} while (n == 'Y' || n == 'y');
		
		cout << "Registered Course:-";
		cout << endl;
		//Displaying the course registered 
		list1.display();
		//Displaying the total credits 
		cout << "\nTotal Credits : " << total << endl;
	
		cout << "\nDo you want to drop any courses ? (Enter Y = Yes / N = no): ";
		cin >> del_choice ;
		while(del_choice == 'Y' || del_choice == 'y')
		{
			cout << "\nEnter the course number from the above list that you want to drop: " << endl;
			cin >> choice;
			//Store getCourse function to name variable
			name = s.getCourse(choice-1);
			//Deleting the intended course 
			list1.deleteNode(name);
			//Displaying the course registered after deleting 
			list1.display();
			cre = s.getCredit(choice-1);
			//Deleting the intended course's credits
			list2.deleteNode(cre);
			//Calculating total credits after deleting the intended course
		   	total = total - cre;
		   	cout << "\nDo you want to drop another course? (Enter Y = Yes / N = no): ";
		   	cin >> del_choice;
		}
			
	    cout << "\nTotal Credits after dropping the course: " << total << endl;
	}
	
    else if(ch == 2)
    {	
    	//Calling the studentGrade function
		studentGrade(GPAaverage);
	}
    
    system("cls");
    //Calling the Display function
    Display(Name, icNum, matricNum, year);
    
    if (ch == 1) //Display the Registered Courses and total credits 
    {
    	cout << "\nRegistered Course:- " << endl;
    	list1.display();
    	cout << "\nTotal credits: " << total;
    }
	else if (ch == 2) //Displaying the GPA
    	cout << "\nGPA: " << GPAaverage;
	
	return 0;
}

//studentBio function
void studentBio(string &n, string &icNo, int &matrics, int &yearStudy)
{
    cout << "Enter Your Details Below:-\n";
	cout << "Name: ";
    getline (cin, n);
    cout << "Matrics Number: ";
    cin >> matrics;
    InputValidation1(matrics); //Call InputValidation1 funtion for matric number
    cout << "IC Number: ";
    cin.ignore();
    getline(cin, icNo); 
    cout << "Year: ";
    cin >> yearStudy;
    InputValidation2(yearStudy); //Call InputValidation1 funtion for IC number
}

//Display function
void Display(string Name, string icNum, int matricNum, int year)
{
	cout << endl;
	cout << "Name: " << Name << endl;
    cout << "Matric Number: " << matricNum << endl;
    cout << "IC Number:" << icNum << endl;
    cout << "Year: " << year << endl;
}

//studentGrade function
void studentGrade(double &avg)
{
    Grade gPointAvg; //Declaring Grade class 
    string l_grade; //letter grade
 	double crdt; //Credits
    char option; 

    cout << "\n--GPA CALCULATOR--" << endl;
	
    cout<<"\nEnter Grade: ";
    cin>>l_grade;
    cin.ignore();
	cout<<"Enter Course Credit: ";
	cin>>crdt;
    gPointAvg.calcGrade(l_grade, crdt); 
    cout<<"\nDo you want to enter another grade (Y - Yes, N - no): ";
    cin>>option;

	while(option == 'Y' || option == 'y')
	{           
        cout<<"\nEnter Grade: ";
        cin>>l_grade;
        cin.ignore();
        cout<<"Enter Course Credit: ";
    	cin>>crdt;
            
        gPointAvg.calcGrade(l_grade, crdt); 
        cout<<"\nDo you want to enter another grade (Y - Yes, N - no): ";
        cin>>option;
	}
	
    gPointAvg.calcFinal(avg);
}

//InputValidation1 function
int InputValidation1(int& m)
{
	while (m < 100000 || m > 199999)
	{
		cout << "\nINVALID! Enter a valid matric number : ";
		cin >> m;
        return m;
	}
}

//InputValidation2 function
int InputValidation2(int& yr)
{
	while (yr < 1 || yr > 4)
	{
		cout << "\nINVALID! Enter your correct year of study : ";
		cin >> yr;
        return yr;
	}
}
