//This is a driver program to test the function isPalindrome()
//that tests a line of text to see if it is a palindrome.

#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

bool isPalindrome(string text);
//Function to test whether a line of text is a palindrome.
//Precondition: text.length() > 0 and text contains no punctuation.
//Postcondition: Returned true if text is a palindrome, otherwise
//  false.

int main()
{
    string text;

    cout << "Please enter a line of text without punctuation: ";
    getline(cin, text, '\n');

    cout << text << (isPalindrome(text) ? " is " : " is not ")
         << "a palindrome." << endl;

    return 0;
}

bool isPalindrome(string text)
{
    assert(text.length() > 0);

    queue<char> forwards;
    stack<char> backwards;

    for (int i = 0; i < text.length(); ++i) {
        if (!isspace(text.at(i))) {
            forwards.push(tolower(text.at(i)));
            backwards.push((text.at(i)));
        }
    }

    for (int i = 0; i < forwards.size(); ++i) {
        if (forwards.front() != backwards.top())
            return false;
        forwards.pop();
        backwards.pop();
    }

    return true;
}
