/**
 * ************** File 2 - Arrays ********************************************
 * Just pretend that all of these void functions are the main function of the program
 * Forgot about what the actual function parts mean and just look inside them
 * We will do functions later
 * 
 * Arrays are used when we want to have a bunch of values OF THE SAME TYPE
 * We can just use a single variable (the array) to contain all of the values
 * 
 * We access each individual value in the array BY NUMBER
 * The number we use is called the INDEX
 * Eg imagine the array of values below (numbers 1 through 5)
 *            ________________________________________
 * Values:   |   1   |   2   |   3   |   4   |   5   |
 *            ________________________________________
 *         
 * Index:        0       1       2       3       4
 * 
 * Array indices (plural of index) START AT ZERO!!!!!!!!!!!!!!!!!
 * This means if we want the first element in the array (which is 1 in this case), we
 * actually want the value that is at INDEX 0
 * 
 * The second value in the array is at INDEX 1 etc
 * 
 * There is a totally logical reason for this but who cares for now
 ***********************************************************************************/

#include<iostream>
using namespace std;


void basicArray() {
  // To create an array we need to know the type AND how many values we are going 
  // to have in the array (how big the array should be)

  // This creates an array that CAN hold up to 5 integers
  // but it doesn't contain any integers yet
  int arrayOfFiveInts[5];  

  // We can put integers in there
  arrayOfFiveInts[0] = 10;    // Remember first value in the array is at index 0
  arrayOfFiveInts[1] = 11;
  // etc..

  // We can print values from the array
  cout << "The value at index 0 is: " << arrayOfFiveInts[0] << endl;
  cout << "The value at index 1 is: " << arrayOfFiveInts[1] << endl;
  // etc..

  // We can also create arrays and insert their values in one step like this
  // BUT YOU CAN ONLY DO THIS ONCE WHEN YOU CREATE YOUR ARRAY
  int arrayOfNumbers [3] = {1, 2, 3};
}

// 2 Looping over arrays is why arrays are useful
void printArray() {
  int arrayOfInts [3] = {1, 2, 3};

  // We need a variable to keep track of what value in the array we are currently at
  // That is, what INDEX we are currently at
  int index = 1;
  cout << "The value at index is: " << arrayOfInts[index] << endl << endl; 

  // Typically we use a variable called i to represent this index
  // Then we can write a loop to print all the elements in the array
  // i should start at 0 (the first index in the array)
  // The loop should stop when i < number of elements in the array (3 in this case)
  for (int i = 0; i < 3; i++) {
    cout << "The value at index " << i << " is: " << arrayOfInts[i] << endl;
  }
}


/****************************************************************
 *  Passing arrays to functions is tricky: see functions section
 ****************************************************************/




int main() {

  cout << "1. Basic arrays" << endl;
  basicArray();
  cout << endl << endl;

  cout <<  "2. Print an array with a loop" << endl;
  printArray();
  cout << endl << endl;

  return 0;
}