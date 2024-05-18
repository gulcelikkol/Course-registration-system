#ifndef GRADE_H
#define GRADE_H
using namespace std;

class Grade
{
    private:
		//Declaring Variables 
		string lettergrade;  //lettergrade
	 	double credit; //credit
	    double caltimes; //caltimes
	    double totalcal; //total pointer
	    double totalcredit; //total credit
	    double finalgpa; //final GPA 
	    
	public:
		//Default Constructor
		Grade();
		//Constructor
		Grade(string, double, double, double, double, double);
		//Mutator function
		void set(string, double);
		//calcGrade function
		void calcGrade(string lg, double cre);
		//calcFinal function
		void calcFinal(double &);
};

//Default Constructor
Grade::Grade()
{
	lettergrade = "";
	credit = 0.0;
	caltimes = 0.0;
	totalcal = 0.0;
	totalcredit = 0.0;
	finalgpa = 0.0;
}

//Constructor
Grade::Grade(string lg, double cre, double ct, double tc, double tcre, double gpa) 
{
	lettergrade = lg;
	credit = cre;
	caltimes = ct;
	totalcal = tc;
	totalcredit = tcre;
	finalgpa = gpa;
}

//Mutator function
void Grade::set(string lg, double cre)
{
	lettergrade = lg;
	credit = cre;
}

//calcGrade function
void Grade::calcGrade(string lg, double cre)
{
	if(lg == "a" || lg == "A")
	{
		caltimes = cre * 4.0;
	}
	else if(lg == "a-" || lg == "A-")
	{
		caltimes = cre * 3.67;
	}
	else if(lg == "b+" || lg == "B+")
	{
		caltimes = cre * 3.33;
	}
	else if(lg == "b" || lg == "B")
	{
		caltimes = cre * 3.0;
	}
	else if(lg == "b-" || lg == "B-")
	{
		caltimes = cre * 2.67;
	}
	else if(lg == "c+" || lg == "C+")
	{
		caltimes = cre * 2.33;
	}
	else if(lg == "c" || lg == "C")
	{
		caltimes = cre * 2.0;
	}
	else if(lg == "c-" || lg == "C-")
	{
		caltimes = cre * 1.67;
	}
	else if(lg == "d" || lg == "D")
	{
		caltimes = cre * 1.33;
	}
	else if(lg == "f" || lg == "F")
	{
		caltimes = cre * 1.0;
	}	   
	else
	{
		cout<<"Invaild Input...";
	}
	
    totalcredit = totalcredit + cre; //Calculates total credits  
    totalcal = totalcal + caltimes; //Calculates total pointer
}

//calcFinal function
void Grade::calcFinal(double &avg)
{
	cout << setprecision(2) << fixed << showpoint; //Set the finalgpa to decimal points
	finalgpa = totalcal/totalcredit; //Calculates finalgpa  
	avg = finalgpa;
} 

#endif
