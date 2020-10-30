// Include all other peoples code that we need
#include <stdio.h>
#include <stdlib.h>

// 1. Basic function call
// The basic structure is: <Function Return Type> <Function Name>(<Function Parameter 1>, <Function Parameter 2>)
// Then put whatever the function is to do inside of curly brackets

// The paramters of the function (number - in the function below) are variables that the function
// gets to use 
// How could a function compute the square of a number without knowing the number to square?
// So we "pass" functions variables so that the function can use the variable to do something useful.
// In this case the variable we pass is the number and the something useful is squaring the number
int computeSquareOfNumber(int number) {
  int numberSquared = number * number;
  return numberSquared;   // Explain where this ends up
}

// Functions can also return nothing (they return void)
// This is useful for functions that just do stuff (Eg print something)
void printTitleNumber(int titleNumber) {
  printf("---------------------------------------------\n");
  printf("%d\n", titleNumber);
  printf("---------------------------------------------\n");
}

// Functions can also take multiple parameters
int computeAreaOfRectangle(int width, int height) {
  int area = width * height;
  return area;
}

// Functions can also themselves call other functions 
// Here we're calling the computeAreaOfRectange function to first get the rectangles area
// Once we have that we can multiply it by the depth of the rectangle
int computeVolumeOfCuboid(int width, int height, int depth) {
  int area = computeAreaOfRectangle(width, height);
  int volume = area * depth;
  return volume;
}

// Functions can accept as paramters values of any type 
// Functions can return values of any type
int isNumberPositive(int number) {
  if (number >= 0) {
    return 1;
  } else {
    return 0;
  }
}


// Passing arrays to functions is tricky
// We ALWAYS need to pass the size of the array so that the function
// can know how many items are in the array
// Otherwise it would not know how many items it needs to work on
int sumNumbersInArray(int array[], int numItemsInArray) {
  int totalSum = 0;   // Sum starts at zero

  // Loop over the array like we did in arrays
  for (int i=0; i<numItemsInArray; i++) {
    int currentValue = array[i];  // Get the current value from the array
    totalSum = totalSum + currentValue;     // Add it to the totalSum
  }

  return totalSum;
}


int main() {
  
  // Calling function that returns something
  int fiveSquared = computeSquareOfNumber(5);

  // Calling void function - it doesn't return anything
  // So we cant store what it returns in a variable, so we dont need one
  printTitleNumber(999);

  // Calling function that calls other functions
  // Note that the caller (which is the code that uses the function) doesn't
  // know or care if the function it is calling calls other functions
  int volume = computeVolumeOfCuboid(3, 4, 5);
  printf("Volume of cuboid with sides 3, 4 and 5 is: %d\n", volume);

  // Calling function that returns boolean
  int numIsPositive = isNumberPositive(-1);
  printf("-1 is positive? %d\n", numIsPositive);

  int arrayOfNumbers[5] = {1, 2, 3, 4, 5};
  int sumOfArrayOfNumbers = sumNumbersInArray(arrayOfNumbers, 5);
  printf("The sum of the numbers from 1 to 5 is: %d\n", sumOfArrayOfNumbers);

  return 0;
}