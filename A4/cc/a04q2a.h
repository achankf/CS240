#ifndef A04Q2A_H
#define A04Q2A_H


#include <cstddef>


class BSTNode {
private:
      int value;
      BSTNode* left;
      BSTNode* right;
      
      float balance;
      int leftDescendants;
      int rightDescendants;

public:
      BSTNode(int value) {
            this->value = value;
            left = NULL;
            right = NULL;
      }

      bool Insert(int value);
      bool Search(int value);

      int GetValue() const { return value; }
      BSTNode* GetLeft() const { return left; }
      BSTNode* GetRight() const { return right; }

      float Balance() const { return balance; }
      int GetLeftDescendants() const { return leftDescendants; }
      int GetRightDescendants() const { return rightDescendants; } 
};


class BinarySearchTree {
private:
      BSTNode* root;

public:
      BinarySearchTree() {
            root = NULL;
      }

      bool Insert(int value);
      bool Search(int value);

      BSTNode* GetRoot() const { return root; }
};


#endif
