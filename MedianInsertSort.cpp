#include "MedianInsertSort.h"

#include <cstring>


MedianInsertSort::MedianInsertSort() : 
	array(nullptr), arraySize(0), numElems(0)
{
}


MedianInsertSort::~MedianInsertSort()
{
	resetImpl();
}


std::string MedianInsertSort::printInfo() 
{
	return "MedianInsertSort";
}


void MedianInsertSort::reset() 
{
	resetImpl();
}


void MedianInsertSort::resetImpl() 
{
	if (array != nullptr) {
		delete[] array;
	}
	array = nullptr;
	arraySize = 0;
	numElems = 0;
}


double MedianInsertSort::calculateMedian(int newVal)
{
	manageArraySize();

	// Insert element
	insertionSort(newVal);

	// Return median which is middle of array or average
	if (numElems % 2 == 1) {
		return array[numElems/2];
	}
	else {
		return double(array[numElems/2-1] + array[numElems/2]) / 2.0;
	}
}


void MedianInsertSort::manageArraySize() 
{
	// Create array if it doesn't exist
	if (array == nullptr) {
		array = new int[INIT_SIZE];
		arraySize = INIT_SIZE;
		numElems = 0;
	}
	// Reallocate array if array is full
	else if (numElems == arraySize) {
		int* tempArray = new int[2 * arraySize];
		memcpy(tempArray, array, arraySize * sizeof(int));
		delete[] array;
		array = tempArray;
		arraySize = 2 * arraySize;
	}
}

// Even if we find point to insert in O(logN) time, moving elements takes O(N)
void MedianInsertSort::insertionSort(int newVal)
{
	for (int i = 0; i < numElems; ++i)
	{
		if (newVal < array[i]) {

			// Faster with memmove (MSVC++ 2x)
			memmove(array+i+1, array+i, (numElems-i)*sizeof(int));
			/*for (int j = numElems - 1; j >= i; --j) {
				array[j + 1] = array[j];
			}*/

			array[i] = newVal;
			numElems++;
			return;
		}
	}

	// If new element greater than all existing - insert at end
	array[numElems++] = newVal;
}
