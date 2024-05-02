#include<iostream>
using namespace std;

class Stack {
	int* list;
	int stackTop;
	int maxStackSize;
public:
	Stack(int maxSize) {
		list = new int[maxSize];
		maxStackSize = maxSize;
		stackTop = -1;
	}
	~Stack() {
		delete[] list;
	}
	void push(int val) {
		if (!isFull()) {
			list[++stackTop] = val;
		}
		else
			//error or expand list
			cout << "The array size reached maximum." << endl;
	}
	int pop() {
		if (!isEmpty()) {
			return list[stackTop--]; //return the original value before decrement, then decrement
		}
		else {
			cout << "Error" << endl;
			return -1;
		}
	}
	int peek() {
		if (!isEmpty()) {
			return list[stackTop];
		}
		else {
			cout << "The stack is empty" << endl;
			return -1;
		}
	}
	bool isEmpty() {
		return stackTop == -1;
	}
	bool isFull() {
		return stackTop == maxStackSize - 1;
	}
	void displayList() {
		for (int i = 0; i < maxStackSize; i++) {
			cout << list[i];
		}
	}
};
/*int main() {
	Stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.displayList();
}*/