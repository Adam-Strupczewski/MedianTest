#pragma once

#include<iostream>

class Heap
{
public:
	// Constructor, destructor
	Heap(bool isMin);
	~Heap();

	// Delete everything
	void reset();

	// Returns and removes the root which is min / max
	int extractTop();

	// Returns the root which is min / max
	int getTop() const;

	// Insert new integer value
	void insertValue(int val);

	// Returns number of elements
	int getCount() const { return numElems; }

private:

	void manageArraySize();

	int parent(int i) const { return (i - 1) / 2; }

	int left(int i) const { return (2 * i + 1); }

	int right(int i) const { return (2 * i + 2); }

	// Heapify a subtree with root at given index
	void heapify(int);

	// Type of heap
	bool(*comp)(int, int);	// Comparator depends on type of heap

	// Internal variables
	int *array;		// Pointer to array of elements in heap
	int arraySize;	// Allocated size of heap
	int numElems;	// Current number of elements in heap

	// Prevent copy construction and assignment
	Heap(const Heap&);
	Heap& operator=(const Heap&);
};