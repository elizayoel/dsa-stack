#include <iostream>
#include<iomanip>
#include<string>

using namespace std;

class Stack {
	string* list; //dynamic memory allocation = allocate memory for the stack's array 
	//based on user's specified size, using constructor later
	//deallocation = destructor, avoid memory leaks
	//array is static in nature -> size is fixed at compile time
	//in a stack, number of elements can changed as element pushed and popped
	//supaya bs grow and shrink as needed
	int maxStack;
	int stackTop;
public:
	Stack(int maxSize) {
		list = new string[maxSize];
		maxStack = maxSize;
		stackTop = -1;
	}
	~Stack() {
		delete[]list;
	}
	string pop() {
		if (!isEmpty()) {
			return list[stackTop--];
		}
		else {
			cout << "Array is empty, can't pop anything." << endl;
			return "";
		}
	}
	void push(string subj){
		if (!isFull()) {
			list[++stackTop] = subj;
		}
		else {
			cout << "Array is already full." << endl;

		}
	}
	bool isEmpty() {
		return stackTop == -1;
	}
	bool isFull() {
		return stackTop == maxStack - 1;
	}
	string peek() {
		if (!isEmpty()) {
			return list[stackTop];
		}
		else {
			cout << "Error" << endl;
			return"empty";
		}
	}
	void display() {
		for (int i = stackTop; i >= 0; i--) {
			cout << "|" << setw(10)<<list[i] << "|" << endl;
		}
		cout << "------------" << endl;
	}
};

/*int main() {
	int menu = -1;
	Stack s(10);//kalau gapake* gausah pake new
	while (menu != 0) {
		cout << "1. push" << endl << "2. pop" <<endl<< "3. peek"<<endl<<"4. display" << endl << "option : ";
		cin >> menu;
		cin.ignore();
		if (menu == 1) {
			string subj = "";
			cout << "Enter school subject : " << endl;
			getline(cin, subj); //#include <string>
			s.push(subj);
		}
		else if (menu == 2) {
			s.pop();
		}
		else if (menu == 3) {
			string top = s.peek();
			cout << "The top is " << top << endl;
		}
		else if (menu == 4) {
			s.display();
		}
	}
}*/