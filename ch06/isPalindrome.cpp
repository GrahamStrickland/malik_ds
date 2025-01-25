// Driver program to test if a string is a palindrome.

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);
// Postcondition: Returned true if str is a palindrome,
//  otherwise returned false.

int main() {
  string str;

  cout << "Please enter a string to check if it is a palindrome: ";
  getline(cin, str);

  cout << str << " is" << (isPalindrome(str) ? "" : " not") << " a palindrome."
       << endl;

  return 0;
}

bool isPalindrome(string str) {
  // Find position of first and last alphabetic character.
  int first = 0, last = str.size() - 1;
  while (!isalpha(str.at(first)) && first < last)
    first++;
  while (!isalpha(str.at(last)) && last > first)
    last--;

  // Check if alphabetic characters are equal.
  if (tolower(str.at(first)) != tolower(str.at(last)))
    return false;
  else if (str.size() > 2)
    return isPalindrome(str.substr(first + 1, last - 1));
  else
    return true;
}
