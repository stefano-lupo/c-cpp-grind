/**
 * Note:
 * Just pretend that all of these void functions are the main function of the program
 * Forgot about what the actual function parts mean and just look inside them
 * We will do functions in the next file
**/

// Include all other peoples code that we need
#include<iostream>
#include<string>

// Boiler plate - dont worry
using namespace std;

// 1. Print out some text to the terminal
void basicPrinting() {
  cout << "Hello world!" << endl;
}

// 2. Variables
void variables() {
  int age = 23;
  string name = "Stefano";
  double heightInMetres = 1.75;
  
  cout << "Below is some info about me: " << endl;
  cout << name << " is " << age << " years old and " << heightInMetres << "m tall" << endl;
}

// 3. while loop
// We use this when WE DON'T KNOW HOW MANY TIMES we will need to 
// run something when we are writing the program
// The user could sit here forever typing 1
void whileLoops() {
  bool keepRunning = true;

  while (keepRunning) {
    cout << "Running..." << endl;
    cout << "Should I keep runnning? (type 1 for yes, 0 for no)";
    cin >> keepRunning;
  }

  cout << "Shutting down since while condition no longer true";
}

// 4a. Life without for loops
void withoutForLoop() {
  // Notice the code is repeated (with just one thing changed)
  cout << 1 << endl;
  cout << 2 << endl;
  cout << 3 << endl;
  cout << 4 << endl;
  cout << 5 << endl;
}

// 4b. Life with for loops
// We use for loops when WE KNOW how many times we want to run a piece of code (5 in this case)
void withForLoop() {
  // We can just use a variable to represent the bit in the middle
  // We can then just repeatedly change the value of that variable and
  // run the same line of code a bunch of times inside of the loop

  int currentNumber = 1; // Use int as we are dealing with numbers
  for (int currentNumber = 1; currentNumber <= 5; currentNumber++) {
    cout << currentNumber << endl;
  }
}

// 4c. What the for loop essentially does (it doesnt actually do this but pretty much)
void whatForLoopDoesSortOf() {
  int currentNumber = 1;

  // 1 <= 5 so run the code
  cout << currentNumber << endl;
  currentNumber++;  // increment currentNumber to 2 etc

  // 2 <= 5 so run the code
  cout << currentNumber << endl;
  currentNumber++;

  // 3 <= 5 so run the code
  cout << currentNumber << endl;
  currentNumber++;  

  // 4 <= 5 so run the code
  cout << currentNumber << endl;
  currentNumber++;

  // 4 <= 5 so run the code
  cout << currentNumber << endl;
  currentNumber++;
}


// 5a. if statements
// Should you let a kid go on a rollercoaster?
// Has bugs in it
void ifStatements() {
  int age;
  double heightInM;
  bool isOwnerOfParksKid;
  bool isCrying;

  cout << "How old are they in years: ";
  cin >> age;
  cout << endl;

  cout << "How tall are they in metres: ";
  cin >> heightInM;
  cout << endl;

  cout << "Are they the owners kid: ";
  cin >> isOwnerOfParksKid;
  cout << endl;

  cout << "Are they crying:";
  cin >> isCrying;
  cout << endl;

  if (age > 10) {
    cout << "They're allowed since they're old enough" << endl;
  }

  if (age > 8 && heightInM > 1.2) {
    cout << "They're allowed since they're big enough" << endl;
  }

  if (isOwnerOfParksKid || isCrying) {
    cout << "Letting them in anyway" << endl;
  }

  cout << "Not letting them in!" << endl;
}

// 5b. combined if statements
void combinedIf() {

  // Notice how we need all this code from 5a again??
  // This is the perfect case for a function (see later)
  int age;
  double heightInM;
  bool isOwnerOfParksKid;
  bool isCrying;

  cout << "How old are they in years: ";
  cin >> age;
  cout << endl;

  cout << "How tall are they in metres: ";
  cin >> heightInM;
  cout << endl;

  cout << "Are they the owners kid: ";
  cin >> isOwnerOfParksKid;
  cout << endl;

  cout << "Are they crying:";
  cin >> isCrying;
  cout << endl;

  if (age > 10 || 
    (age > 8 && heightInM > 1.2) ||
    (isCrying || isOwnerOfParksKid)) {
      cout << "Letting them on!" << endl;
  } else {
    cout << "Not letting them on" << endl;
  }
}

// 5c. Nested if statements
void nestedIfAndElseIf() {

  // Too lazy to write all that cin stuff again so just make up values
  int age = 9;
  double heightInM = 1.21;
  bool isOwnersKid = false;
  bool isCrying = false;

  if (age > 10) {
    cout << "Letting them on as they are older than 10" << endl;
  } else {

    // This next bit of code only happens if they are 10 or younger
    // We know that they are DEFINITELY 10 or younger inside of these curly brackets
    // as if they were older than 10 the if statement above would have been true
    // so that code would have ran and not this else code

    if (age > 8 && heightInM > 1.2) {
      cout << "Letting them on as they are over 8 AND above 1.2m";
    } else if (isCrying) {
      cout << "Letting them on as they are crying" << endl;
    } else if (isOwnersKid) {
      cout << "Letting them on as they are the owners kid" << endl;
    } else {
      cout << "Not letting them on" << endl;
    }

  }
}

// What code runs when we run our program
// Just a special function (called main) that returns an int
int main() {

  cout << "1. Printing" << endl;
  basicPrinting();
  cout << endl << endl;

  // cout << "2. Variables" << endl;
  // variables();
  // cout << endl << endl;

  // cout << "3. while loops" << endl;
  // whileLoops();
  // cout << endl << endl;

  // cout << "4a. Without for loops" << endl;
  // withoutForLoop();
  // cout << endl << endl;

  // cout << "4b. With for loops" << endl;
  // withForLoop();
  // cout << endl << endl;

  // cout << "4c. What for loop actually does" << endl;
  // whatForLoopDoesSortOf();
  // cout << endl << endl;

  // cout << "5a. If statements" << endl;
  // ifStatements();
  // cout << endl << endl;

  // cout << "5b. combined if statements" << endl;
  // combinedIf();
  // cout << endl << endl;

  // cout << "5c. Nested if and else if statements" << endl;
  // nestedIfAndElseIf();
  // cout << endl << endl;

  return 0;
}