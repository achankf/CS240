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
	std::cout << set_color(RED) << "Inserting " << value << ' ';
	print();
	std::cout << set_color() << endl;
	if (root == NULL) {
		root = new BSTNode(value);
		return true;
	}
	if (!root->Insert(value)) return false;

	bool ret = root->Insert(value);
	std::cout << set_color(GREEN) << "Inserted " << value << ' ';
	print();
	std::cout << set_color();

	BSTNode **iterator = &root;
int i = 0;
	while(*iterator){
if (i++ == 10){
	throw 3;
}
cout <<"START"<<endl;
		BSTNode *cur = *iterator;

cout << "IS " << *cur  << " " << **iterator<< " BALANCED? "<<(int)cur->isBalance() << endl;

		if(cur->isBalance()){
			if (value > cur->value){
				// notice that I want the POSITION of cur->right, and not BSTNode *right above
				iterator = &(cur->right);
			} else if (value < cur->value){
				iterator = &(cur->left);
			} else {
				return true;
			}
cout << "TEMP"<<endl;
			continue;
		}

	print();
		if (cur->leftDescendants > cur->rightDescendants){
			cout << *cur  << "  " << **iterator<< " LEFT HEAVY"<<endl;
			rotateRight(iterator);
		} else if (cur->leftDescendants < cur->rightDescendants){
			cout << *cur  << "  " << **iterator<< " RIGHT HEAVY"<<endl;
			if (cur->
			rotateLeft(iterator);
		} else {
			throw 3;
		}

		// cur is now INVALID since rotateLeft/Right mutates the position of the tree

		// update meta data in ORDER (chilren then root)
		(*iterator)->left->fixMetaData();
		(*iterator)->right->fixMetaData();
		(*iterator)->fixMetaData();
	}

	return ret;
}

void BSTNode::fixMetaData(){
	cout << "Fixing " << *this << " ";
	leftDescendants = weight(left);
	rightDescendants = weight(right);
cout << weight(left) << " " << weight(right) << endl;
	balance = calBalance(this);
}

bool BSTNode::isBalance(){
	// at most one child
	if (leftDescendants + rightDescendants <= 1)
		return true;
	return balance >= 0.5 && balance <= 2;
}

void BinarySearchTree::rotateLeft(BSTNode **tar){
	cout << **tar << " Rotate Left"<<endl;
	BSTNode *bak = *tar;
	BSTNode *root = bak->right;
	bak->right = root->left;
	*tar = root;
	root->left = bak;
}

void BinarySearchTree::rotateRight(BSTNode **tar){
	cout << **tar << " Rotate Right"<<endl;
	BSTNode *bak = *tar;
	BSTNode *root = bak->left;
	bak->left = root->right;
	*tar = root;
	root->right = bak;
}

void BinarySearchTree::doubleLeft(BSTNode **tar){
	rotateRight(&((*tar)->right));
	rotateLeft(tar);
}

void BinarySearchTree::doubleRight(BSTNode **tar){
	rotateLeft(&((*tar)->left));
	rotateRight(tar);
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
