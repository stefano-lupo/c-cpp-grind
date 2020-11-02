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
}