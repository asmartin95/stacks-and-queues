/*
Name: Alec Martin + Abdullah Alsayyar
Summary: First takes a character s or q for stack or queue and then
gives several options to create/edit/print the stack/queue
*/

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "stack.h"
#include "queue.h"

typedef string Type;

using namespace std;

int main(int argc, char * argv[]) {
	stack<Type> *stack1 = new stack<Type>();
	queue<Type> *queue1 = new queue<Type>();

	cout << "Enter s for stack or q for queue: " << endl;
	char ch;
	cin >> ch;

	while (ch != 's' && ch != 'q') {
		cout << "Error, invalid input. Please enter either s for stack or q for queue." << endl;
		cin >> ch;
	}

	while (1)
	{
		int choice;

		//Menu options
		cout << endl
			<< "1. Return Capacity" << endl
			<< "2. Return Size of the data structure" << endl
			<< "3. View first item" << endl
			<< "4. Insert item" << endl
			<< "5. Delete item" << endl
			<< "6. Display" << endl
			<< "7. Clear" << endl
			<< "8. Exit" << endl;

		cin >> choice;
		switch (choice) {
		case 1:
			if (ch == 's') cout << stack1->capacity() << endl;
			else cout << queue1->capacity() << endl;
			break;
		case 2:
			if (ch == 's') cout << stack1->size() << endl;
			else cout << queue1->size() << endl;
			break;
		case 3:
			try {
				if (ch == 's') cout << stack1->top() << endl;
				else cout << queue1->front() << endl;
			}
			catch (exception& e) {
				cerr << e.what() << endl;
			}
			break;
		case 4:
			if (ch == 's') {
				cout << "Enter a data member to be pushed onto the stack" << endl;
				Type data;
				cin >> data;
				stack1->push(data);
			}
			else {
				cout << "Enter a data member to be pushed onto the queue" << endl;
				Type data;
				cin >> data;
				queue1->enqueue(data);
			}
			break;
		case 5:
			try {
				if (ch == 's') cout << stack1->pop() << endl;
				else cout << queue1->dequeue() << endl;
			}
			catch (exception& e) {
				cerr << e.what() << endl;
			}
			break;
		case 6:
			if (ch == 's') stack1->display();
			else queue1->display();
			break;
		case 7:
			if (ch == 's') stack1->clear();
			else queue1->clear();
			break;
		case 8:
			exit(1);
			break;
		default:
			cout << "Wrong choice. Please enter a valid choice." << endl;
			break;
		}
	}
	return 0;
}
