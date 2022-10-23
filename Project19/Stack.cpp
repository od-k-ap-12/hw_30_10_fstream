#include "Stack.h"
#include <iostream>
using namespace std;

char Stack::GetTopChar() {
	return st[top];
}

Stack::Stack()
{

	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Ïóñò?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}
int Stack::GetCount()
{
	return top + 1;
}

void Stack::Push(char c)
{
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}
void Stack::Output()
{
	for (int i = 0; i < top + 1; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;
}
