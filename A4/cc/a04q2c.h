#ifndef A04Q2C_H
#define A04Q2C_H


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
      BSTNode( int value );

      bool Insert(int value);
      bool Search(int value);

      int Value() const { return value; }
      BSTNode* Left() const { return left; }
      BSTNode* Right() const { return right; }

      float Balance() const { return balance; }
      int LeftDescendants() const { return leftDescendants; }
      int RightDescendants() const { return rightDescendants; } 
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

      BSTNode* Root() const { return root; }
};


#endif
