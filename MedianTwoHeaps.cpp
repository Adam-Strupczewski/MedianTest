#include "MedianTwoHeaps.h"



MedianTwoHeaps::MedianTwoHeaps() : 
	minHeap(nullptr), maxHeap(nullptr), previousMedian(0.0)
{
}


MedianTwoHeaps::~MedianTwoHeaps()
{
	resetImpl();
}


std::string MedianTwoHeaps::printInfo() 
{
	return "MedianTwoHeaps";
}


void MedianTwoHeaps::reset() 
{
	resetImpl();
}


void MedianTwoHeaps::resetImpl() 
{
	if (minHeap != nullptr) {
		delete minHeap;
	}
	if (maxHeap != nullptr) {
		delete maxHeap;
	}
	minHeap = nullptr;
	maxHeap = nullptr;

	previousMedian = 0.0;
}


double MedianTwoHeaps::calculateMedian(int newVal)
{
	if (minHeap == nullptr)
		minHeap = new Heap(true);
	if (maxHeap == nullptr)
		maxHeap = new Heap(false);
	
	int maxElems = maxHeap->getCount();
	int minElems = minHeap->getCount();

	double newMedian = 0.0;

	// When inserting new element ensure that left and right heap differ by no 
	// more than 1 element
	if (maxElems > minElems) { 
		// There are more elements in left heap
		if (newVal < previousMedian) {
			// Current element fits in left heap
			// Remove top element from left heap and insert into right heap
			minHeap->insertValue(maxHeap->extractTop());
			maxHeap->insertValue(newVal);
		}
		else {
			// Current element fits in right heap
			minHeap->insertValue(newVal);
		}

		// Both heaps are balanced
		newMedian = double(maxHeap->getTop() + minHeap->getTop()) / 2.0;
	}
	else if (maxElems == minElems) {

		if (newVal < previousMedian) {
			// Current element fits in left heap
			maxHeap->insertValue(newVal);
			newMedian = maxHeap->getTop();
		}
		else {
			// Current element fits in right heap
			minHeap->insertValue(newVal);
			newMedian = minHeap->getTop();
		}
	}
	else { 
		// There are more elements in right heap
		if (newVal < previousMedian) {
			// Current element fits in left heap
			maxHeap->insertValue(newVal);
		}
		else {
			// Remove top element from right heap and insert into left heap
			maxHeap->insertValue(minHeap->extractTop());
			minHeap->insertValue(newVal);
		}

		// Both heaps are balanced
		newMedian = double(maxHeap->getTop() + minHeap->getTop()) / 2.0;
	}

	previousMedian = newMedian;
	return newMedian;
}
