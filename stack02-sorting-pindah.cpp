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
	void push(int val) {
		Node* nnode = new Node;
		nnode->val = val;
		if (isEmpty()) {
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
			cout << "Cannot pop, stack is empty." << endl;
		}
		else if (top->next == nullptr) {
			delete top;
		}
		else {
			Node* prev = top;
			top = top->next;
			delete prev;
		}
		size--;
	}
	Node* getTop() {
		return top;
	}
	bool isEmpty() {
		return size == 0;
	}
	void display() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}
		Node* current = top;
		cout << "nullptr" << "<-";
		//while (current->next != nullptr) {
		while(current != nullptr){ //karena kalo current = top = null, next nya gabisa null
			cout << current->val << "<-";
			current = current->next;
		}
		
	}
	void displayBelow() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
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
	Stack s1; Stack s2;
	int menu = -1;
	while (menu != 0) {
		cout << "1. Push & sort" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Print samping" << endl;
		cout << "4. Print bawah" << endl;
		cout << "Option : " << endl;
		cin >> menu;
		if (menu == 1) {
			int val;
			cout << "Enter val : " << endl;
			cin >> val;
			if (s1.isEmpty()) {
				s1.push(val);
			}
			else {
				while (s1.getTop()->val < val && !s1.isEmpty()) {
					cout << "s1 "; s1.display();
					s2.push(s1.getTop()->val);
					cout << "s2 "; s2.display();
					s1.pop();
					cout << "s1 "; s1.display();
				}
				s1.push(val);
				cout << "s1 ";  s1.display();
				while (!s2.isEmpty()) {
					s1.push(s2.getTop()->val);
					cout << "s1 ";  s1.display();
					s2.pop();
					cout << "s2 "; s2.display();
				}
			}
		}
		else if (menu == 2) {
			s1.pop();
		}
		else if (menu == 3) {
			cout << "S1" << endl;
			s1.display();
			cout << endl;
			cout << "S2" << endl;
			s2.display();
			cout << endl;
		}
		else if (menu == 4) {
			cout << "S1" << endl;
			s1.displayBelow();
			cout << endl;
			cout << "S2" << endl;
			s2.displayBelow();
			cout << endl;
		}
	}
}*/