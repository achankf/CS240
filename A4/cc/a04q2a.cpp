#include "a04q2a.h"
#include <algorithm> //max

float calBalance(BSTNode node){
	int left = node.GetLeftDescendants();
	int right = node.GetRightDescendants();
	return left ? right / left : 0;
}

int height(BSTNode node){
	int left = node.GetLeftDescendants();
	int right = node.GetRightDescendants();
	return 1 + std::max(left,right);
}

bool BinarySearchTree::Insert(int value) {
	if (root == NULL) {
		root = new BSTNode(value);
		return true;
	}
	return root->Insert(value);
}

bool BSTNode::Insert(int value) {
	BSTNode *next = NULL;
	if (value == this->value){
		return false;
	} else if (value < this->value) {
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
	}
	return next ? next->Insert(value) : false;
}

bool BinarySearchTree::Search(int value) {
	return root ? root->Search(value) : false;
}

bool BSTNode::Search(int value) {
	BSTNode *next = NULL;
	if (value == this->value){
		return true;
	} else if (value < this->value) {
		next = left;
	} else if (value > this->value) {
		next = right;
	}
	return next ? next->Search(value) : false;
}
