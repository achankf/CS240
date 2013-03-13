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
	return left ? (float) right / left : 0;
}

BSTNode::BSTNode( int value ) {
	this->value = value;
	left = right = NULL;
	leftDescendants = rightDescendants = balance = 0;
}


bool BinarySearchTree::Insert( int value ){
cout << endl << "START"<<endl;
	print();
	if (root == NULL) {
		root = new BSTNode(value);
		return true;
	}
cout << endl << "START"<<endl;
	print();
	return root->Insert(value);
}

void BSTNode::fixMetaData(){
	if (!this) return;
	//cout << "Fixing " << *this << " ";
	leftDescendants = weight(left);
	rightDescendants = weight(right);
//cout << weight(left) << " " << weight(right) << endl;
	balance = calBalance(this);
}

bool BSTNode::isBalance(){
	// at most one child
	if (!this || numChildren() <= 1)
		return true;
	return balance >= 0.5 && balance <= 2;
}

void BSTNode::rotateLeft(){
cout << *this << " Single Left"<<endl;
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *rightBak = this->right;
	bak->left = this->left;
	bak->right = this->right->left;
	this->value = this->right->value;
	this->left = bak;
	this->right = this->right->right;
	delete rightBak;
}

void BSTNode::rotateRight(){
cout << *this << " Single Right"<<endl;
	BSTNode *bak = new BSTNode(this->value);
	BSTNode *leftBak = this->left;
	bak->right = this->right;
	bak->left = this->left->right;
	this->value = this->left->value;
	this->right = bak;
	this->left = this->left->left;
	delete leftBak;
	//cout << *this<< " " << *(this->right) <<endl;
}

void BSTNode::doubleLeft(){
cout << *this << " Double Left"<<endl;
	right->rotateRight();
	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();
	rotateLeft();
}

void BSTNode::doubleRight(){
cout << *this << " Double Right"<<endl;
	left->rotateLeft();
	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();
	rotateRight();
}

int BSTNode::numChildren(){
	if (!this) return 0;
	return leftDescendants + rightDescendants;
}

bool BSTNode::Insert( int value ){
//cout << "this: "<<value << " " << *this<<endl;
	//BSTNode *next = NULL;
	if (value < this->value) {
		if (left == NULL) {
			leftDescendants++;
			balance = calBalance(this);
			left = new BSTNode(value);
			return true;
		}
		//next = left;
		left->Insert(value);
		fixMetaData();
cout << "left: " << balance <<" is balance? " << (int) isBalance() << " " << *this<< endl;
//cout << "HEY:" << *this << " " <<*left<< " " << (int) isBalance() << " " << left->isBalance()<<endl;
		if (isBalance()) return true;
		if (rightDescendants < leftDescendants){
cout << "left is balance : " << (int)left->isBalance() << " " << *left<< endl;
			if (left->isBalance() && left->numChildren() > 1){
				doubleRight();
			} else {
				rotateRight();
			}
		} else{
// throw "HIH";
			if (right->isBalance()&& right->numChildren() > 1){
				doubleLeft();
			} else {
				rotateLeft();
			}
		}
	} else if (value > this->value) {
		if (right == NULL) {
			rightDescendants++;
			balance = calBalance(this);
			right = new BSTNode(value);
			return true;
		}
		//next = right;
		right->Insert(value);
		fixMetaData();
cout << "right: " << balance <<" is balance? " << (int) isBalance() << " " << *this<< endl;
		if(isBalance()) return true;
		if (leftDescendants < rightDescendants){
			if (right->isBalance()&& right->numChildren() > 1){
				doubleLeft();
			} else {
				rotateLeft();
			}
		} else {
			//throw 1;
			if (left->isBalance()&& left->numChildren() > 1){
				doubleRight();
			} else {
				rotateRight();
			}
		}
	} else { // equal
		return false;
	}

	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();
	return true;
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
