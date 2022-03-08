/** @file ProductFactory.h
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

   Key Variables: hashTable_ holds all product object pointers. The Customer and Inventory objects may point to objects
   in hashTable_, however, only either the Customer or Inventory will never point to the same item simultaneously.

   Exceptions: Any incorrect formatting within a file that contains some correct formatting will be ignored. 
   If all entries are incorrectly formatted, an error message will be printed to the user. */

#pragma once
#include <iostream>
#include "BST.h"
#include "Product.h"
#include "Coin.h"
#include "Comic.h"
#include "SportsCard.h"

using namespace std;


static const int BUCKETS_ = 11;

class BST; // forward declaration
class ProductFactory {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new ProductFactory object has been instantiated.  */
      ProductFactory(){}

      /**  -----------------------------------------------------------------
         create
         -- Calls hashFunction and uses the returned index
         -- Calls insertItem to store a Product* object in hashTable_
         -- Used for callers to create a dynamically allocated Comparable
         @pre:               hashTable_ contains at least one non-conflicting slot
         @post:              a Comparable is stored in hashTable_
         @param description: the full description of the Product
         @return:            a new Product* with attributes written */
      Comparable* create(string description);

      /**  -----------------------------------------------------------------
         remove
         -- Calls hashFunction and uses the returned index
         -- Calls deleteItem to remove a Product* object in hashTable_
         @pre:               hashTable_ contains at least one non-conflicting slot
         @post:              a Comparable is removed from hashTable_
         @param description: the full description of the Product
         @return:            a new Product* with attributes written */
      Comparable* remove(string description);

      /**  -----------------------------------------------------------------
         get
         -- Retrieves a Product* 
         @pre:               none
         @post:              a Product* is returned to the caller
         @param key:         the correlating key for a specific Product
         @param description: the full description of the Product
         @return:            a Product* matching the description given */
      Comparable* get(string description);

      /**  -----------------------------------------------------------------
         Output Stream operator
         -- Prints all Products with a quantity of at least 1
         @pre:       none
         @post:      a list of Products is sent to the Output Stream operator
         @param out: the output stream operator
         @param pf: *this  */
      friend ostream& operator<<(ostream &out, ProductFactory& pf);

   private:
       /**  -----------------------------------------------------------------
         hashFunction
         -- Generates an index integer for the caller
         @pre:       none
         @post:      An array index in hashTable_ is returned to the caller
         @param key: a char denoting the type of Product* the index slot is being reserved for.
         @return:    an integer for the slot in which Product* should be inserted into hashTable_. */
      int hashFunction(char key);

      /**  -----------------------------------------------------------------
         insertItem
         -- Calls hashFunction and uses returned index to store a Product* object in hashTable_.
         @pre:        hashTable_ contains at least one non-conflicting slot
         @post:       a new HashNode object is stored in hashTable_
         @param key:  returned index from hashFunction
         @param item: a Product* object
         @return:     true if insertion is succesful, false otherwise. */
      void insertItem(char key, Comparable *&item);

      /**  -----------------------------------------------------------------
         removeItem
         -- Calls hashFunction and uses returned index to remove a Product* object in hashTable_.
         @pre:        none
         @post:       item is removed from hashTable_
         @param key:  returned index from hashFunction
         @param item: the Product* object to remove
         @return:     the Product* that was removed */
      Comparable* removeItem(char key, Comparable *&item);

      /** array holding BSTs */
      BST hashTable_[BUCKETS_];
};
