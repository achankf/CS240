#ifndef A04Q2C_H
#define A04Q2C_H

#include <cstddef>

class BSTNode {
private:
	int value;
	BSTNode* left;
	BSTNode* right;
	
	float balance;
	int leftDescendants;
	int rightDescendants;

public:
	BSTNode( int value );

	bool Insert(int value);
	bool Search(int value);

	int Value() const { return value; }
	BSTNode* Left() const { return left; }
	BSTNode* Right() const { return right; }

	float Balance() const { return balance; }
	int LeftDescendants() const { return leftDescendants; }
	int RightDescendants() const { return rightDescendants; } 

private: // custom functions

	// returns number of children of this node
	int numChildren() const;

	// return the weight of this subtree (1+ numChildren())
	int weight() const;

	// returns the balance
	float calBalance() const;

	// checks whether this is balanced
	bool isBalance() const;

	// updated metadata (balance and left/rightDescendants)
	void fixMetaData();

	// decide which direction should this be rotated;
	// mutually recursive with prepareRotateLeft/RIght
	void decideRotateDirection();

	// decide whether this should run a single/double rotation
	void prepareRotateLeft();
	void prepareRotateRight();

	// AVL-style rotations
	void rotateLeft();
	void rotateRight();
	void doubleLeft();
	void doubleRight();
};


class BinarySearchTree {
private:
	BSTNode* root;

public:
	BinarySearchTree() {
		root = NULL;
	}

	bool Insert(int value);
	bool Search(int value);
	BSTNode* Root() const { return root; }
};


#endif
