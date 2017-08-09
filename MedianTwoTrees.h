#pragma once
#include "MedianBase.h"
#include "BST.h"

/*
Structure that calculates median by using two trees with smaller and larger elements
than last median, each incoming number is inserted into appropriate tree, if trees
would end up with sizes differing by more than one, they are rearranged. This way the
median can be found quickly by getting min/max from tree(s).
*/
class MedianTwoTrees :
	public MedianBase
{
public:
	MedianTwoTrees();
	virtual ~MedianTwoTrees();

	virtual double calculateMedian(int newVal);
	virtual void reset();
	virtual std::string printInfo();

private:
	void resetImpl();		// To avoid calling virt func from destructor

	BST *minTree;
	BST *maxTree;

	double previousMedian;

	// Prevent copy construction and assignment
	MedianTwoTrees(const MedianTwoTrees&);
	MedianTwoTrees& operator=(const MedianTwoTrees&);
};

