/**
 * ************** File 1 - Baiscs of C++ ********************************************
 * Just pretend that all of these void functions are the main function of the program
 * Forgot about what the actual function parts mean and just look inside them
 * We will do functions in another file
 ***********************************************************************************/

// Include all other peoples code that we need
#include <stdio.h>
#include <stdlib.h>

// 1. Print out some text to the terminal
void basicPrinting() {
  printf("Hello world!\n");
}

// 2. Variables
void variables() {
  int age = 23;
  float heightInMetres = 1.75;
  
  printf("Below is some info about me: \n");
  printf("The person is %d years old and %fm tall\n", age, heightInMetres);
}

// 3. while loop
// We use this when WE DON'T KNOW HOW MANY TIMES we will need to 
// run something when we are writing the program
// The user could sit here forever typing 1
void whileLoops() {
  int keepRunning = 1;



  while (keepRunning == 1) {
    printf("Running...\n");
    printf("Should I keep runnning? (type 1 for yes, 0 for no)\n");
    
    // Don't worry about this, it just gets what number you typed in and puts it into the keepRunning variable
    scanf("%d", &keepRunning);

    printf("Keep running is now %d\n", keepRunning);
  }

  printf("Shutting down since while condition no longer true\n");
}

// 4a. Life without for loops
void withoutForLoop() {
  // Notice the code is repeated (with just one thing changed)
  printf("1\n");
  printf("2\n");
  printf("3\n");
  printf("4\n");
  printf("5\n");
}

// 4b. Life with for loops
// We use for loops when WE KNOW how many times we want to run a piece of code (5 in this case)
void withForLoop() {
  // We can just use a variable to represent the bit in the middle
  // We can then just repeatedly change the value of that variable and
  // run the same line of code a bunch of times inside of the loop


  for (int currentNumber = 1; currentNumber <= 5; currentNumber++) {
    printf("Current number is: %d\n",currentNumber);
  }
}

// 4c. What the for loop essentially does (it doesnt actually do this but pretty much)
void whatForLoopDoesSortOf() {
  int currentNumber = 1;

  // 1 <= 5 so run the code
  printf("%d\n", currentNumber);
  currentNumber++;  // increment currentNumber to 2 etc

  // 2 <= 5 so run the code
  printf("%d\n", currentNumber);
  currentNumber++;

  // 3 <= 5 so run the code
  printf("%d\n", currentNumber);
  currentNumber++;  

  // 4 <= 5 so run the code
  printf("%d\n", currentNumber);
  currentNumber++;

  // 4 <= 5 so run the code
  printf("%d\n", currentNumber);
  currentNumber++;
}


// 5a. if statements
// Should you let a kid go on a rollercoaster?
// Has bugs in it
void ifStatements() {
  int age;
  float heightInM;
  int isOwnerOfParksKid;
  int isCrying;

  printf("How old are they in years: ");
  scanf("%d", &age);
  printf("\n");

  printf("How tall are they in metres: ");
  scanf("%f", &heightInM);
  printf("\n");

  printf("Are they the owners kid: ");
  scanf("%d", &isOwnerOfParksKid);
  printf("\n");

  printf("Are they crying:");
  scanf("%d", &isCrying);
  printf("\n");

  printf("Age: %d, height: %fm, isOwnerOfParksKid: %d, isCrying: %d\n", age, heightInM, isOwnerOfParksKid, isCrying);

  if (age > 10) {
    printf("They're allowed since they're old enough\n");
    return;
  }

  if (age > 8 && heightInM > 1.2) {
    printf("They're allowed since they're big enough\n");
    return;
  }

  if (isOwnerOfParksKid || isCrying) {
    printf("Letting them in anyway\n");
    return;
  }

  // Note this code always prints not letting them in - see else statements section.
  printf("Not letting them in!\n");
}

// 5b. combined if statements
void combinedIf() {

  // Notice how we need all this code from 5a again??
  // This is the perfect case for a function (see later)
  int age;
  float heightInM;
  int isOwnerOfParksKid;
  int isCrying;

  printf("How old are they in years: ");
  scanf("%d", &age);
  printf("\n");

  printf("How tall are they in metres: ");
  scanf("%f", &heightInM);
  printf("\n");

  printf("Are they the owners kid: ");
  scanf("%d", &isOwnerOfParksKid);
  printf("\n");

  printf("Are they crying:");
  scanf("%d", &isCrying);
  printf("\n");

  printf("Age: %d, height: %fm, isOwnerOfParksKid: %d, isCrying: %d\n", age, heightInM, isOwnerOfParksKid, isCrying);

  if (age > 10 || 
    (age > 8 && heightInM > 1.2) ||
    (isCrying == 1 || isOwnerOfParksKid == 1)) {
      printf("Letting them on!\n");
  } else {
    printf("Not letting them on\n");
  }
}

// 5c. Nested if statements
void nestedIfAndElseIf() {

  // Too lazy to write all that cin stuff again so just make up values
  int age = 9;
  double heightInM = 1.21;
  int isOwnersKid = 0;
  int isCrying = 0;

  if (age > 10) {
    printf("Letting them on as they are older than 10\n");
  } else {

    // This next bit of code only happens if they are 10 or younger
    // We know that they are DEFINITELY 10 or younger inside of these curly brackets
    // as if they were older than 10 the if statement above would have been true
    // so that code would have ran and not this else code

    if (age > 8 && heightInM > 1.2) {
      printf("Letting them on as they are over 8 AND above 1.2m");
    } else if (isCrying == 1) {
      printf("Letting them on as they are crying\n");
    } else if (isOwnersKid == 1) {
      printf("Letting them on as they are the owners kid\n");
    } else {
      printf("Not letting them on\n");
    }

  }
}

// What code runs when we run our program
// Just a special function (called main) that returns an int
int main() {

  // printf("1. Printing\n");
  // basicPrinting();
  // printf("\n");

  // printf("2. Variables\n");
  // variables();
  // printf("\n");

  printf("3. while loops\n");
  whileLoops();
  printf("\n");

  // printf("4a. Without for loops\n");
  // withoutForLoop();
  // printf("\n");

  // printf("4b. With for loops\n");
  // withForLoop();
  // printf("\n");

  // printf("4c. What for loop actually does\n");
  // whatForLoopDoesSortOf();
  // printf("\n");

  // printf("5a. If statements\n");
  // ifStatements();
  // printf("\n");

  // printf("5b. combined if statements\n");
  // combinedIf();
  // printf("\n");

  // printf("5c. Nested if and else if statements\n");
  // nestedIfAndElseIf();
  // printf("\n");

  return 0;
}