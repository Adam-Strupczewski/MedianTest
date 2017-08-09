#include "BST.h"


struct Node
{
	int value;
	Node *left;
	Node *right;

	Node(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

BST::BST() : root(nullptr), numElems(0)
{
}


BST::~BST()
{
	destroyTree();
}


void BST::insertValue(int newVal)
{

	if (root != nullptr) {
		// If root exists start insertion from root
		insertFromNode(newVal, root);
	}
	else {
		// Else create root node and then insert from there
		root = new Node(newVal);
		numElems++;
	}
}

void BST::insertFromNode(int newVal, Node* startNode)
{
	Node* node = startNode;

	// Continue moving down until the right place for insertion is found
	while (true) {
		if (newVal < node->value) {
			// Insert if node doesn't exist, or move down to left
			if (node->left == nullptr) {
				node->left = new Node(newVal);
				numElems++;
				break;
			}
			else {
				node = node->left;
			}
		}
		else {
			// Insert if node doesn't exist, or move down to right
			if (node->right == nullptr) {
				node->right = new Node(newVal);
				numElems++;
				break;
			}
			else {
				node = node->right;
			}
		}
	}
}


int BST::getMin() const 
{
	// If tree exists return leftmost node
	if (root != nullptr) {
		Node* node = root;
		while (node->left != nullptr)
			node = node->left;
		return node->value;
	}
	return 0;
}


int BST::getMax() const 
{
	// If tree exists return rightmost node
	if (root != nullptr) {
		Node* node = root;
		while (node->right != nullptr)
			node = node->right;
		return node->value;
	}
	return 0;
}


int BST::extractMin() 
{
	int retval = 0;

	// If tree exists find leftmost node
	if (root != nullptr) {
		Node* parent = root;
		Node* node = root;
		while (node->left != nullptr) {
			parent = node;
			node = node->left;
		}
		retval = node->value;

		// If node has right child link it to parent, else set null
		if (node->right != nullptr) {
			if (node != root)
				parent->left = node->right;
			else
				root = node->right;		// In case of root we move tree 'up'
		}
		else {
			if (node != root)
				parent->left = nullptr;
			else
				root = nullptr;			// In case this was the last node
		}

		delete node;
		numElems--;
	}
	return retval;
}


int BST::extractMax() 
{
	int retval = 0;

	// If tree exists find rightmost node
	if (root != nullptr) {
		Node* parent = nullptr;
		Node* node = root;
		while (node->right != nullptr) {
			parent = node;
			node = node->right;
		}
		retval = node->value;

		// If node has left child link it to parent, else set null
		if (node->left != nullptr) {
			if (node != root)
				parent->right = node->left;
			else
				root = node->left;		// In case of root we move tree 'up'
		}
		else {
			if (node != root)
				parent->right = nullptr;
			else
				root = nullptr;			// In case this was the last node
		}

		delete node;
		numElems--;
	}
	return retval;
}


void BST::destroyTree() 
{
	destroySubtree(root);
	root = nullptr;
	numElems = 0;
}


void BST::destroySubtree(Node* node) 
{
	// Not optimal, but you need parent pointer for O(N) destruction
	// Recursive delete causes stack overflow for large unbalanced trees
	while (getCount() > 0) {
		extractMin();
	}
}