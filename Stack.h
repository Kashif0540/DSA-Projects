#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	Stack(int size);
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T top() = 0;
};

template <class T>
Stack<T>::Stack(int size)
{
	maxSize = size;
	currentSize = 0;
	arr = new T[size];
}