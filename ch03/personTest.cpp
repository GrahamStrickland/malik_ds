#include "personType.h"
#include <iostream>
#include <string>

int main() {
  using namespace std;

  personType person1;
  personType person2("Bertrand", "Russell");

  cout << "The name of person2 is ";
  person2.print();
  cout << endl;

  string firstName = person2.getFirstName();
  string lastName = person2.getLastName();
  person1.setName(firstName, lastName);

  cout << "\nThe name of person1 is ";
  person1.print();
  cout << endl;

  cout << "\nPlease enter a new name for person1: ";
  cin >> firstName >> lastName;
  person1.setName(firstName, lastName);

  cout << "\nperson1\'s new name is ";
  person1.print();
  cout << endl;

  return 0;
}
