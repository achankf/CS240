#include "a04q2a.h"


bool BinarySearchTree::Insert(int value) {
      if (root == NULL) {
            root = new BSTNode(value);
            return true;
      } else
            return root->Insert(value);
}

bool BSTNode::Insert(int value) {
      if (value == this->value)
            return false;
      else if (value < this->value) {
            if (left == NULL) {
                  left = new BSTNode(value);
                  return true;
            } else
                  return left->Insert(value);
      } else if (value > this->value) {
            if (right == NULL) {
                  right = new BSTNode(value);
                  return true;
            } else
                  return right->Insert(value);
      }
      return false;
}

bool BinarySearchTree::Search(int value) {
      if (root == NULL)
            return false;
      else
            return root->Search(value);
}

bool BSTNode::Search(int value) {
      if (value == this->value)
            return true;
      else if (value < this->value) {
            if (left == NULL)
                  return false;
            else
                  return left->Search(value);
      } else if (value > this->value) {
            if (right == NULL)
                  return false;
            else
                  return right->Search(value);
      }
      return false;
}
