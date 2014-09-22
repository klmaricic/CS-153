//PROGRAMMER: Kelsey Maricic

#include <iostream>
#include<iomanip>
#include "hw02.hpp"

using namespace std;

int main()
{
  cout<<setprecision(4);
  int numStudents, type, tempProj,tempPaper;
  float temp;
  string name;
  Student **array; 
  
  cin>>numStudents;
  
  array = new Student*[numStudents];
  
  for(int i =0; i < numStudents; i++)
  {
    cin>>type;
    cin>>name;
    
    if(type<200)
    {
      
      Undergrad* active = new Undergrad(type, name, 4);
      
      array[i] = active;
      
      for(int k = 0; k < 4; k++)
      {
        cin>>temp;
        
        active->setExam(k, temp);
      } 
      
      cin>>tempProj;
      active->setProj(tempProj);
    }
    
    else if(type<300)
    {
      Graduate* active = new Graduate(type, name, 5);
      array[i] = active;
      
      for(int k = 0; k < 5; k++)
      {
        cin>>temp;
        
        active->setExam(k, temp);
      }
      
      cin>>tempProj;
      
      cin>>tempPaper;
      active->setProj(tempProj, tempPaper);
    }
    
    else
    {
      Distance* active = new Distance(type, name, 6);
      array[i] = active;
      
      for(int k = 0; k < 6; k++)
      {
        cin>>temp;
        active->setExam(k, temp);
      }     
    }
  }
  
  for(int j = 0; j < numStudents; j++){
    array[j]->print();
    cout<<" "<<array[j]->finalGrade()<<endl;
  }

  return 0;
}
