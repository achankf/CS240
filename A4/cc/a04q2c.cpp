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
	return ret;
}

static bool isBalance(BSTNode *node){
	if (!node) return true;
	BSTNode *left = node->Left();
	BSTNode *right = node->Right();

	// at most one child
	if ((!left && !right) &&
		((left || right) && (!left || !right))) return true;
	return node->Balance() >= 0.5 && node->Balance() <= 2;
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

	// is already in balance
	if(isBalance(this)) return temp;

	if (balance > 2){
cout << *this << " RIGHT HEAVY"<<endl;
#if 0
		BSTNode *newNode = new BSTNode(this->value);
		newNode->left = left;
		newNode->right= right->left;
		this->value = right->Value();
		right = right->right;
		left = newNode;
#endif 

		BSTNode *newNode = new BSTNode(this->value);
		newNode->right = right;
		newNode->left= left->right;
		this->value = left->Value();
		left = left->left;
		right = newNode;
	} else if (balance < 0.5){
cout << *this<< " LEFT HEAVY"<<endl;
		BSTNode *newNode = new BSTNode(this->value);
		newNode->left = left;
		newNode->right= right->left;
		this->value = right->Value();
		right = right->right;
		left = newNode;
		
#if 0
		BSTNode *newNode = new BSTNode(this->value);
		newNode->right = right;
		newNode->left= left->right;
		this->value = left->Value();
		left = left->left;
		right = newNode;
#endif
	}
	this->leftDescendants = weight(this->left);
	this->rightDescendants = weight(this->right);
	this->balance = calBalance(this);
	if (left){
		left->leftDescendants = weight(left->left);
		left->rightDescendants = weight(left->right);
		left->balance = calBalance(left);
	}
	if (right){
		right->leftDescendants = weight(right->left);
		right->rightDescendants = weight(right->right);
		right->balance = calBalance(right);
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
