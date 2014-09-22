//
// What follows is the declaration of a base class 'Student' and 
// 3 derived classes, 'Undegrad', 'Graduate' and 'Distance' designed
// to represent the 3 kinds of students mentioned in the problem.
//
// Notice that all field (data members) are "protected", therefore
// there will be accessed only through methods (member functions)
//

#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------------
class Student {
protected:
	int id;				// Id Number
	string name; 		// Name of student
	int no_exams;       // Number of exams
	int *exams;         // Array of grades of exams
	
public:
	Student(int i, string n, int ne);
	/* Constructor
	   Assigns i, n and ne to id, name and no_exams respectively.
	   Initializes the *exams array 
	*/
	~Student();
	/* Destructor
	*/
	
	void setExam(int i, int g);
	/* assigns a grade of g to the i'th exam  
	*/
	float examAvg();
	/* returns the average of all exams
	*/
	void print();
 	/* Outputs to cout the id and name of the student.
	*/
	
	virtual float finalGrade() {return -1;}
};

Student:: Student(int i, string n, int ne)
{
  id =i;
  name = n;
  no_exams=ne;
  
  exams = new int[ne];
}

Student::~Student()
{
  delete[] exams;
}

void Student:: setExam(int i, int g)
{
  exams[i] = g;
}

float Student:: examAvg()
{
  float total = 0;
  
  for(int i =0; i < no_exams; i++)
    total += exams[i];
    
  float avg = total/no_exams;
  
  return avg;
}

void Student:: print()
{
  cout<<id<<" "<<name;
}
      

// ------------------------------------------------------------------
class Undergrad : public Student {
protected:
	int progproj;		// grade of programming project
public:
	Undergrad(int i, string n, int ne) : Student(i,n,ne) {} 
	~Undergrad(){}
	/* Constructor and destructor
	   (same function as base class)
	 */
	
	void setProj(int g);
	/* assigns a grade of g to the programming project  
	*/
	float finalGrade();
	/* computes and returns the final grade
	*/
};

void Undergrad:: setProj(int g)
{
  progproj = g;
}

float Undergrad:: finalGrade()
{
  return examAvg()*.80+progproj*.20;
}


// ------------------------------------------------------------------
class Graduate : public Student {
protected:
	int research;		// grade of research project
	int paper;			// grade of paper presentation
public:
	Graduate(int i, string n, int ne):Student(i,n,ne){}
	~Graduate(){}
	/* Constructor and destructor
	   (same function as base class)
	 */
	
	void setProj(int g, int p);
	/* assigns a grade of g to the research project
	   and a grade of p the the paper presentation  
	*/
	float finalGrade();
	/* computes and returns the final grade
	*/
};

void Graduate:: setProj(int g, int p)
{
  research = g;
  paper = p;
}

float Graduate:: finalGrade()
{
  return examAvg()*.65+research*.20+paper*.15;
}  


// ------------------------------------------------------------------
class Distance : public Student {
public:
	Distance(int i, string n, int ne):Student(i,n,ne){}
	~Distance(){}
	/* Constructor and destructor
	   (same function as base class)
	 */
	float finalGrade();
	/* computes and returns the final grade
	*/	
};

float Distance:: finalGrade()
{
  return examAvg();
}
