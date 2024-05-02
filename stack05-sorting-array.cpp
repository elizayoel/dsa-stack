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
		delete[]list;
	}
	void push(int val) {
		if (!isFull()) {
			list[++stackTop] = val;
		}
		else {
			cout << "The array is full" << endl;
		}
	}
	int pop() {
		if (!isEmpty()) {
			return list[stackTop--];
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
			cout << list[i] << " ";
		}
		cout << endl;
	}
	
};

/*int main() {
	Stack s(5);
	Stack s2(5);
	while (!s.isFull()) {
		int val = 0;
		cout << "Enter random integer value and we will sort it (top = smallest number)." << endl;
		cin >> val;

		//kalau kosong
		if (s.isEmpty()) {
			s.push(val);
		}
		else {
			while (!s.isEmpty() && s.peek() < val) { //the loop will continue as long as the stack is not empty. if empty, then cannot do anything
				s2.push(s.peek());
				s.pop();
			}
			s.push(val);
			while (!s2.isEmpty()) {
				s.push(s2.peek());
				s2.pop();
			}
		}
	}
	s.displayList();
}*/