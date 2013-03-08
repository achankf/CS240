#include "a04q2c.h"
#include <algorithm> // std::max

float calBalance(BSTNode node){
	int left = node.LeftDescendants();
	int right = node.RightDescendants();
	return left ? right / left : 0;
}

int height(BSTNode node){
	int left = node.LeftDescendants();
	int right = node.RightDescendants();
	return 1 + std::max(left,right);
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
			left = new BSTNode(value);
			return true;
		}
		next = left;
	} else if (value > this->value) {
		if (right == NULL) {
			right = new BSTNode(value);
			return true;
		}
		next = right;
	} else { // equal
		return false;
	}
	return next ? next->Insert(value) : false;
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
