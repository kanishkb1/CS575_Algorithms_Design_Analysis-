#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool  empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void insertAVLOperation(int key) ;
  void deleteN(int key);
  void printPreOrderBSTAVL();
  void printPreOrder(); 
  

  
 private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;
    int height=0;

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
  BinNode * avl_root;
  int i=0;

  


/////////////////////////////////////////////////////////////////


int height(BinNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}

BinNode* newNode(int key)
{
    BinNode* node = new BinNode();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
 
BinNode *rightRotate(BinNode *y)
{
    BinNode *x = y->left;
    BinNode *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    return x;
}
 BinNode *leftRotate(BinNode *x)
{
    BinNode *y = x->right;
    BinNode *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(BinNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

BinNode* insertAVL(BinNode* node, int key)
{

    if (node == NULL)
        return(newNode(key));
 
    if (key < node->data)
        node->left = insertAVL(node->left, key);
    else if (key > node->data)
        node->right = insertAVL(node->right, key);
    else 
        return node;

    node->height = 1 + max(height(node->left),
                        height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

BinNode * minValueNode(BinNode * node)
{
    BinNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

BinNode * deleteNode(BinNode *root, int key){
    if (root == NULL)
        return root;

    if ( key < root->data )
        root->left = deleteNode(root->left, key);
    else if( key > root->data )
        root->right = deleteNode(root->right, key);
    else
    {
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            BinNode *temp = root->left ?
                         root->left :
                         root->right;
 
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
            *root = *temp; 
            free(temp);
        }
        else
        {
            BinNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    if (root == NULL)
    return root;
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;

}
  
  void preOrder(BinNode *node){
        if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
  }



}; // end of class declaration

#endif
