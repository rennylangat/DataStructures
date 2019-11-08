#pragma once
#pragma once
#include <iostream>
#include <string>
#include "list.h"


template <class T>
class Stack : protected LinkedList<T>
{
	public:
		Stack<T>() {} 
		~Stack<T>();

		void push(T);
		void pop(T&);
		bool isEmpty();
		T stackTop();
};

template <class T>
Stack<T>::~Stack<T>()
{
	T del;
	while (!isEmpty())
		pop(del);

}

// Inserting a new node to the top of the stack. 
// Pre:New node value T val 
// Post:val passed to insert
// Return: None
template <class T>
void Stack<T>::push(T val)
{
	this->insert(val);
}

// Popping up top from the stack. 
// Pre:New node value T val1 
// Post:val1 equals top of stack which is return from stackTop()
// Return:None
template <class T>
void Stack<T>::pop(T & val1) {
	try
	{
		val1 = stackTop();
		//head = head->getlink();
		this->delete_front();

	}

	catch (std::string e)
	{
		std::cout << e << std::endl;
		system("pause");
	}

}
// Checks if stack is empty or not
// Pre: none
// Post: none
// Returns true if stack is empty
// else false
template <class T>
bool Stack<T>::isEmpty()
{
	bool flag = false;
	if (!this->head && this->count==0)
		flag = true;
	return flag;

}

// Returns top of the stack node
// Pre: None
// Post: if it is empty throw exception.
// Return: Value in the head pointing node
template <class T>
T Stack<T>::stackTop()
{
	std::string e;
	if (isEmpty())
	{
		std::string e = "Stack is Empty";
		throw e;
	}
	

	return (this->head)->getvlue();//(this->getHead())->val;
	
}