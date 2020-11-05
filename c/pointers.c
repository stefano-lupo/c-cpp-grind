#include <stdio.h>
#include <stdlib.h>


void functionsGetOwnCopiesByDefault(int someNumber) {
  someNumber = 99;

  printf("Function has changed someNumber to: %d\n", someNumber);
}

void getKidRolercosterInfo(int* age, float* heightInM, int* isCrying, int* isOwnerOfParksKid) {
  printf("Age: %p\n", age);

  printf("Setting age to 99\n");
  *age = 99;

  
  printf("Setting heightInM to 3.5m\n");
  *heightInM = 3.5;

  printf("Setting isCrying to 1\n");
  *isCrying = 1;

  printf("Setting isOwnerOfParksKid to 0\n");
  *isOwnerOfParksKid = 1;
}


/*
  Advanced - double pointers to structs (e.g. mutating a linked list head)
*/
typedef struct SomeStruct {
  int data;
} SomeStruct;


// Lets say if the data is 99, we want to change the callers SomeStruct to be a new one with data = 100
// This does NOT work the way we would think.
// We might imagine code like
/* 
  SomeStruct* ss = (SomeStruct*) malloc(sizeof(SomeStruct*));
  ss -> data = 99;

  // This creates a _new_ SomeStruct* and hands that off to the function
  // It just copies the value of ss (the memory address of the struct) into a new pointer for use inside the function
  whyWeNeedDoublePointers(someStruct); 
*/
// The fact that this function takes a SomeStruct* doesn't really mean anything
// We know it's really just an integer memory address at the end of the day.
// The someStruct variable here is a TOTALLY SEPARATE PIECE OF MEMORY to the piece of memory that the caller referenced from
// Just in calling the function, we set those two pieces of memory to have the same value - they both now refer to the SomeStruct at the same memory address
// But the there are actually two separate pointers here 
//  - the one that the caller had
//  - and the one that was passed _by value_ based on what the caller had (remember ints (and everything in C) are actually just pass by value)
void whyWeNeedDoublePointers(SomeStruct* thePassedByValuePointer) {
  printf("The passed in pointer is [%p] %p --> %d\n", &thePassedByValuePointer, thePassedByValuePointer, thePassedByValuePointer->data);
  if (thePassedByValuePointer -> data == 99) {
    // Create the new replacement struct with the correct value
    SomeStruct* replacementStruct = (SomeStruct*) malloc(sizeof(SomeStruct));
    replacementStruct -> data = 100;

    // So now just make someStruct = replacementStruct.. right?
    // NO! Because someStruct is a totally different pointer to the one the caller had!
    // They just happen to point to the same value (the value was passed-by-value when the function was called!)
    thePassedByValuePointer = replacementStruct;

    printf("SomeStruct after replacement is [%p] %p --> %d\n", &thePassedByValuePointer, thePassedByValuePointer, thePassedByValuePointer->data);
  }
}

void usingDoublePointersToMutateACallersPtr(SomeStruct** someStruct) {
  printf("The passed in pointer is [%p] %p --> [%p] %d\n", &someStruct, someStruct, *someStruct, (*someStruct)->data);
  if ((*someStruct)->data == 99) {
    SomeStruct* replacementStruct = (SomeStruct*) malloc(sizeof(SomeStruct));
    replacementStruct -> data = 100;

    // Now de-referecnce the pointer we have _to the CALLER's pointer to the struct_
    // and set the value at memory location to the memory address of the new struct.
    *someStruct = replacementStruct;

    printf("SomeStruct after replacement is [%p] %p --> [%p] %d\n", &someStruct, someStruct, *someStruct, (*someStruct)->data);
  }
}

int main() {

  // Pass by value
  // printf("1: Functions get their own copy of variables by default\n");
  // int x = 0;
  // printf("x before calling function is: %d\n", x);
  // functionsGetOwnCopiesByDefault(x);
  // printf("x after calling function is: %d\n", x);
  // printf("\n\n");

  // How to use references to variables to set values in void functions
  int age = 5;
  float heightInM = 1.2;
  int isCrying = 0;
  int isOwnerOfParksKid = 0;
  char c = 'a';

  printf("2: Passing by reference to functions changes their underlying values\n");
  printf("The address of age is %p\n", &age);
  printf("The address of heightInM is %p\n", &heightInM);
  printf("The address of isCrying is %p\n", &isCrying);
  printf("The address of isOwnerOfParksKid is %p\n\n", &isOwnerOfParksKid);


  getKidRolercosterInfo(&age, &heightInM, &isCrying, &isOwnerOfParksKid);

  printf("\nThe values should now have been set by the getKidRolercosterInfo function\n");
  printf("Age: %d\n", age);
  printf("heightInM: %f\n", heightInM);
  printf("isCrying: %d\n", isCrying);
  printf("isOwnerOfParksKid: %d\n", isOwnerOfParksKid);

  // Advanced, why we need double pointers etc
  SomeStruct* ss = (SomeStruct*) malloc(sizeof(SomeStruct));
  ss -> data = 99;

  printf("\n\nCaller's SomeStruct pointer: [%p] %p --> %d\n", &ss, ss, ss->data);
  whyWeNeedDoublePointers(ss);
  printf("Callers SomeStruct pointer after call: [%p] %p --> %d\n", &ss, ss, ss->data);

  usingDoublePointersToMutateACallersPtr(&ss);
  printf("Callers SomeStruct pointer after correct call: [%p] %p --> %d\n", &ss, ss, ss->data);

}