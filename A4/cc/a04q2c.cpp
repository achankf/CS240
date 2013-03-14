#include "a04q2c.h"

// for the descriptions of the function, please refer to the header file
// though the order of implemention is mixed up, so if you haven't read
// a function, like "numChildren", please just assumes what it is as 
// described in the header file

int BSTNode::weight() const{
	// note the use of (!this) ... this allows the main codes to
	// avoid explicitly writting the NULL test, which save
	// spaces and more importantly increases readability
	if (!this) return 0;
	return 1 + numChildren();
}

float BSTNode::calBalance() const{
	if (!this) return 0;
	int left = leftDescendants;
	int right = rightDescendants;
	return left ? (float) right / left : 0;
}

// constructor
BSTNode::BSTNode( int value ) {
	this->value = value;
	left = right = NULL;
	leftDescendants = rightDescendants = balance = 0;
}

bool BinarySearchTree::Insert( int value ){
	if (root == NULL) {
		root = new BSTNode(value);
		return true;
	}
	return root->Insert(value);
}

void BSTNode::fixMetaData(){
	if (!this) return;
	leftDescendants = left->weight();
	rightDescendants = right->weight();
	balance = calBalance();
}

bool BSTNode::isBalance() const{
	if (!this || numChildren() <= 1)
		return true;
	return balance >= 0.5 && balance <= 2;
}

void BSTNode::rotateLeft(){
	// backup the old root node in a NEW node
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *rightBak = this->right;
	bak->left = this->left;
	bak->right = this->right->left;
	this->value = this->right->value;
	this->left = bak;
	this->right = this->right->right;

	// remove the original right node because it is "stuck" and not used
	delete rightBak;

	// fix the metadata
	this->left->fixMetaData();
	this->right->fixMetaData();
	this->fixMetaData();
}

void BSTNode::rotateRight(){
	// backup the old root node in a NEW node
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *leftBak = this->left;
	bak->right = this->right;
	bak->left = this->left->right;
	this->value = this->left->value;
	this->right = bak;
	this->left = this->left->left;

	// remove the original right node because it is "stuck" and not used
	delete leftBak;

	// fix the metadata
	this->left->fixMetaData();
	this->right->fixMetaData();
	this->fixMetaData();
}

void BSTNode::doubleLeft(){
	right->rotateRight();
	rotateLeft();
}

void BSTNode::doubleRight(){
	left->rotateLeft();
	rotateRight();
}

void BSTNode::prepareRotateRight(){
	if ((left->rightDescendants == rightDescendants && rightDescendants != 0)
		|| (left->leftDescendants < left->rightDescendants)){
		doubleRight();
	} else{
		rotateRight();
	}

	// re-rotate when necessary
	decideRotateDirection();

	// left and right are likely get messed up during the TRANSFER of subtree
	// hence they are potentially needed to be rebalanced
	right->decideRotateDirection();
	left->decideRotateDirection();
}

void BSTNode::prepareRotateLeft(){
	if ((leftDescendants == right->leftDescendants && leftDescendants != 0)
		|| (right->leftDescendants > right->rightDescendants)){
		doubleLeft();
	} else {
		rotateLeft();
	}

	// re-rotate when necessary
	decideRotateDirection();

	// left and right are likely get messed up during the TRANSFER of subtree
	// hence they are potentially needed to be rebalanced
	right->decideRotateDirection();
	left->decideRotateDirection();
}

void BSTNode::decideRotateDirection(){
	// return early if *this node is balanced
	if (isBalance()) return;

	if (leftDescendants > rightDescendants){
		prepareRotateRight();
	} else { // rightDescendants < leftDescendants
		prepareRotateLeft();
	}
}

int BSTNode::numChildren() const{
	if (!this) return 0;
	return leftDescendants + rightDescendants;
}

bool BSTNode::Insert( int value ){
	// do normal insertion
	if (value < this->value) {
		if (left == NULL) {
			leftDescendants++;
			balance = calBalance();
			left = new BSTNode(value);
			return true;
		}
		left->Insert(value);
	} else if (value > this->value) {
		if (right == NULL) {
			rightDescendants++;
			balance = calBalance();
			right = new BSTNode(value);
			return true;
		}
		right->Insert(value);
	} else { // equal
		return false;
	}

	// fix the data and then do the rotation
	// notice that the newly-created node won't get to here
	// because they return early
	fixMetaData();
	decideRotateDirection();
	return true;
}


bool BinarySearchTree::Search( int value ) {
	return root ? root->Search(value) : false;
}


bool BSTNode::Search( int value ) {
	if (value < this->value)
		return left ? left->Search(value) : false;
	else if (value > this->value)
		return right ? right->Search(value) : false;
	else
		return true;
}
