//like undo and redo fifo
#include <iostream>
#include <stack>

using namespace std;

void printStackElements(stack<int> stack) {
	//ask top element, write, pop it out
	//while stack is not empty or greater than 0
	while (!stack.empty()) {
		cout << stack.top() << endl;
		stack.pop();
	}
}
/*int main() {
	//empty, size, push, pop, top
	stack<int> numbersStack;

	numbersStack.push(1);
	numbersStack.push(5);
	numbersStack.push(2);

	numbersStack.pop();
	numbersStack.pop();
	numbersStack.push(2);
	numbersStack.push(3);
	numbersStack.push(4);

	printStackElements(numbersStack);
	if (numbersStack.empty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	cout << "Stack size is " << numbersStack.size() << endl;
}*/

/*
functions:
stack is empty or not
size of stack = how many elements
give top element of stack
add element into stack = push
remove element = pop
*/
