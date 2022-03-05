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

   coins		| 	comics	|	sports cards

   This program will process transactions based on a list of commands from an external input file. 
   The user will then be able to view the current inventory, a single customer's list of transactions, or an
   entire list of transactions for all customers. The preconditions for viewing these changes, however, is to 
   initialize the inventory list and customers from two separate input files. A third input file will contain the 
   list of transaction commands. 
   
   I/O: While the products may vary, valid input must follow basic formatting rules. Each product must include the 
   following details for each of the five categories below, separated by a comma:

      name, quantity, year, grade

   For name, "coin type" may be used for coins, "title" may be used for comics, and "player" may be used for 
   sports cards. A sixth category would be required for both comics and sports cards:

      publisher or manufacturer

   Key Variables: hasBSTable_ holds all product object pointers. The Customer and Inventory objects may point to objects
   in hasBSTable_, however, only either the Customer or Inventory will never point to the same item simultaneously.

   Exceptions: Any incorrect formatting within a file that contains some correct formatting will be ignored. 
   If all entries are incorrectly formatted, an error message will be printed to the user. */

#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

/**  -----------------------------------------------------------------
   Copy Constructor 
   -- Creates a copy of BST passed as a parameter
   -- Calls copyTree to duplicate BST in *this
   @pre:       none
   @post:      BST is copied into *this
   @param BST: BST object to be copied */
BST::BST(const BST &ST)
{
   rootPtr = copyTree(ST.rootPtr);
} // end Copy Constructor


/**  -----------------------------------------------------------------
   copyTree
   -- Creates a deep copy of a BST
   @pre:        none.
   @post:       a deep copy of BST is created.
   @param node: the root node of the BST to be created.
   @return:     a new BST pointer */
BST::Node* BST::copyTree(const Node *node) const
{
   if (node == nullptr) {
      return nullptr;
   }
   // Create a new node, new Comparable and copy items
   Node* nn = new Node();
   Comparable* nc = new Comparable();

   nc = node->item;
   nn->item = nc;
   nn->quantity = node->quantity;
   
   // Visit left & right children
   nn->leftChild = copyTree(node->leftChild);
   nn->rightChild = copyTree(node->rightChild);

   // Return the node
   return nn;
} // end copyTree


/**  -----------------------------------------------------------------
   Destructor
   -- Calls clearTree
   @pre:  the Constructor has been called.
   @post: all data that was dynamically allocated has been removed and deallocated. */
BST::~BST()
{
   clearTree(rootPtr);
} // end Destructor


/**  -----------------------------------------------------------------
   clearTree
   -- Deallocates and removes all nodes within BST
   @pre:        BST is not empty.
   @post:       BST is empty.
   @param node: the root node of the BST to be cleared. */
void BST::clearTree(Node *node)
{
   if (node != nullptr) {
      if (node->leftChild != nullptr)
         clearTree(node->leftChild);
      if (node->rightChild != nullptr)
         clearTree(node->rightChild);
      delete node->item;
      delete node;
      node = nullptr;
   } // end if
} // end clearTree


/**  -----------------------------------------------------------------
   Assignment operator 
   -- Copies BST on the righthandside of the assignment
   -- Calls treeCheck to check for self assignment
   -- Calls makeEmpty to clear the current tree and set rootPtr to nullptr
   -- Calls copyTree to duplicate rhs in *this
   @pre:       an identical BST is not present on both sides of the assignment
   @post:      *this is assigned the same BST as rhs
   @param rhs: BST object to be copied */
BST& BST::operator=(const BST &rhs)
{
   if (!treeCheck(rootPtr, rhs.rootPtr)) {
      // Clear this tree
      makeEmpty();
      // Copy rhs tree
      rootPtr = copyTree(rhs.rootPtr);
   }
   return *this;
} // end =

/**  -----------------------------------------------------------------
   treeCheck
   -- Helper method for the Comparison operator
   @pre:         Two BSTs to be compared.
   @post:        none.
   @param nodeA: BST node to be compared.
   @param nodeB: BST node to be compared.
   @return:      True if equal, false otherwise */
bool BST::treeCheck(Node *nodeA, Node *nodeB) const
{
   if (nodeA == nullptr && nodeB == nullptr) {
      return true;
   } else if ((nodeA == nullptr && nodeB != nullptr)
      || (nodeA != nullptr && nodeB == nullptr)) {
         return false;
   } else {
      if(nodeA->item == nodeB->item 
         && nodeA->quantity == nodeB->quantity
         && treeCheck(nodeA->leftChild, nodeB->leftChild)
         && treeCheck(nodeA->rightChild, nodeB->rightChild)) {
         return true;  
      } else {
         return false;
      } // end if
   } // end if
} // end treeCheck


/**  -----------------------------------------------------------------
   makeEmpty
   -- Removes and deallocates all of the data from the tree
   @pre:  BST is not empty.
   @post: Tree is empty. */  
void BST::makeEmpty()
{
   clearTree(rootPtr);
   rootPtr = nullptr;
} // end makeEmpty


/**  -----------------------------------------------------------------
   Comparison operator 
   @pre:       none.
   @post:      returns true if *this is equal to rhs
   @param rhs: BST on the righthand side of the equation 
   @return:    true if *this is equal to rhs, false otherwise */
bool BST::operator==(const BST &rhs) const
{
   if (treeCheck(rootPtr, rhs.rootPtr))
      return true;
   return false;
} // end ==


/**  -----------------------------------------------------------------
   insert
   -- Calls add to create a node with the Comparable value passed with a
      quantity of 1 or increases quantity by 1
   @pre         none. 
   @post:       a node is created with the value passed or the quantity is
                increased.
   @param comp: the Comparable to be passed
   @return:     true if a new node is created, false otherwise */
bool BST::insert(Comparable *comp)
{  
   bool flag = false;
   // add node or increase quantity
   rootPtr = add(rootPtr, comp, flag);
   // return true if not already present
   return flag;
} // end insert


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
BST::Node* BST::add(Node *node, Comparable *comp, bool flag)
{
   if (node == nullptr) {
      Node* nn = new Node(); // create new node
      nn->item = comp;
      nn->quantity = 1;
      node = nn;
      flag = true;
   } else if (*(node->item) > *comp) {
      node->leftChild = add(node->leftChild, comp, flag);
   } else if (*(node->item) < *comp) {
      node->rightChild = add(node->rightChild, comp, flag);
   } else if (*(node->item) == *comp) {
      // delete item if already exists:
      delete comp;
      node->quantity += 1;
   } // end if
   return node;
} // end add


/**  -----------------------------------------------------------------
   contains
   -- Helper method the checks whether a Comparable value is 
      present within BST
   @pre:        none. 
   @post:       none.
   @param node: the root node of BST
   @param comp: the Comparable to be found
   @return:     true if Comparable is present, false otherwise */
bool BST::contains(Node *node, Comparable *comp) const
{
   if (node == nullptr) {
      return false;
   } else {
      if (*(node->item) > *comp) {
         return contains(node->leftChild, comp);
      } else if (*(node->item) < *comp) {
         return contains(node->rightChild, comp);
      } else if (*(node->item) == *comp) {
         return true;
      }
   } // end if
   return false;
} // end contains


/**  -----------------------------------------------------------------
   remove
   -- If the Comparable is present, decreases quantity by 1 or removes
      the node if the quantity is 1 
   @pre:        BST is not empty.
   @post:       quantity of this Comparable is decreased or a node 
                has been removed.
   @param comp: the Comparable in which one occurrence is to be removed
   @return:     true if the Comparable is present, false otherwise */
bool BST::remove(const Comparable &comp)
{
  return deleteNode(rootPtr, comp);
} // end remove

/**  -----------------------------------------------------------------
   deleteNode
   -- Helper method for remove, responsible for decreasing quantity and
      returning a boolean value to remove
   @pre:        BST is not empty.
   @post:       quantity is decreased or a node has been removed.
   @param node: the root node of BST
   @param comp: the Comparable in which one occurrence is to be removed
   @return:     true if the Comparable is present, false otherwise */
bool BST::deleteNode(Node *&node, const Comparable &comp)
{
   if (node == nullptr)
      return false;
   else if (comp == *node->item) {
      if (node->quantity < 2)
         removeRoot(node);
      else
         node->quantity -= 1;
      return true;
   } else if (comp < *node->item)
      return deleteNode(node->leftChild, comp);
   else
      return deleteNode(node->rightChild, comp);
}


/**  -----------------------------------------------------------------
   removeRoot
   -- Helper method for deleteNode, responsible for handling each case for
      the type of node to be removed
   @pre:        none. 
   @post:       quantity is decreased or a node has been removed.
   @param node: the root node of BST
   @return:     true if the Comparable is present, false otherwise */
void BST::removeRoot(Node *&node)
{
   // delete Comparable
   delete node->item;

   // Case 1 : Leaf:
   if (node->leftChild == nullptr && 
      node->rightChild == nullptr) {
      delete node;
      node = nullptr;
   } 
   // Case 2 : One Child Parent:
   else if (node->leftChild == nullptr ||
      node->rightChild == nullptr) {
      Node *temp = node;
      if (node->leftChild == nullptr) {
         node = node->rightChild;
      } else {
         node = node->leftChild;
      }
      delete temp;
   } 
   // Case 3 : Two Children Parent:
   else {
      node->quantity = lMaxAndInt(node->leftChild);
      node->item = lMaxAndComp(node->leftChild);
   } // end if
} // end removeRoot


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
Comparable* BST::lMaxAndComp(Node *&node) const
{
   if (node->rightChild == nullptr) {
      // Get this node's value
      Comparable *comp = node->item;
      Node *nodeToDelete = node;
      // Connect parent to leftChild
      node = node->leftChild;
      delete nodeToDelete;
      return comp;
   } else {
      return lMaxAndComp(node->rightChild);
   } // end if
} // end lMaxAndComp


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
int BST::lMaxAndInt(const Node *node) const
{
   if (node->rightChild == nullptr) {
      // Get this node's quantity
      int val = node->quantity;
      return val;
   } else {
      return lMaxAndInt(node->rightChild);
   } // end if
} // end lMaxAndInt


/**  -----------------------------------------------------------------
   retrieve
   -- Finds and returns a Comparable within BST if present
   @pre:        none.
   @post:       none.
   @param comp: the Comparable to be found
   @return:     a Comparable pointer */
const Comparable* BST::retrieve(const Comparable &comp) const
{
   Comparable* target = fetch(rootPtr, comp);
   return target;
} // end retrieve


/**  -----------------------------------------------------------------
   fetch
   -- Helper method for retrieve, responsible for finding the target 
      Comparable in BST.
   @pre:        none. 
   @post:       none.
   @param node: the root node of BST
   @param comp: the Comparable to find
   @return:     a pointer to the Comparable or nullptr if not found */
Comparable* BST::fetch(Node *node, const Comparable &comp) const
{
   if (node == nullptr) {
      return nullptr;
   } else if (*node->item > comp) {
      return fetch(node->leftChild, comp);
   } else if (*node->item < comp) {
      return fetch(node->rightChild, comp);
   } else if (*node->item == comp) {
      Comparable* target = node->item;
      return target;
   } else {
      return nullptr;
   }
} // end fetch


/**  -----------------------------------------------------------------
   Output Stream operator
   -- Prints a table of Comparables with associated quantities 
   -- calls printInOrder
   @pre:        none. 
   @post:       BST data is sent to the Output Stream
   @param:      the Output Stream
   @param node: node of BST, starting at root node */
std::ostream& operator<<(std::ostream &out, BST& BT)
{
   BT.printInorder(out, BT.rootPtr);
   return out;
}

/**  -----------------------------------------------------------------
   printInorder
   -- Prints a table of Comparables with associated quantities 
      in BST using inorder
   @pre:        none. 
   @post:       the most-right node of the left subtree is removed and 
                its Comparable is copied.
   @param node: the target node to be removed
   @return:     a integer value, representing quantity */
void BST::printInorder(std::ostream& out, Node* node) const
{
   if (node != nullptr) {
      printInorder(out, node->leftChild);
      out << *node->item << node->quantity << std::endl;
      printInorder(out, node->rightChild);
   } // end if
} // end printInorder
