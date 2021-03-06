#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }



void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}


void BST::insertAVLOperation(int key){
   avl_root=insertAVL(avl_root,key);
}

void BST::deleteN(int key)
{
   avl_root=deleteNode(avl_root,key);
   preOrder(avl_root);
}

void BST::printPreOrder(){
   preOrder(avl_root);
}
void BST::printPreOrderBSTAVL(){
   cout<<"\nPreorder of BST\n";
   preOrder(myRoot);
   cout<<"\nPreorder of AVL\n";
   preOrder(avl_root);
}


