#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

class Stack {
private:
	Node* top;
	int size;
public:
	Stack() {
		top = nullptr;
		size = 0;
	}
	Node* createNewNode(int val) {
		Node* nnode = new Node;
		nnode->val = val;
		nnode->next = nullptr;
		return nnode;
	}
	void push(int val) {
		Node* nnode = createNewNode(val);
		if (top == nullptr) {
			top = nnode;
		}
		else {
			nnode->next = top;
			top = nnode;
		}
		size++;
	}
	int pop() {
		if (top == nullptr) {
			cout << "The stack is empty." << endl;
			return 0;
		}
		Node* currTop = top;
		top = top->next;
		int poppedValue = currTop->val;
		delete currTop;
		size--;
		return poppedValue;
	}
	bool isEmpty() {
		return size == 0;
	}
	void display() {
		if (isEmpty()) {
			cout << "The stack is empty" << endl;
			return;
		}
		Node* current = top;
		while (current != nullptr) {
			cout << current->val << "->";
			current = current->next;
		}
		cout << "nullptr" << endl;
	}
	void displayBelow() {
		if (isEmpty()) {
			cout << "The stack is empty" << endl;
			return;
		}
		Node* current = top;
		while (current != nullptr) {
			cout << current->val << endl;
			current = current->next;
		}
		cout << "nullptr" << endl;
	}
};

/*int main() {
	Stack s1;
	string exp;
	cout << "Enter postfix expression without space" << endl;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++) {
		char each = exp[i];
		if (each >= '0' && each <= '9') { //kalau angka
			s1.push(each - '0'); //to change into integer using ascii value
			s1.displayBelow();
			cout << endl;
		}
		else if (each == '+' || each == '-' || each == '*' || each == '/') {
			int c = 0;
			int a = s1.pop();//paling atas
			s1.displayBelow(); cout << endl;
			int b = s1.pop();//bawahnya
			s1.displayBelow();
			cout << endl;
			//atau bisa juga dipisah pop dan getTop
			if (each == '+') {
				c = b + a;
			}
			else if (each == '-') {
				c = b - a;
			}
			else if (each == '*') {
				c = b * a;
			}
			else if (each == '/') {
				c = b / a;
			}
			s1.push(c);
		}
	}
	s1.displayBelow();
}*/