#include "a04q2c.h"

#include <iostream>
using namespace std;

static int weight(BSTNode *node){
	if (node == NULL) return 0;
	int left = node->LeftDescendants();
	int right = node->RightDescendants();
	return 1 + left + right;
}

static float calBalance(BSTNode *node){
	int left = node->LeftDescendants();
	int right = node->RightDescendants();
	cout << *node << ' ' << (left ? (float) right / left : 0) << endl;
	return left ? (float) right / left : 0;
}

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


bool BSTNode::Insert( int value ){
	BSTNode *next = NULL;
	if (value < this->value) {
		if (left == NULL) {
			leftDescendants++;
			balance = calBalance(this);
			left = new BSTNode(value);
			return true;
		}
		next = left;
	} else if (value > this->value) {
		if (right == NULL) {
			rightDescendants++;
			balance = calBalance(this);
			right = new BSTNode(value);
			return true;
		}
		next = right;
	} else { // equal
		return false;
	}
	bool temp = false;
	if (next){
		temp = next->Insert(value);
	}
	this->leftDescendants = weight(left);
	this->rightDescendants = weight(right);
	this->balance = calBalance(this);
	if (balance > 2){
cout << *this << " RIGHT HEAVY"<<endl;
	} else if (balance < (float)1/2){
cout << *this<< " LEFT HEAVY"<<endl;
	}

	return temp;
}


bool BinarySearchTree::Search( int value ) {
	return root ? root->Search(value) : false;
}


bool BSTNode::Search( int value ) {
	BSTNode *next = NULL;
	if (value < this->value) {
		next = left;
	} else if (value > this->value) {
		next = right;
	} else {
		return true;
	}
	return next ? next->Search(value) : false;
}
