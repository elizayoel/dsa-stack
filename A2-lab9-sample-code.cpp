/*
* Exercise 1: to learn how to make a program to check whether the parentheses are balance
* in an equation or not.
* e.g. (a+b)-b*c
*/

#include <iostream>
#include <string>

using namespace std;

//create the stack structure
struct stack
{
	char data;
	stack* next;
	stack* previous;
} *top, * bottom;

//functions
stack* createnewnode(char data)
{
	stack* newnode = new stack;
	newnode->data = data;
	newnode->next = NULL;
	newnode->previous = NULL;
	return newnode;
}

void push(char data)
{
	stack* newnode = createnewnode(data);

	if (top == NULL)
	{
		top = bottom = newnode;
	}
	else
	{
		top->next = newnode;
		newnode->previous = top;
		top = newnode;
	}
}

char pop()
{
	//check error 3: whether the pop function able remove stg or not?
	if (top == NULL)
	{
		cout << "Parentheses is not balance where one of the left parentheses is missing! " << endl;
		exit(1);
	}

	stack* temp = top;
	char returnstacksymbol = temp->data;

	if (top == bottom)
	{
		top = bottom = NULL;
	}
	else
	{
		top = top->previous;
		top->next = NULL;
	}

	delete temp;
	return returnstacksymbol;
}

bool checkparenthesesformat(char data, char compare)
{
	if (data == compare)
		return true;
	else
		return false;
}

/*int main()
{
	top = bottom = NULL;

	//create variables that required to use
	string equation = "";
	char returnstackvalue = '\0';
	bool answer = true;

	//read the equation from user
	cout << "Enter your equation at here (without any space between the chars) : ";
	cin >> equation;

	//start to check - read from left char to the right char in the equation
	for (int i = 0; i < equation.length(); i++)
	{ 
		//1. if meet the '(' , push to the stack
		if (equation[i] == '(' || equation[i] == '{' || equation[i] == '[')
		{
			push(equation[i]);
		}
		//2. if meet the ')', pop from the stack and compare
		else if (equation[i] == ')' || equation[i] == '}' || equation[i] == ']')
		{
			returnstackvalue = pop();

			char correctsymbol;

			switch (equation[i])
			{
			case ')': correctsymbol = '('; break;
			case '}': correctsymbol = '{'; break;
			case ']': correctsymbol = '['; break;
			}

			answer = checkparenthesesformat(returnstackvalue, correctsymbol);

			//error 1: design not same, cout error and not balance and exit the program
			if (answer == false)
			{
				cout << "Equation is not balance in parentheses section. Parentheses in position " << i + 1 << " is having error! " << endl;
				exit(1);
			}
		}
		//3. if meet the alphabet or number, then ignore that alphabet / number and continue looping.
	}

	//check 2nd error : is it the stack still fill with any item?
	if (top != NULL)
	{
		cout << "Equation is not balance in parentheses because still have left parentheses in stack. Missing of right parentheses!" << endl;
		exit(1);
	}
	//if all free from bugs, then this means equation is not parentheses issue!
	cout << "Equation is balance and correct. You may proceed with the calculation now! " << endl;
	return 0;
}*/