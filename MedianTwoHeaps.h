#pragma once
#include "MedianBase.h"
#include "Heap.h"

/*
Structure that calculates median by using two heaps with smaller and larger elements 
than last median, each incoming number is inserted into appropriate heap, if heaps 
would end up with sizes differing by more than one, they are rearranged. This way the 
median can be found quickly by getting top of heap(s).
*/
class MedianTwoHeaps :
	public MedianBase
{
public:
	MedianTwoHeaps();
	virtual ~MedianTwoHeaps();

	virtual double calculateMedian(int newVal);
	virtual void reset();
	virtual std::string printInfo();

private:
	void resetImpl();		// To avoid calling virt func from destructor

	Heap *minHeap;
	Heap *maxHeap;

	double previousMedian;

	// Prevent copy construction and assignment
	MedianTwoHeaps(const MedianTwoHeaps&);
	MedianTwoHeaps& operator=(const MedianTwoHeaps&);
};

