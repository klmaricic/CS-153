//PROGRAMMER: Kelsey Maricic
//PROGRAM: hw01.cpp
//PURPOSE: Organize posters by tags

#include<iostream>
#include "hw01.hpp"
using namespace std;

int main()
{
  int numPosters, numTags, numQ;
  string title, author, tag;
  
  //cout<<"How many posters are there?"<<endl;
  cin>>numPosters;
  
  Poster* array = new Poster[numPosters];

  for(int i = 0; i < numPosters; i ++)
  {
    //cout<<"What is the name of the poster?"<<endl;
    getline(cin, title); //clears buffer
    getline(cin, title);//getline gets multiple words on one line
    
    //cout<<"Who is the author?"<<endl;
    getline(cin, author);
    
    array[i].set(title, author);
    
    //cout<<"How many tags?"<<endl;
    cin>>numTags;
    array[i].no_tags = numTags;
    
    array[i].tags = new string[numTags];
    
    for(int j = 0; j < numTags; j++)
    {
      //cout<<"Tag "<<j<<endl;
      cin>>tag;
      array[i].tags[j] = tag;
    }   
  }
  
  //cout<<"How many quieres?"<<endl;
  cin>>numQ;
  
  string* arrQ = new string[numQ];
  
  for(int q = 0; q < numQ; q++)
  {
    cout<<"quierie "<<q<<endl;
    cin>>arrQ[q];
  }
  bool found;
  for(int i = 0; i < numQ; i++)
  {
    cout<<"#"<<i<<":"<<endl;
    for(int posterIndex = 0; posterIndex < numPosters; posterIndex++)
    {
      found = false;
      for(int tagIndex = 0; tagIndex < array[posterIndex].no_tags && !found; tagIndex++)
      {
        if(arrQ[i] == array[posterIndex].tags[tagIndex]) 
        {
          found = true;
          cout<<array[posterIndex].name << " by " << array[posterIndex].author<<endl;
        }
      }
    }
  }
  
  return 0;
}
