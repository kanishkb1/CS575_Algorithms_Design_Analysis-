#include <iostream>
using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      //left side of the tree
      if (item < locptr->data)      
         locptr = locptr->left;
      else if (locptr->data < item)  
      //right side of the tree
         locptr = locptr->right;
      else                           
      //if item found
         found = true;
   }
   if (!found)
   {  
       // construct node containing item
      locptr = new BinNode(item);  
      //condition for empty tree
      if (parent == 0)               
         myRoot = locptr;
      //insertion in the left side as (item > parent's data)   
      else if (item < parent->data )  
         parent->left = locptr;
      // insertion in the right side as (item > parent's data)   
      else                           
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}
//Problem 1: Part a-> preOrder() function
//preorder operation
//flow of preorder = root node -> left side -> right side
void BST::preOrder_operation(BinNode* cnode)const{
    BinNode * locptr = myRoot;   
    BinNode * parent = 0; 
    
    if(cnode!=0){
            cout<<cnode->data<<"\n";
            preOrder_operation(cnode->left);
            preOrder_operation(cnode->right);
           
    }
    
}
void BST::preOrder()const{
    BinNode * locptr = myRoot;   
    BinNode * parent = 0; 
    preOrder_operation(myRoot);
}
//Problem 1: Part b-> inOrder() function
//inorder operation
//flow of inorder operation = left side-> root node -> right side
void BST::inOrder_operation(BinNode* cnode)const{
    BinNode * locptr = myRoot;   
    BinNode * parent = 0; 
    
    if(cnode!=0){
            inOrder_operation(cnode->left);
            cout<<cnode->data<<"\n";
            inOrder_operation(cnode->right);
    }
    
}
void BST::inOrder()const{
    BinNode * locptr = myRoot;   
    BinNode * parent = 0; 
    inOrder_operation(myRoot);
}

//Problem 1: part c -> nodeCount()
//counting of nodes operation
//transversing through left and right side of the tree 
int BST::nodecount_operation(BinNode* cnode, int total)const{
    
    if(cnode==0){
        return 0;
   
    }
    else{
    total = 1+nodecount_operation(cnode->left,total)+nodecount_operation(cnode->right,total);    
    return total;
    }   
}
void BST::nodecount()const{
    BinNode * locptr = myRoot;   
    BinNode * parent = 0; 
    int total = 0;
    total=  nodecount_operation(myRoot,0);
    cout<<"\nTotal number of nodes is : "<<total;
}



//Problem 2: delete member of the function 

void BST::deletenode(const int & item)
{
   BinNode * locptr = myRoot;   
   BinNode * parent = 0;        
   bool found = false;     
   while (!found && locptr != 0)
   {
      
      if (item < locptr->data) {
        parent = locptr;
        locptr = locptr->left;
    }
         
      else if (locptr->data < item){
        parent =locptr;
        locptr = locptr->right;
      
    }
      else{
        cout<<parent->data<<"\n"<<locptr->data;
        found = true;
    }                         
     
   }
   if (!found)
    {                                 
      cout << "Given value not available";
      cout << "Deletion is not possible.\n";
    }
    
    if(found){
        
        if(parent==0){
                cout<<"This is root";
            }
        else{
            //Left child documentation
            if(parent->left->data==locptr->data){
                
                cout<<"Left Child\n";
                if(locptr->left==0 && locptr->right==0){
                    cout<<"Case a:The Node has no children (easiest case)\n";
                    parent->left=0;
                    
                }
                else if(locptr->left==0 || locptr->right==0){
                    cout<<"Case b: The Node has one child (easy case)\n";
                    if(locptr->left!=0)
                        parent->left=locptr->left;
                    else
                        parent->left=locptr->right;
                }
                else {
                    cout<<"Case c: The Node has two Childs (hard case)\n";
                    locptr=locptr->right;
                    BinNode *parenttemp;
                    while(locptr!=0 && locptr->left!=0){
                         parenttemp= locptr;
                        locptr=locptr->left;
                    }
                    
                    cout<<locptr->data;
                    if(locptr->right==0){
                        parent->left->data = locptr->data;
                        parenttemp->left = 0;
                    }
                    else{
                        parent->left->data = locptr->data;
                        parenttemp->left = locptr->right;           
                    }
                }
                cout<<"\nIn Order after deletion\n";
                inOrder();
            }
            else{                                           
                cout<<"Right Child";
                if(locptr->left==0&&locptr->right==0){
                    cout<<"Case a:The Node has no children (easiest case)\n";
                    parent->right=0;
                }
                else if(locptr->left==0||locptr->right==0){
                    cout<<"Case b: The Node has one child (easy case)\n";
                    if(locptr->left!=0)
                        parent->right=locptr->left;
                    else
                        parent->right=locptr->right;
                }
                else {
                    cout<<"Case c: The Node has two Childs (hard case)";
                    cout<<"Data on temp"<<parent->data;
                    cout<<locptr->data;
                    locptr=locptr->right;
                    BinNode *parenttemp;
                    while(locptr!=0&&locptr->left!=0){
                         parenttemp= locptr;
                        locptr=locptr->left;
                    }
                    cout<<locptr->data;
                    if(locptr->right==0){
                        parent->right->data = locptr->data;
                        parenttemp->left = 0;
                    }
                    else{
                        parent->right->data = locptr->data;
                        parenttemp->left = locptr->right;   
                    }  
                }
                cout<<"\nIn Order after deletion\n";
                inOrder();
            } 
        }
    }            
}
