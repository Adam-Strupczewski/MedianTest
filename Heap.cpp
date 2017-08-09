#include "Heap.h"
#include "Constants.h"

// Prototype of a utility function to swap two integers
inline void swap(int *x, int *y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool greater(int a, int b)
{
	return a > b;
}

bool smaller(int a, int b)
{
	return a < b;
}

Heap::Heap(bool isMin) : array(nullptr), arraySize(0), numElems(0)
{
	if (isMin)
		comp = &smaller;
	else
		comp = &greater;
}

Heap::~Heap()
{
	reset();
}

void Heap::reset() 
{
	if (array != nullptr) {
		delete[] array;
	}
	array = nullptr;
	arraySize = 0;
	numElems = 0;
}

void Heap::manageArraySize() 
{
	// Create array if it doesn't exist
	if (array == nullptr) {
		array = new int[INIT_SIZE];
		arraySize = INIT_SIZE;
		numElems = 0;
	}
	// Reallocate array if it is full
	else if (numElems == arraySize) {
		int *tempArray = new int[2 * arraySize];
		memcpy(tempArray, array, arraySize * sizeof(int));
		delete[] array;
		array = tempArray;
		arraySize = 2 * arraySize;
	}
}

void Heap::insertValue(int val)
{
	manageArraySize();

	// First insert the new key at the end
	int i = numElems++;
	array[i] = val;

	// Fix the min/max heap property if it is violated
	while (i != 0 && comp(array[i], array[parent(i)]))
	{
		swap(&array[i], &array[parent(i)]);
		i = parent(i);
	}
}

int Heap::getTop() const
{ 
	if (numElems <= 0) {
		std::cout << "Error: No elements in heap" << std::endl;
		return INT_MAX;
	} else
		return array[0];
}

// Remove root from heap and return value
int Heap::extractTop()
{
	if (numElems <= 0) {
		std::cout << "Error: No elements in heap" << std::endl;
		return INT_MAX;
	}
	if (numElems == 1) {
		numElems--;
		return array[0];
	}

	// After removing root, switch with last element and restore heap structure
	int root = array[0];
	array[0] = array[numElems - 1];
	numElems--;
	heapify(0);

	return root;
}

// Heapify a subtree with root at given index
// Assumes that the subtrees are already heapified
void Heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int extremal = i;

	// Check if any child node is inconsistent with heap property
	if (l < numElems && comp(array[l], array[extremal]))
		extremal = l;
	if (r < numElems && comp(array[r], array[extremal]))
		extremal = r;

	// If any of the children are extremal in wrong way, swap with 
	// most extremal and continue heapification down
	if (extremal != i) {
		swap(&array[i], &array[extremal]);
		heapify(extremal);
	}
}