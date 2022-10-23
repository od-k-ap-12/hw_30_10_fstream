#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

bool BracketCheckout(char* string) {
	Stack BC;
	char c;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == '<' || string[i] == '>' ) {
			c = string[i];
			if (c == '<') {
				BC.Push(c);
			}
			else if (c == '>') {
				if (BC.IsEmpty() || BC.GetTopChar() != '<') {
					return false;
				}
				else {
					BC.Pop();
				}
			}

		}
		else {
			continue;
		}
	}
	return true;
}
int main()
{
	cout << "Enter file path: ";
	string path;
	cin >> path;
	fstream check;
	check.open(path,fstream::in|fstream::out|fstream::app);
	char file[200];
	if (!check.is_open()){
		cout << "Can't open. Path might be wrong.";
	}
	else {
		int i = 0;
		while (!check.eof())
		{
			file[i] = check.get();
			cout << file[i];
			i++;
		}
		check.close();
	}
	cout << BracketCheckout(file);
}