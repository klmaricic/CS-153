//PROGRAMMER: KELSEY MARICIC    DATE: 10/19/11
//PROGRAM: assgn0.cpp
//PURPOSE: Processes the sonar data and finds the best longitude to 
           //fish for crab.
           
#include<iostream>
#include "hw00.hpp"
using namespace std;

//Gets the index of the greatest column
int getGreatestCol(int** array, int col, int row)
{
  int* arr = new int[col];
  
  for(int r = 0; r < row; r++)
  {
    arr[r] = 0;
  }
  
  //assigns the sums of each column of the calling array 
  for(int r = 0; r < row; r++)
  {
    for(int c = 0; c < col; c++)
    {
      arr[c] += array[c][r];
    }
  }
      
  int maxI = 0;
  
  //finds the index of the max sum
  for(int c = 0; c < col; c++)
  {
    if(arr[c] > arr[maxI])
      maxI = c;
  }
  
  delete[] arr;
  return maxI;
}

int main()
{
  int testNum, numRow, numCol;
  
  cin>>testNum;
  
  for(int i = 0; i < testNum; i++)
  {
    cin>>numRow;
    
    cin>>numCol;
    
    int** array = getmatrix<int>(numCol, numRow, -1);
    
    //assigns the values to the array
    for(int r = 0; r < numRow; r++)
    {
      for(int c = 0; c <numCol; c++)
      {
        cin>>array[c][r];
      }
    }

    cout<<"#"<<i<<":"<< getGreatestCol(array, numCol, numRow)<<endl;
  
    for(int r = 0; r < numRow; r++)
    {
      delete[] array[r];
    }
  
    delete[] array;
  }
      
  return 0;
} 
