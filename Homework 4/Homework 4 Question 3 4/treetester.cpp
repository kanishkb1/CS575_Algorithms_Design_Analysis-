/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;      
   BST node;      // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
      intBST.insertAVLOperation(number);
      (number);
   }
   
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";
   cout << "\nPreOrder of BST and AVl.";
   intBST.printPreOrderBSTAVL();
   
   for(;;){
      cout << "\nEnter the option";
      cout << "\n 1)Insert";
      cout << "\n 2)AVL Tree generation";
      cout << "\n 3)Deletion\n";
      int op=0;
      cin >> op;
      switch(op){
         case 1: {
            cout << "\nInsert Element in to AVL\n";
            cin >> number;
            intBST.insertAVLOperation(number);
          }
          break;
         case 2: {
             cout << "\nPreOrder of AVL\n";
             intBST.printPreOrder();
          }
          break;
         case 3: {
            cout << "\nDelete Element in AVL\n";
            int k;
            cin >> k;
            intBST.deleteN(k);
         }
         break;
      
      default: cout<< "option";
      break;
      }
   }



}
