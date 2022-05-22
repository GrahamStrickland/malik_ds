// This is a driver program to test the array-based stackType ADT.

#include <iostream>
#include "arrStack.h"

using namespace std;

int main()
{
    stackType<int> stack1, stack2(50);

    cout << (stack1 == stack2 ? "stack1 == stack2" : "stack1 != stack2") << endl;

    stack1.push(6);
    stack1.push(36);
    stack1.push(216);

    stackType<int> stack3;
    stack3 = stack1;

    cout << (stack1 == stack3 ? "stack1 == stack3" : "stack1 != stack3") << endl;

    stack1.reverseStack(stack2);

    cout << "stack1: ";
    while (!stack1.isEmptyStack()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;

    cout << "stack2: ";
    while (!stack2.isEmptyStack()) {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout << endl;

    return 0;
}
