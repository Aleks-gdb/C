#include "StackNode.h"
#include "Stack.h"

int main()
{
	string postfix;
	string infix;
	int result;
	char ans = 'y';
	while (ans == 'y')
	{
		cout << "Please enter an infix arithmetic expression:\n";
		cin >> infix;
		postfix = convertToPostfix(infix);
		if (postfix != "") //validating user input for the expression
		{
			cout << "Here is the postfix arithmetic expression:\n" << postfix << endl;
			result = evaluatePostfixExpression(postfix);
			cout << "Evaluated value: " << result << endl;
		}
		for(;;)//validating user input for continuation
		{ 
			cout << "Would you like to continue? (y/n)\n";
			cin >> ans;
			tolower(ans);
			if (ans != 'y' && ans != 'n')
			{
				cout << "Please answer yes or no.\n";
			}
			else
				break;
		}
	}
	system("pause");
	return 0;
}

#pragma once
//StackNode.h for the struct Node
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
};

#pragma once
//Stack.h for the stack and functions
#include "StackNode.h"
#include <math.h>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
template<typename T>
struct Stack
{
	Node<T>* top;
	int count;
public:
	Stack()
	{
		top = NULL;
		count = 0;
	}
	void push(T element); //add an element to the stack
	void pop(); //take an element out of the stack
	void print(); //print the stack
	bool isEmpty(); //check if the stack is empty
};

string convertToPostfix(string strinf); //convert infix to postfix
bool isOperator(char c); //check if the character is an operator
bool precedence(char o1, char o2); //determine the precedence of operators
template<typename T>
T stackTop(); //return the top item in the stack
int evaluatePostfixExpression(string post); //evaluate the postfix expression
int calculate(int op1, char operation, int op2); //calculate the current operation in the postfix expression


//Stack.cpp to store and divide the strings
#include "StackNode.h"
#include "Stack.h"
int count;
template<typename T>
bool Stack<T>::isEmpty() //check if the stack is empty
{
	if (top == NULL)
		return true;
	else
		return false;
}
template<typename T>
void Stack<T>::push(T element) //add an element to the stack
{
	Node<T>* newNode = new Node<T>;
	if (top == NULL)
	{
		newNode->data = element;
		newNode->next = NULL;
		top = newNode;
		count++;
	}
	else
	{
		newNode->data = element;
		newNode->next = top;
		top = newNode;
		count++;
	}
}

template<typename T>
void Stack<T>::pop() //take an element out of the stack
{
	if (top != NULL)
	{
		Node<T>* deleteNode = top;
		top = top->next;
		count--;
		delete deleteNode;
	}
	else
	{

	}
}
template<typename T>
void Stack<T>::print() //print the stack
{
	Node<T>* temp;
	temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
string convertToPostfix(string strinf) //convert infix to postfix
{
	Stack<char>* infixStack = new Stack<char>;
	string postfix = "";
	string infix = strinf + ')';
	infixStack->push('(');
	int exit = 0; //validate input
	while (!infixStack->isEmpty()) //while stack is not empty
	{
		for (int i = 0; i < infix.length(); i++) //for the length of the expression
		{
			if (isdigit(infix[i]) || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || 
				infix[i] == '%' || infix[i] == '^' || infix[i] == ' ' || infix[i] == ')' || infix[i] == '(')
			{
				if (infix[i] == ' ' || infix[i] == ',') continue; //if a white space or a comma, skip
				if (isdigit(infix[i]))
					postfix += infix[i];
				if (infix[i] == '(')
					infixStack->push(infix[i]);
				if (isOperator(infix[i]))
				{
					while (!infixStack->isEmpty() && infixStack->top->data != '(' && precedence(infixStack->top->data, infix[i]))
					{
						postfix += infixStack->top->data;
						infixStack->pop();
					}
					infixStack->push(infix[i]);
				}
				if (infix[i] == ')')
				{
					while (!infixStack->isEmpty() && infixStack->top->data != '(')
					{
						postfix += infixStack->top->data;
						infixStack->pop();
					}
					infixStack->pop();
				}
			}
			else
			{
				//cout << infix[i]<< endl;
				cout << "The expression contains invalid characters.\n";
				exit = 1;
				break;
			}
		}
		if (exit == 1)
			break;
	}
	if (exit == 1)
		return "";
	else
		return postfix;
}

bool isOperator(char c) //check if the character is an operator
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return true;
	else
		return false;
}

bool precedence(char o1, char o2) //determine the precedence of operators
{
	int weight1, weight2;
	switch (o1)
	{
	case '+':
	case '-':
		weight1 = 1;
		break;
	case '*':
	case '/':
		weight1 = 2;
		break;
	case '%':
		weight1 = 3;
		break;
	case '^':
		weight1 = 4;
		break;
	}

	switch (o2)
	{
	case '+':
	case '-':
		weight2 = 1;
		break;
	case '*':
	case '/':
		weight2 = 2;
		break;
	case '%':
		weight2 = 3;
		break;
	case '^':
		weight2 = 4;
		break;
	}
	if (weight1 >= weight2)
		return true;
	else
		return false;
}
template<typename T>
T stackTop() //return the top item in the stack
{
	return top->data;
}

int evaluatePostfixExpression(string post) //evaluate the postfix expression
{
	Stack<char>* postfixStack = new Stack<char>;
	string postfix = post;
	int x, y, result = 0, exit = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i]))
			postfixStack->push((postfix[i] - '0'));
		if (isOperator(postfix[i]))
		{
			x = postfixStack->top->data;
			postfixStack->pop();
			y = postfixStack->top->data;
			postfixStack->pop();
			result = calculate(y, postfix[i], x);
			postfixStack->push(result);
		}
	}
	return result;
}

int calculate(int op1, char operation, int op2) //calculate the current operation in the postfix expression
{
	int result = 0;
	switch (operation)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	case '%':
		result = op1 % op2;
		break;
	case '^':
		result = pow(op1,op2);
		break;
	}
	return result;
}
