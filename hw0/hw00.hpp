//PROGRAMMER: KELSEY MARICIC    DATE: 10/19/11
//PROGRAM: assgn0.hpp
//PURPOSE: Processes the sonar data and finds the best longitude to
           //fish for crab.
           

// This function allocates a 2D array of size cols by rows
// fills the array with default value def
// and returns a pointer T to the (beggining of) the array 

template <typename T>
T** getmatrix(int cols, int rows, T def)
{
    T**array = new T*[cols];
    
    for(int c = 0; c < cols; c++)
    {
      array[c] = new T[rows];
    }
    
    for(int c = 0; c < cols; c++)
    { 
      for(int r = 0; r < rows; r++)
        array[c][r] = def;
    }
    
    return array;
}

