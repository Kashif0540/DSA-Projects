#pragma once
#include "Stack.h"

template <class T>
class myStack :public Stack<T>
{
public:
	void push(T value);
	T pop();
	T top();
	myStack(int s);
	void display();
	bool isEmpty();
	bool isFull();
};

template <class T>
bool myStack<T>::isFull()
{
	return Stack<T>::currentSize == Stack<T>::maxSize;
}

template <class T>
bool myStack<T>::isEmpty()
{
	return Stack<T>::currentSize == 0;
}

template <class T>
void myStack<T>::display()
{
	cout << "Max Size = " << Stack<T>::maxSize << endl;
	cout << "Current Size = " << Stack<T>::currentSize << endl;

	for (int i = 0; i < Stack<T>::currentSize; i++)
		cout << i << ". " << Stack<T>::arr[i] << endl;
}

template <class T>
myStack<T>::myStack(int s) :Stack<T>(s)
{

}

template <class T>
void myStack<T>::push(T value)
{
	if (isFull())
	{
		cout << "Stack is Full" << endl;
	}
	else
	{
		Stack<T>::arr[Stack<T>::currentSize] = value;
		Stack<T>::currentSize++;
	}

}

template <class T>
T myStack<T>::top()
{
	if (isEmpty())
	{
		cout << "Stack in Empty" << endl;
		return NULL;
	}

	else
	{
		return Stack<T>::arr[Stack<T>::currentSize - 1];
	}
}

template <class T>
T myStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack in Empty" << endl;
		return NULL;
	}

	else
	{
		Stack<T>::currentSize--;
		return Stack<T>::arr[Stack<T>::currentSize];
	}
}