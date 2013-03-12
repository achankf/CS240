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
	//cout << *node << ' ' << (left ? (float) right / left : 0) << endl;
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
	bool ret = root->Insert(value);
	std::cout << set_color(GREEN) << "Inserted " << value << ' ';
	print();
	std::cout << set_color();

	if (!ret) return false;

	BSTNode **iterator = &root;
	while(*iterator){
		BSTNode *cur = *iterator;
		BSTNode *left = cur->left;
		BSTNode *right = cur->right;

cout << "IS " << *cur  << " " << " BALANCED? "<<(int)cur->isBalance() << endl;
		if(cur->isBalance()){
			if (value > cur->value){
				iterator = &right;
			} else if (value < cur->value){
				iterator = &left;
			} else {
				return true;
			}
			continue;
		}

		if (cur->leftDescendants > cur->rightDescendants){
			cout << *cur  << "  " << **iterator<< " LEFT HEAVY"<<endl;
			rotateRight(iterator);
		} else {
			cout << *cur  << "  " << **iterator<< " RIGHT HEAVY"<<endl;
			rotateLeft(iterator);
		}
		cur = *iterator;
		left = cur->left;
		right = cur->right;
		if (cur->left){
			left->fixMetaData();
		}
		if (cur->right){
			right->fixMetaData();
		}
		cur->fixMetaData();
cout << "PPPP"<<endl;
print();
	}

	return ret;
}

void BSTNode::fixMetaData(){
	cout << "Fixing " << *this << endl;
	leftDescendants = weight(left);
	rightDescendants = weight(right);
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
