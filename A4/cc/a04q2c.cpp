#include "a04q2c.h"

#include <iostream>
using namespace std;

static int weight(BSTNode *node){
	if (node == NULL) return 0;
#if 0
	int left = node->LeftDescendants();
	int right = node->RightDescendants();
	return 1 + left + right;
#endif
	return nodesize(node);
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
	print(value);
	if (root == NULL) {
		root = new BSTNode(value);
		return true;
	}
	cout << endl << "START"<<endl;
	bool ret = root->Insert(value);
	print(value);
	return ret;
}

void BSTNode::fixMetaData(){
	if (!this) return;
	leftDescendants = weight(left);
	rightDescendants = weight(right);
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

	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();
	cout << "SUBTREE:" << endl;print_helper(this, 0, this->value);
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

	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();

	cout << "SUBTREE:" << endl;print_helper(this, 0, this->value);
	cout << endl;
}

void BSTNode::doubleLeft(){
cout << *this << " Double Left"<<endl;
	right->rotateRight();
	rotateLeft();
	if (!right->isBalance()){
cout << "Encore: " << *this << " (right in DL) " << *right << endl;
		//if (right && right->rightDescendants > right->leftDescendants){
		BSTNode *grandchild = right->right;
cout << "grandchild: "; if (grandchild){
	cout << *grandchild << " " << grandchild->leftDescendants << ' ' <<  right->leftDescendants;
	} cout<<std::endl;
		if (grandchild && (
			(grandchild->leftDescendants == right->leftDescendants && right->leftDescendants != 0) ||
			(grandchild->rightDescendants < grandchild->leftDescendants))){
		//if (grandchild && grandchild->rightDescendants < grandchild->leftDescendants){
			right->doubleLeft();
		} else{
			right->rotateLeft();
		}
	}
	if (!left->isBalance()){
cout << "Encore: " << *this <<" (left in DL) " << *left<< endl;
		BSTNode *grandchild = left->left;
cout << "grandchild: "; if (grandchild){
	cout << *grandchild << " " << grandchild->rightDescendants << ' ' <<  left->rightDescendants ;
	} cout<<std::endl;
		if (grandchild && (
			(grandchild->rightDescendants == left->rightDescendants && left->rightDescendants != 0) ||
			(grandchild->leftDescendants < grandchild->rightDescendants))){
		//if (grandchild && grandchild->leftDescendants < grandchild->rightDescendants){
			left->doubleRight();
		} else{
			left->rotateRight();
		}
	}
}

void BSTNode::doubleRight(){
cout << *this << " Double Right"<<endl;
	left->rotateLeft();
	rotateRight();
#if 0
	if (!left->isBalance()) left->rotateRight();
	if (!right->isBalance()) right->rotateLeft();
#endif
	if (!right->isBalance()){
cout << "Encore: " << *this << " (right in DL) " << *right << endl;
		BSTNode *grandchild = right->right;
cout << "grandchild: "; if (grandchild){
	cout << *grandchild << " " << grandchild->leftDescendants << ' ' <<  right->leftDescendants;
	} cout<<std::endl;
		if (grandchild && (
			(grandchild->leftDescendants == right->leftDescendants && right->leftDescendants != 0) ||
			(grandchild->rightDescendants < grandchild->leftDescendants))){
			right->doubleLeft();
		} else{
			right->rotateLeft();
		}
	}
	if (!left->isBalance()){
cout << "Encore: " << *this <<" (left in DL) " << *left<< endl;
		BSTNode *grandchild = left->left;
cout << "grandchild: "; if (grandchild){
	cout << *grandchild << " " << grandchild->rightDescendants << ' ' <<  left->rightDescendants ;
	} cout<<std::endl;
		if (grandchild && (
			(grandchild->rightDescendants == left->rightDescendants && left->rightDescendants != 0) ||
			(grandchild->leftDescendants < grandchild->rightDescendants))){
		//if (grandchild && grandchild->leftDescendants < grandchild->rightDescendants){
			left->doubleRight();
		} else{
			left->rotateRight();
		}
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
			balance = calBalance(this);
			left = new BSTNode(value);
			return true;
		}
		left->Insert(value);
		fixMetaData();
		cout << "left: " << balance <<" is balance? " << (int) isBalance() << " " << *this<< endl;
		if (isBalance()) return true;
		if ((rightDescendants == left->rightDescendants && rightDescendants != 0)
			|| (left->isBalance() && left->rightDescendants > left->leftDescendants)){
			doubleRight();
		} else {
			rotateRight();
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
		if ((leftDescendants == right->leftDescendants && leftDescendants != 0)
			|| (right->isBalance() && right->leftDescendants > right->rightDescendants)){
			doubleLeft();
		} else {
			rotateLeft();
		}
	} else { // equal
		return false;
	}

	this->fixMetaData();
#if 0
	this->fixMetaData();
	this->left->fixMetaData();
	this->right->fixMetaData();
#endif
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
