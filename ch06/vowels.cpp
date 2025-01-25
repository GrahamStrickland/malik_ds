// Driver program to test recursive function vowels()
// which returns the number of vowels in an input string.

#include <iostream>
#include <string>

using namespace std;

int vowels(string str);

int main() {
  string str;

  cout << "Please enter an input string: ";
  getline(cin, str);

  cout << "Number of vowels in \"" << str << "\" = " << vowels(str) << endl;

  return 0;
}

int vowels(string str) {
  if (str.size() == 0)
    return 0;
  else {
    switch (str.at(0)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1 + vowels(str.substr(1, str.size() - 1));
      break;
    default:
      return vowels(str.substr(1, str.size() - 1));
      break;
    }
  }
}
