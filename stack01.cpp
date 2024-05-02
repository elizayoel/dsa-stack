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
	void push(int value) {
		Node* nnode = new Node;
		nnode->val = value;
		if (top == NULL) {
			top = nnode;
			nnode->next = nullptr;
		}
		else {
			nnode->next = top;
			top = nnode;
		}
		size++;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty. Cannot pop." << endl;
			return;
		}
		if (top->next == NULL) {
			delete top;
			top = NULL;
		}
		else {
			Node* prev = top;
			top = top->next;
			delete prev;
		}
		size--;
	}
	bool isEmpty() {
		return size == 0;
	}
	Node* getTop() {
		return top;
	}
	void printStack() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}
		Node* current = top;
		while (current->next != nullptr) {
			cout << current->val << "->";
			current = current->next;
		}
		cout << current->val << endl;
	}
};
/*int main() {
	Stack s1;
	int menu = -1;
	while (menu != 0) {
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Print" << endl;
		cout << "Option : " << endl;
		cin >> menu;
		if (menu == 1) {
			int val;
			cout << "Enter val : " << endl;
			cin >> val;
			s1.push(val);

		}
		else if(menu == 2) {
			s1.pop();
		}
		else if (menu == 3) {
			s1.printStack();
		}
	}
}*/