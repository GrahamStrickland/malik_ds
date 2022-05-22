// This is a driver program to test the ADT linkedStackType.

#include <iostream>
#include "linkedStack.h"

using namespace std;

int main()
{
    linkedStackType<int> stack1, stack2;

    stack1.push(1);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(5);
    stack1.push(8);
    stack1.push(13);

    cout << (stack1 == stack2 ? "stack1 == stack2" : "stack1 != stack2") << endl;

    linkedStackType<int> stack3;

    stack3 = stack1;

    cout << (stack1 == stack3 ? "stack1 == stack3" : "stack1 != stack2") << endl;

    stack1.reverseStack(stack2);

    cout << "stack1: ";
    while (!stack1.isEmptyStack())
    {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;

    cout << "stack2: ";
    while (!stack2.isEmptyStack())
    {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout << endl;

    return 0;
}
