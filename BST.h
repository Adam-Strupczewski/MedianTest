#pragma once

struct Node;

class BST
{
public:
	// Constructor, destructor
	BST();
	~BST();

	// Insert new integer value
	void insertValue(int newVal);

	// Returns min / max element
	int getMin() const;
	int getMax() const;

	// Returns and removes min / max element
	int extractMin();
	int extractMax();

	// Returns number of elements
	int getCount() const { return numElems; }

	// Destroys the tree and deletes all data
	void destroyTree();

private:
	void destroySubtree(Node* node);
	void insertFromNode(int newVal, Node* startNode);

	Node *root;
	int numElems;

	// Prevent copy construction and assignment
	BST(const BST&);
	BST& operator=(const BST&);
};

