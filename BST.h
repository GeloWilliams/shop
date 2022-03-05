/** @file BST.h
   Angelo Williams | Student No. 2101031
   2022.02
   Program 4 : Object Oriented Design Shop

   This program serves as a shop model that mimics five basic operations. 
   The actions below are defined in terms of the program's scope:
      
      sell : removes an item from the store inventory

      buy : adds an item to the store inventory

      display : outputs the entire inventory, including the number of each item

      customer : outputs all transactions for an individual customer in chronological order 
      (includes items for each transaction)

      history : outputs the transactions of all customers, sorted by customer name

   There are three types of products that the store contains:

   BSTs		| 	comics	|	sports cards

   This program will process transactions based on a list of commands from an external input file. 
   The user will then be able to view the current inventory, a single customer's list of transactions, or an
   entire list of transactions for all customers. The preconditions for viewing these changes, however, is to 
   initialize the inventory list and customers from two separate input files. A third input file will contain the 
   list of transaction commands. 
   
   I/O: While the products may vary, valid input must follow basic formatting rules. Each product must include the 
   following details for each of the five categories below, separated by a comma:

      name, quantity, year, grade

   For name, "BST type" may be used for BSTs, "title" may be used for comics, and "player" may be used for 
   sports cards. A sixth category would be required for both comics and sports cards:

      publisher or manufacturer

   Key Variables: hashTable_ holds all product object pointers. The Customer and Inventory objects may point to objects
   in hashTable_, however, only either the Customer or Inventory will never point to the same item simultaneously.

   Exceptions: Any incorrect formatting within a file that contains some correct formatting will be ignored. 
   If all entries are incorrectly formatted, an error message will be printed to the user. */

#pragma once
#include <iostream>
#include <vector>
#include "Comparable.h"
#include "ProductFactory.h"
using namespace std;

class BST {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new BST object has been instantiated.  */
      BST() : rootPtr(nullptr) {}

      /**  -----------------------------------------------------------------
         Copy Constructor 
         -- Creates a copy of BST passed as a parameter
         -- Calls copyTree to duplicate BST in *this
         @pre:      none
         @post:     BST is copied into *this
         @param BST: BST object to be copied */
      BST(const BST &ST);

      /**  -----------------------------------------------------------------
         Destructor
         -- Calls clearTree
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      ~BST();

      /**  -----------------------------------------------------------------
         Assignment operator 
         -- Copies BST on the righthandside of the assignment
         -- Calls treeCheck to check for self assignment
         -- Calls makeEmpty to clear the current tree and set rootPtr to nullptr
         -- Calls copyTree to duplicate rhs in *this
         @pre:       an identical BST is not present on both sides of the assignment
         @post:      *this is assigned the same BST as rhs
         @param rhs: BST object to be copied */
      BST& operator=(const BST &rhs);

      /**  -----------------------------------------------------------------
         Comparison Operator 
         @pre:       none.
         @post:      returns true if *this is equal to rhs
         @param rhs: BST on the righthand side of the equation 
         @return:    true if *this is equal to rhs, false otherwise */
      bool operator==(const BST &rhs) const;

      /**  -----------------------------------------------------------------
         insert
         -- Calls add to create a node with the Comparable value passed with a
            quantity of 1 or increases quantity by 1
         @pre         none. 
         @post:       a node is created with the value passed or the quantity is
                      increased.
         @param comp: the Comparable to be passed
         @return:     true if a new node is created, false otherwise */
      bool insert(Comparable *comp);

      /**  -----------------------------------------------------------------
         remove
         -- If the Comparable is present, decreases quantity by 1 or removes
            the node if the quantity is 1 
         @pre:        BST is not empty.
         @post:       quantity of this Comparable is decreased or a node 
                      has been removed.
         @param comp: the Comparable in which one occurrence is to be removed
         @return:     true if the Comparable is present, false otherwise */
      bool remove(const Comparable &comp);

      /**  ----------------------------------------------------------------- 
         retrieve
         -- Finds and returns a Comparable within BST if present
         @pre:        none.
         @post:       none.
         @param comp: the Comparable to be found
         @return:     a Comparable pointer */
      const Comparable* retrieve(const Comparable &comp) const;

      /**  -----------------------------------------------------------------
         Output Stream operator
         -- Prints a table of Comparables with associated quantities 
         -- calls printInOrder
         @pre:        none. 
         @post:       BST data is sent to the Output Stream
         @param:      the Output Stream
         @param node: node of BST, starting at root node */
      friend std::ostream& operator<<(std::ostream &out, BST& BT);

   private:
      struct Node {
         /**  -----------------------------------------------------------------
            Constructor */
         Node() : item(nullptr), quantity(0),
            leftChild(nullptr), rightChild(nullptr) {}

         /** item: A Comparable pointer */
         Comparable *item;
         /** quantity: Holds the number of times the value is present within 
            BST */
         int quantity;
         Node *leftChild;
         /** rightChild: A pointer to the right child of current node */
         Node *rightChild;
      };
      
      /**  -----------------------------------------------------------------
         copyTree
         -- Creates a deep copy of a BST
         @pre:        none.
         @post:       a deep copy of BST is created.
         @param node: the root node of the BST to be created.
         @return:     a new BST pointer */
      Node* copyTree(const Node *node) const;

      /**  -----------------------------------------------------------------
         clearTree
         -- Deallocates and removes all nodes within BST
         @pre:        BST is not empty.
         @post:       BST is empty.
         @param node: the root node of the BST to be cleared. */
      void clearTree(Node *node);

      /**  -----------------------------------------------------------------
         treeCheck
         -- Helper method for the Comparison operator
         @pre:         Two BSTs to be compared.
         @post:        none.
         @param nodeA: BST node to be compared.
         @param nodeB: BST node to be compared.
         @return:      True if equal, false otherwise */
      bool treeCheck(Node *nodeA, Node *nodeB) const;

      /**  -----------------------------------------------------------------
         makeEmpty
         -- Removes and deallocates all of the data from the tree
         @pre:  BST is not empty.
         @post: Tree is empty. */  
      void makeEmpty();

      /**  -----------------------------------------------------------------
         add
         -- Helper method for insert, responsible for checking and locating 
            present values within BST. Increases quantity by 1
         @pre:        none. 
         @post:       a reconstructed BST with a newly created node with the 
                      value passed or the quantity is increased.
         @param node: the root node of BST
         @param comp: the Comparable to be passed
         @param flag: boolean to be returned to insert
         @return:     a pointer to the root node of BST */
      Node* add(Node *node, Comparable *comp, bool flag);

      /**  -----------------------------------------------------------------
         contains
         -- Helper method the checks whether a Comparable value is 
            present within BST
         @pre:        none. 
         @post:       none.
         @param node: the root node of BST
         @param comp: the Comparable to be found
         @return:     true if Comparable is present, false otherwise */
      bool contains(Node *node, Comparable *comp) const;

      /**  -----------------------------------------------------------------
         deleteNode
         -- Helper method for remove, responsible for decreasing quantity and
            returning a boolean value to remove
         @pre:        BST is not empty.
         @post:       quantity is decreased or a node has been removed.
         @param node: the root node of BST
         @param comp: the Comparable in which one occurrence is to be removed
         @return:     true if the Comparable is present, false otherwise */
      bool deleteNode(Node *&node, const Comparable &comp);

      /**  -----------------------------------------------------------------
         removeRoot
         -- Helper method for deleteNode, responsible for handling each case for
            the type of node to be removed
         @pre:        none. 
         @post:       quantity is decreased or a node has been removed.
         @param node: the root node of BST
         @return:     true if the Comparable is present, false otherwise */
      void removeRoot(Node *&node);

      /**  -----------------------------------------------------------------
         lMaxandComp
         -- Helper method for removeRoot, responsible for finding the most-right
            descendant of the left subtree for the target node to be removed;
            returns the Comparable value
         @pre:        none. 
         @post:       the most-right node of the left subtree is removed and 
                      its Comparable is copied.
         @param node: the target node to be removed
         @return:     a pointer to the Comparable */
      Comparable* lMaxAndComp(Node *&node) const;

      /**  -----------------------------------------------------------------
         lMaxandInt
          -- Helper method for removeRoot, responsible for finding the most-right
             descendant of the left subtree for the target node to be removed;
             returns the quantity value
         @pre:        none. 
         @post:       the most-right node of the left subtree is removed and 
                      its Comparable is copied.
         @param node: the target node to be removed
         @return:     a integer value, representing quantity */
      int lMaxAndInt(const Node *node) const;

      /**  -----------------------------------------------------------------
         fetch
         -- Helper method for retrieve, responsible for finding the target 
            Comparable in BST.
         @pre:        none. 
         @post:       none.
         @param node: the root node of BST
         @param comp: the Comparable to find
         @return:     a pointer to the Comparable or nullptr if not found */
      Comparable* fetch(Node *node, const Comparable &comp) const;

      /**  -----------------------------------------------------------------
         printInorder
         -- Prints a table of Comparables with associated quantities 
            in BST using inorder
         @pre:        none. 
         @post:       BST data is sent to the Output Stream
         @param:      the Output Stream
         @param node: node of BST, starting at root node */
      void printInorder(std::ostream& out, Node* node) const;

      /** rootPtr: A pointer to the root node */
      Node *rootPtr;
};