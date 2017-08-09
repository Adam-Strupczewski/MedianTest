#pragma once
#include "MedianBase.h"
#include "constants.h"

/*
Structure that calculates median by keeping a sorted array of all 
past numbers and selecting middle element(s)
*/
class MedianInsertSort : 
	public MedianBase
{
public:
	MedianInsertSort();
	virtual ~MedianInsertSort();

	virtual double calculateMedian(int newVal);
	virtual void reset();
	virtual std::string printInfo();

private:	
	void resetImpl();		// To avoid calling virt func from destructor
	void manageArraySize();
	void insertionSort(int newVal);

	int *array;
	int arraySize;
	int numElems;

	// Prevent copy construction and assignment
	MedianInsertSort(const MedianInsertSort&);
	MedianInsertSort& operator=(const MedianInsertSort&);
};

