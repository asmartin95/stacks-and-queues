/*
Summary: This queue stores objects in an ordered list and allows insertions at one end and deletions from the other end. 
The objects are stored in an array and the capacity may be changed depending on the number of objects currently n the array.
*/

#ifndef queue_h
#define queue_h

#include <iostream>
#include <stdexcept>

using namespace std;

template<class Type> class queue {
public:
	Type *ar;
	int iHead;
	int iTail;
	int count;
	int initialSize;
	int arraySize;

	//Constructor. Takes initialSIze as an arguement and allocates memorey for the array.
	//If the value was 0 or negative set it to 1. Additionally set all other members as necessary
	queue(int n = 15) {
		if (n <= 0) this->initialSize = 1;
		else this->initialSize = n;
		ar = new Type[initialSize];
		this->arraySize = this->initialSize;
		iHead = 0;
		iTail = 0;
		count = 0;
	}

	//The destructor. Deletes memory allocated for the array
	~queue() {
		delete[] ar;
	}

	//Front returns value at head index
	Type front() const {
		if (count == 0) throw underflow_error("Queue is empty, no front");
		else return ar[iHead];
	}

	//Back returns value at tail index
	Type back() const {
		if (count == 0) throw underflow_error("Queue is empty, no back");
		else return ar[iTail];
	}

	//Returns size of queue
	int size() const {
		return count;
	}

	//Returns if queue is full or empty
	bool empty() const {
		return count == 0;
	}

	//Returns storage size of array
	int capacity() const {
		return arraySize;
	}

	//Prints the elements stored in the queue with first in queue being printed first
	void display() {
		if (count == 0) {
			cout << "Queue empty, nothing to display";
		}
		else {
			for (int i = iHead, j = 0; j < count; j++, i++) {
				i = i%arraySize;
				cout << ar[i] << " ";
			}
		}
		cout << endl;
	}

	//Adds new data to queue. If the queue is too small it doubles in size and copies over previous elements
	void enqueue(Type const &data) {
		if (count == arraySize) {
			Type *newAr = new Type[arraySize*2];
			for (int i = iHead, j = 0; j < count; j++, i++) {
				i = i%arraySize;
				newAr[j] = ar[i];
			}
			arraySize *= 2;
			iHead = 0;
			newAr[count++] = data;
			iTail = count;
			ar = newAr;
		}
		else {
			ar[iTail] = data;
			count++;
			iTail = (iTail + 1) % arraySize;
		}
	}

	//Dequeues the first data element at the front of the queue. If after the removal the queue is 1/4 of the size
	//then shrink the array to half size and transfer over elements
	Type dequeue() {
		Type temp;
		if (count == 0) throw underflow_error("Queue is empty, no elements to dequeue");
		else {
			temp = ar[iHead++];
			if (((count - 1) <= arraySize / 4) && (arraySize > initialSize)) {
				Type *newAr = new Type[arraySize/2];
				for (int i = iHead, j = 0; j < (count - 1); j++, i++) {
					i = i%arraySize;
					newAr[j] = ar[i];
				}
				arraySize /= 2;
				iHead = 0;
				iTail = count - 1;
				ar = newAr;
			}

			count--;
		}
		return temp;
	}

	//Clears elements from list and reinitializes to the initial size
	void clear() {
		arraySize = initialSize;
		count = 0;
		iHead = 0;
		iTail = 0;
	}
};

#endif
