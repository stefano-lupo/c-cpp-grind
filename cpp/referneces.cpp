#include<iostream>
using namespace std;

void functionsGetOwnCopiesByDefault(int someNumber) {
  someNumber = 99;

  cout << "Function has changed someNumber to: " << someNumber << endl;
}

void getKidRolercosterInfo(int& age, double& heightInM, bool& isCrying, bool& isOwnerOfParksKid) {
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
}

int main() {

  cout << "1: Functions get their own copy of variables by default" << endl;
  int someNumber = 0;
  cout << "someNumber before calling function is: " << someNumber << endl;
  functionsGetOwnCopiesByDefault(someNumber);
  cout << "someNumber after calling function is: " << someNumber << endl;
  cout << endl << endl;

  // How to use references to variables to set values in void functions
  // int age;
  // double heightInM;
  // bool isCrying;
  // bool isOwnerOfParksKid;

  // getKidRolercosterInfo(age, heightInM, isCrying, isOwnerOfParksKid);

  // cout << "The values should now have been set by the getKidRolercosterInfo function" << endl;
  // cout << "Age: " << age << endl;
  // cout << "heightInM: " << heightInM << endl;
  // cout << "isCrying: " << isCrying << endl;
  // cout << "isOwnerOfParksKid: " << isOwnerOfParksKid << endl;
}