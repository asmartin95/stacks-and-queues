/*
Summary: This stack stores values in an array. It can do insertions and deletions in O(1) time
at one end of the stack. If the stack is full it doubles its size and if there are 1/4 of elements
in the stack after an erase then it halves its size.
*/

#ifndef stack_h
#define stack_h

#include <iostream>
#include <stdexcept>

using namespace std;

template<class Type> class stack {
public:
	Type *ar;
	int count = 0;
	int initialSize;
	int arraySize;

	//Constructor with default 15. If user inputs 0 or negatives size gets set to 1
	stack(int n = 15) {
		if (n <= 0) this->initialSize = 1;
		else this->initialSize = n;

		this->arraySize = this->initialSize;
		ar = new Type[initialSize];
	}

	//Destructor
	~stack() {
		delete[] ar;
	}

	//Returns the object at the top of the stack
	Type top() const {
		if (count == 0) {
			throw underflow_error("Error: Stack is empty, no top element");
		}
		else {
			return ar[count - 1];
		}
	}

	//Returns the number of elements currently stored in the stack
	int size() const {
		return count;
	}

	//Returns true if the stack is empty, false otherwise
	bool empty() const {
		return count == 0;
	}

	//Returns the current size of the array
	int capacity() const {
		return arraySize;
	}

	//Prints the content of the stack
	//Displays items in stack with top of the stack being displayed at the front
	void display() {
		if (count == 0) {
			cout << "Stack is empty, no items to display";
		}

		for (int i = count - 1; i >= 0; i--) {
			cout << ar[i] << " ";
		}
		cout << endl;
	}

	//Inserts the new element at the top of the stack
	void push(Type const &data) {
		if (count == arraySize) {
			arraySize *= 2;
			Type *newAr = new Type[arraySize];
			for (int i = 0; i < count; i++) {
				newAr[i] = ar[i];
			}
			ar = newAr;
			ar[count++] = data;
		}
		else {
			ar[count++] = data;
		}
	}

	//Removes the element at the top of the stack. If, after the element is removed,
	//the array is 1/4 full and the array size is greater than the initial size, the size of the array is halved.
	Type pop() {
		Type temp;
		if (count == 0) {
			throw underflow_error("Error: Stack is empty, no element to pop");
		}
		else {
			temp = ar[count - 1];
			count--;
			if ((count <= arraySize / 4) && (arraySize > initialSize)) {
				arraySize /= 2;
				Type *newAr = new Type[arraySize];
				for (int i = 0; i < count; i++) {
					newAr[i] = ar[i];
				}
				ar = newAr;
			}
		}

		return temp;
	}

	//Resets the size to the initial size and resets the count to 0
	void clear() {
		this->arraySize = this->initialSize;
		count = 0;
	}
};

#endif