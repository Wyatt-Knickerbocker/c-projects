/* TestBSTree.cpp
 *   Test Binary Search Tree (BST)
 */

#include <iostream>

#include "BSTree.h"

using namespace std;


int main()
{
   static DATA_TYPE A[8] = { 15, 53, 13, 61, 
                             57, 47, 21, 51 };
   static int nA = sizeof(A)/sizeof(DATA_TYPE);
   
   static DATA_TYPE B[] = { 48, 54, 14, 52, 
                             8, 16, 63, 10, 1 };
   static int nB = sizeof(B)/sizeof(DATA_TYPE);
   
   BinarySearchTree  t1;
   BinarySearchTree  t2;
     

   for (int i = 0; i < nA; i++)
       t1.AddNode( A[i] );
       
   for (int i = 0; i < nB; i++)
       t2.AddNode( B[i] );  

   cout << "\n The Binary Search Tree using ";
   cout << "a Backward PostOrder traversal:" << endl;
   t1.PrintBackwardPostOrder();
   
   cout << "\n The Binary Search Tree using ";
   cout << "an InOrder traversal:" << endl;
   t1.PrintInOrder();
   
   cout << "\n The Binary Search Tree using ";
   cout << "a PreOrder traversal:" << endl;
   t1.PrintPreOrder();
   
   cout << "\n The Binary Search Tree using ";
   cout << "a PostOrder traversal:" << endl;
   t1.PrintPostOrder();
   
       //  Test deletion
   cout << "\n\n Deleting node(s)" << endl;
   cout << "    deleting  61 and 47" << endl;
   t1.DeleteNode( 61 );
   t1.DeleteNode( 47 );
   t1.PrintBackwardPostOrder();
   
   cout << "\n\n Deleting entire tree" << endl;
   cout << "    (Tree should be empty)" << endl;
   t1.~BinarySearchTree();
   t1.PrintInOrder();
   
       //  Display second tree
   cout << "\n The Binary Search Tree using ";
   cout << "a Backward PostOrder traversal:" << endl;
   t2.PrintBackwardPostOrder();

   
   t2.SearchNode(45);
   t2.SearchNode(48);   //  root
   t2.SearchNode(52);

   //return EXIT_SUCCESS;
   return 0;
}
 
