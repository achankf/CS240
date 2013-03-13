#include "a04q2c.h"

#include <iostream>
using namespace std;

int BSTNode::weight(){
	if (!this) return 0;
	return 1 + numChildren();
}

float BSTNode::calBalance(){
	if (!this) return 0;
	int left = leftDescendants;
	int right = rightDescendants;
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

void BSTNode::fixMetaData(){
	if (!this) return;
	leftDescendants = left->weight();
	rightDescendants = right->weight();
	balance = calBalance();
}

bool BSTNode::isBalance(){
	if (!this || numChildren() <= 1)
		return true;
	return balance >= 0.5 && balance <= 2;
}

void BSTNode::rotateLeft(){
#ifdef ALFRED_DEBUG
cout << *this << " before " << set_color(YELLOW) << "LEFT rotation" << set_color()<<endl;
print();
cout << endl;
#endif
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *rightBak = this->right;
	bak->left = this->left;
	bak->right = this->right->left;
	this->value = this->right->value;
	this->left = bak;
	this->right = this->right->right;
	delete rightBak;

#ifdef ALFRED_DEBUG
cout << "END RESULT" << endl;
print();
cout << endl;
#endif
	this->left->fixMetaData();
	this->right->fixMetaData();
	this->fixMetaData();
}

void BSTNode::rotateRight(){
#ifdef ALFRED_DEBUG
cout << *this << " before " << set_color(YELLOW) << "RIGHT rotation" << set_color()<<endl;
print();
cout << endl;
#endif
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *leftBak = this->left;
	bak->right = this->right;
	bak->left = this->left->right;
	this->value = this->left->value;
	this->right = bak;
	this->left = this->left->left;
	delete leftBak;

#ifdef ALFRED_DEBUG
cout << "END RESULT" << endl;
print();
cout << endl;
#endif
	this->left->fixMetaData();
	this->right->fixMetaData();
	this->fixMetaData();
}

void BSTNode::doubleLeft(){
#if ALFRED_DEBUG
cout << *this << " before " << set_color(GREEN) << "DOUBLE LEFT rotation" << set_color()<<endl;
#endif
	right->rotateRight();
	rotateLeft();
}

void BSTNode::doubleRight(){
#if ALFRED_DEBUG
cout << *this << " before " << set_color(GREEN) << "DOUBLE RIGHT rotation" << set_color()<<endl;
#endif
	left->rotateLeft();
	rotateRight();
}

void BSTNode::prepareRotateRight(){
	if (isBalance()) return;
	if ((left->rightDescendants == rightDescendants && rightDescendants != 0) ||
		(left->leftDescendants < left->rightDescendants)){
		doubleRight();
		right->prepareRotateLeft();
		left->prepareRotateRight();
	} else{
		rotateRight();
	}
}

void BSTNode::prepareRotateLeft(){
	if (isBalance()) return;
	if ((leftDescendants == right->leftDescendants && leftDescendants != 0)
		|| (right->leftDescendants > right->rightDescendants)){
		doubleLeft();
		right->prepareRotateLeft();
		left->prepareRotateRight();
	} else {
		rotateLeft();
	}
}

int BSTNode::numChildren(){
	if (!this) return 0;
	return leftDescendants + rightDescendants;
}

bool BSTNode::Insert( int value ){
	if (value < this->value) {
		if (left == NULL) {
			leftDescendants++;
			balance = calBalance();
			left = new BSTNode(value);
			return true;
		}
		left->Insert(value);
		fixMetaData();
		prepareRotateRight();
	} else if (value > this->value) {
		if (right == NULL) {
			rightDescendants++;
			balance = calBalance();
			right = new BSTNode(value);
			return true;
		}
		right->Insert(value);
		fixMetaData();
		prepareRotateLeft();
	} else { // equal
		return false;
	}
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
