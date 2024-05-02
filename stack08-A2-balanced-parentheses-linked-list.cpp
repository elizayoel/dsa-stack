#include<iostream>

using namespace std;

struct Node {
	char ch;
	Node* next;
};
Node* createNewNode(char ch) {
	Node* nnode = new Node();
	nnode->ch = ch;
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
	void push(char ch) {
		Node* nnode = createNewNode(ch);
		if (top == nullptr) {
			top = nnode;
		}
		else {
			nnode->next = top;
			top = nnode;
		}
		size++;
	}
	char pop() {
		char poppedChar;
		if (!isEmpty()) {
			Node* temp = top;
			if (top->next == nullptr) { //cuma sebiji
				poppedChar = top->ch;
				top = nullptr;
			}
			else {

				poppedChar = top->ch;
				top = top->next;
			}
			delete temp;
			size--;
			return poppedChar;
		}
		else {
			cout << "List is empty, can't pop." << endl;
		}
	}
	void display() {
		Node* temp = top;
		cout << "nullptr" << "<-";
		while (temp != nullptr) {
			cout << temp->ch << "<-";
			temp = temp->next;
		}
		cout << endl;
	}
	void displayBawah() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << "|"<<temp->ch << "|" << endl;
			temp = temp->next;
		}
		cout << "---" << endl;
	}
	bool checkSymbol(char xsymbol) {
		if (top->ch == xsymbol) {
			return true;
		}
		else {
			return false;
		}
	}
	char peek() {
		return top->ch;
	}
	Node* getTop() {
		return top;
	}
};

/*int main() {
	string equ = "";
	Stack s;
	cout << "Enter your equation here (without any space): " << endl;
	cin >> equ;

	for (int i = 0; i < equ.length(); i++) {
		bool answer = false;
		char each = equ[i];
		if (each == '(' || each == '{' || each == '[') {
			s.push(each);
		}
		else if (each == ')' || each == ']' || each == '}') {
			char xsymbol;
			switch (each) {
			case')':xsymbol = '('; break;
			case'}':xsymbol = '{'; break;
			case']':xsymbol = '['; break;
			}
			//check the antonym of the symbol to the top
			//kalau sama, betul, brti pop
			answer = s.checkSymbol(xsymbol);
			if (answer == true) {
				s.pop();
			}
			else {
				cout << "Equation is not balance in parentheses section. Parentheses in position " << i + 1 << " is having error!" << endl;
				exit(1);
			}
		}//number, alphabeth, or operators are ignored, continue looping
	}

	if (s.getTop() != nullptr) {
		cout << "Equation is not balance because still have LEFT PARENTHESES in stack. Missing of RIGH PARENTHESES." << endl;
		exit(1);
	}
	//if all free from bugs and the stack is empty
	cout << "Equation is balance and correct. You may proceed with the calculation now" << endl;
	return 0;

}*/