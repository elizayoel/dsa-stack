#include<iostream>
#include<string>
using namespace std;

struct Node {
	char ch;
	Node* next;
};

Node* createNewNodes(char ch) {
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
		Node* nnode = createNewNodes(ch);
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
			if (top->next == nullptr) { //cuma sebiji
				poppedChar = top->ch;
				top = nullptr;
			}
			else {
				Node* temp = top;
				poppedChar = top->ch;
				top = top->next;
				delete temp;
			}
			size--;
			return poppedChar;
		}
		else {
			cout << "List is empty, can't pop." << endl;
			return '\0';
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
			cout << "|" << temp->ch << "|" << endl;
			temp = temp->next;
		}
		cout << "---" << endl;
	}
	
	char peek() {
		return top->ch;
	}
	Node* getTop() {
		return top;
	}
};
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}
bool isOperand(char c) {
	if (c >= 'A' && c <= 'Z')
		return true;
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}
bool equalOrHigher(char op1, char op2) {
	int p1 = precedence(op1);
	int p2 = precedence(op2);
	if (p1 == p2) {
		if (op1 == '^')
			return false; //pangkat ketemu pangkat bs lebih tinggi, brti bs dimasukin
		return true;
	}
	return (p1 >= p2);
	/*ternary operator ? :
	compare p1 and p2, return either true or false
	equals to
	if(p1>p2)
		return true;
	else
		return false;
	*/
}
/*int main() {
	//initialize stack
	Stack s;
	//equation
	string infix = "";
	string postfix = "";
	cout << "Enter your equation here : ";
	getline(cin, infix);
	//scan infix from left to right
	for (int i = 0; i < infix.length(); i++) {
		char each = infix[i];
		if (each == '(') {
			s.push(each);
		}
		else if (each == ' ') {
			continue;
		}
		else if (isOperand(each)) {
			postfix += each;
			//handle multiple operands
			while (i + 1 < infix.length() && isOperand(infix[i + 1])) {
				postfix += infix[++i];
			}
		}
		else if (isOperator(each)) {
			while (!s.isEmpty() && equalOrHigher(s.peek(), each)) {
				//selama topnya lebih besar drpd char baru
				//harus dibuang, krn urutannya dr kecil-besar
				//kalo posisinya sama, harus dibuang juga 
				//kalo dah habis ga ada yang bisa dibuang
				postfix += s.pop();
			}
			s.push(each);
		}
		else if (each == ')') {
			while (!s.isEmpty() && s.peek() != '(') {
				//kalau sudah ketemu (, stop popping
				postfix += s.pop();
			}
			s.pop(); //pop (
		}
	}
	while (!s.isEmpty()) {
		postfix += s.pop();
	}

	cout << "The postfix expression is " << postfix << endl;
}*/