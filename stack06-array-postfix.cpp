#include<iostream>
#include<iomanip>

using namespace std;

class Stack {
//automatically declared as private member
	int* list;
	int maxStackSize;
	int stackTop;
public:
	Stack(int maxSize) {
		list = new int[maxSize];
		maxStackSize = maxSize;
		stackTop = -1;
	}
	~Stack() {
		delete[]list;
	}
	bool isEmpty() {
		return stackTop == -1;
	}
	bool isFull() {
		return stackTop == maxStackSize - 1;
	}
	void push(int val) {
		if (!isFull()) {
			list[++stackTop] = val;
		}
		else {
			cout << "Array is already full." << endl;
		}
	}
	int pop() {
		if (!isEmpty()) {
			return list[stackTop--];//diambil dulu brp value, habis tu dihapus
		}
	}
	int peek() {
		return list[stackTop];
	}
	void displayList() {
		for (int i = stackTop; i >= 0 ; i--) {
			cout << "|"<<setw(3)<<list[i]<<"|"<<endl;
		}
		cout << "----" << endl;
		cout << endl;
	}
};

/*int main() {
	Stack s(10);
	string exp;
	cout << "Enter postfix expression no more than 10 characters without space." << endl;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++) {
		char cut = exp[i];
		if(cut >= '0' && cut <= '9') {
			s.push(cut - '0');
			s.displayList(); 
		}
		else if (cut == '+' || cut == '-' || cut == '*' || cut == '/' || cut == '^') {
			int c = 0;
			int a = s.pop();

			int b = s.pop();

			if (cut == '+') {
				c = b + a;
			}
			else if (cut == '-') {
				c = b - a;
			}
			else if (cut == '*') {
				c = b * a;
			}
			else if (cut == '/') {
				c = b / a;
			}
			s.push(c);
			s.displayList();
		}
	}
}*/