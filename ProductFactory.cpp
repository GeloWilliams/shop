/** @file Hasher.cpp
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

#include <iostream>
#include <vector>
#include "ProductFactory.h"


using namespace std;

/**  -----------------------------------------------------------------
   Constructor 
   @pre:  none.
   @post: a new Hasher object has been instantiated.  */
ProductFactory::ProductFactory()
{
   for (int i = 0; i < BUCKETS_; i++) {

   } // end for 
} // end Constructor

/**  -----------------------------------------------------------------
   hashFunction
   -- Generates an index integer for the caller
   @pre:       none
   @post:      An array index in hashTable_ is returned to the caller
   @param key: a char denoting the type of Product* the index slot is being reserved for.
   @return:    an integer for the slot in which Product* should be inserted into hashTable_. */
int ProductFactory::hashFunction(char key)
{
   // Product:
   if (key == 'P') {
      return 0;
   } else if (key == 'M') {
      return 3;
   } else if (key == 'C') {
      return 7;
   } else if (key == 'S') {
      return 10;
   }

   return -1;
} // end hashFunction


/**  -----------------------------------------------------------------
   insertItem
   -- Calls hashFunction and uses returned index to store a Product* object in hashTable_.
   @pre:        hashTable_ contains at least one non-conflicting slot
   @post:       a new HashNode object is stored in hashTable_
   @param key:  returned index from hashFunction
   @param item: a Product* object
   @return:     true if insertion is succesful, false otherwise. */
void ProductFactory::insertItem(char key, Comparable *&item)
{
   int hashValue = hashFunction(key);
   hashTable_[hashValue].insert(item);
} // end insertItem


/**  -----------------------------------------------------------------
   create
   -- Calls hashFunction and uses returned index to store a Product* object in hashTable_.
   -- Used for callers to create a dynamically allocated Hasahble
   @pre:               hashTable_ contains at least one non-conflicting slot
   @post:              a new HashNode object is stored in hashTable_
   @param key:         the correlating key for a specific Product
   @param description: the full description of the Product
   @return:            a new Product* with attributes written */
Comparable* ProductFactory::create(char key, string description)
{
   if (key == 'P') {
      Product p;
      Comparable* pp = p.build(description);
      insertItem(key, pp);
      return pp;
   } else if (key == 'M') {
      Coin m;
      Comparable* mp = m.build(description);
      insertItem(key, mp);
      return mp;
   } else if (key == 'C') {
      Comic c;
      Comparable* cp = c.build(description);
      insertItem(key, cp);
      return cp;
   } else if (key == 'S') {
      SportsCard s;
      Comparable* sp = s.build(description);
      insertItem(key, sp);
      return sp;
   }
   return nullptr;
} // end create


/** TEST */
void ProductFactory::print()
{
   for (int i = 0; i < BUCKETS_; i++) {
         cout << hashTable_[i] << endl;
   }
}