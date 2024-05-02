#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
	int val;
	Node* next;
};
Node* createNode(int val) {
	Node* nnode;
	nnode->val = val;
	nnode->next = nullptr;
	return nnode;
}
class Stack {
private:
	Node* top;
	int size;
public:
	Stack() {
		top = nullptr;
		size = 0;
	}
	bool isEmpty() {
		return top == nullptr;
	}
	void push(int val) {
		Node* nnode = createNode(val);
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
		int poppedValue;
		if (isEmpty()) {
			cout << "List is empty, can't pop any value." << endl;
			return -1;
		}
		Node* temp = top;
		poppedValue = top->val;
		if (top->next = nullptr) {
			top = nullptr;
		}
		else {
			top = top->next;
		}
		delete temp;
		size--;
		return poppedValue;
	}
	void displayBawah() {
		Node* temp = top;
		while (temp != nullptr) {
			cout <<"|"<< setw(4)<<temp->val << "|" << endl;
			temp = temp->next;
		}
		cout << "---" << endl;
	}
	int peek() {
		return top->val;
	}
};
int main() {

}