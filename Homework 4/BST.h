#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void deletenode(const int & item);
  void preOrder()const;
  void inOrder()const;
  void nodecount()const;
  
  
 private:

  /***** Node class *****/
  class BinNode 
  {
    
    public:
      
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 
  void preOrder_operation(BinNode* node)const;
  void inOrder_operation(BinNode* node)const;
  int nodecount_operation(BinNode* node,int total)const;
}; // end of class declaration

#endif

