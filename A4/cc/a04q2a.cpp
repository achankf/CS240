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
	} else {
		return root->Insert(value);
	}
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
	if (root == NULL){
		return false;
	} else {
		return root->Search(value);
	}
}

bool BSTNode::Search(int value) {
	if (value == this->value){
		return true;
	} else if (value < this->value) {
		if (left == NULL){
			return false;
		} else {
			return left->Search(value);
		}
	} else if (value > this->value) {
		if (right == NULL){
			return false;
		} else {
			return right->Search(value);
		}
	}
	return false;
}
