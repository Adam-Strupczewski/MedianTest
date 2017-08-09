#include "MedianTwoTrees.h"



MedianTwoTrees::MedianTwoTrees() :
	minTree(nullptr), maxTree(nullptr), previousMedian(0.0)
{
}


MedianTwoTrees::~MedianTwoTrees()
{
	resetImpl();
}


std::string MedianTwoTrees::printInfo()
{
	return "MedianTwoTrees";
}


void MedianTwoTrees::reset() 
{
	resetImpl();
}

void MedianTwoTrees::resetImpl() 
{
	if (minTree != nullptr) {
		delete minTree;
	}
	if (maxTree != nullptr) {
		delete maxTree;
	}
	minTree = nullptr;
	maxTree = nullptr;

	previousMedian = 0.0;
}


double MedianTwoTrees::calculateMedian(int newVal)
{
	if (minTree == nullptr)
		minTree = new BST();
	if (maxTree == nullptr)
		maxTree = new BST();

	int maxElems = maxTree->getCount();
	int minElems = minTree->getCount();

	double newMedian = 0.0;

	// When inserting new element ensure that left and right tree differ by no 
	// more than 1 element
	if (maxElems > minElems) { 
		// There are more elements in left tree
		if (newVal < previousMedian) {
			// Current element fits in left tree
			// Remove top element from left tree and insert into right tree
			minTree->insertValue(maxTree->extractMax());
			maxTree->insertValue(newVal);
		}
		else {
			// Current element fits in right tree
			minTree->insertValue(newVal);
		}

		// Both trees are balanced
		newMedian = double(maxTree->getMax() + minTree->getMin()) / 2.0;
	}
	else if (maxElems == minElems) {

		if (newVal < previousMedian) {
			// Current element fits in left tree
			maxTree->insertValue(newVal);
			newMedian = maxTree->getMax();
		}
		else {
			// Current element fits in right tree
			minTree->insertValue(newVal);
			newMedian = minTree->getMin();
		}
	}
	else { // There are more elements in right tree

		if (newVal < previousMedian) {
			// Current element fits in left tree
			maxTree->insertValue(newVal);
		}
		else {
			// Remove top element from right tree and insert into left tree
			maxTree->insertValue(minTree->extractMin());
			minTree->insertValue(newVal);
		}

		// Both trees are balanced
		newMedian = double(maxTree->getMax() + minTree->getMin()) / 2.0;
	}

	previousMedian = newMedian;
	return newMedian;
}
