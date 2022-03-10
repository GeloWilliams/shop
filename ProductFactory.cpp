/** @file ProductFactory.cpp
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
#include <string>
#include "ProductFactory.h"
using namespace std;


/**  -----------------------------------------------------------------
   create
   -- Calls hashFunction and uses the returned index
   -- Calls insertItem to store a Product* object in hashTable_
   -- Used for callers to create a dynamically allocated Comparable
   @pre:               hashTable_ contains at least one non-conflicting slot
   @post:              a Comparable is stored in hashTable_
   @param key:         the Product key code
   @param quantity:    the Product quantity
   @param description: the Product description
   @return:            a new Product* with attributes written */
Comparable* ProductFactory::create(char key, int quantity, string description)
{
   if (key == 'P') {
      Product p;
      Comparable* pp = p.build(key, description);
      pp->quantity_ = quantity;
      insertItem(key, pp);
      return pp;
   } else if (key == 'M') {
      Coin m;
      Comparable* mp = m.build(key, description);
      mp->quantity_ = quantity;
      insertItem(key, mp);
      return mp;
   } else if (key == 'C') {
      Comic c;
      Comparable* cp = c.build(key, description);
      cp->quantity_ = quantity;
      insertItem(key, cp);
      return cp;
   } else if (key == 'S') {
      SportsCard s;
      Comparable* sp = s.build(key, description);
      sp->quantity_ = quantity;
      insertItem(key, sp);
      return sp;
   }
   return nullptr;
} // end create


/**  -----------------------------------------------------------------
   hashFunction
   -- Generates an index integer for the caller
   @pre:       none
   @post:      An array index in hashTable_ is returned to the caller
   @param key: a char denoting the type of Product* the index slot is being reserved for.
   @return:    an integer for the slot in which Product* should be inserted into hashTable_. */
int ProductFactory::hashFunction(char key)
{
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
   remove
   -- Calls hashFunction and uses the returned index
   -- Calls deleteItem to remove a Product* object in hashTable_
   @pre:               hashTable_ contains at least one non-conflicting slot
   @post:              a Comparable is removed from hashTable_
   @param description: the full description of the Product
   @return:            a new Product* with attributes written */
Comparable* ProductFactory::remove(string description)
{
   char key = description[0];
   if (key == 'P') {
      Product p;
      Comparable* pp = p.build(key, description);
      removeItem(key, pp);
      return pp;
   } else if (key == 'M') {
      Coin m;
      Comparable* mp = m.build(key, description);
      removeItem(key, mp);
      return mp;
   } else if (key == 'C') {
      Comic c;
      Comparable* cp = c.build(key, description);
      removeItem(key, cp);
      return cp;
   } else if (key == 'S') {
      SportsCard s;
      Comparable* sp = s.build(key, description);
      removeItem(key, sp);
      return sp;
   }
   return nullptr;   
} // remove


/**  -----------------------------------------------------------------
   removeItem
   -- Calls hashFunction and uses returned index to remove a Product* object in hashTable_.
   @pre:        none
   @post:       item is removed from hashTable_
   @param key:  returned index from hashFunction
   @param item: the Product* object to remove
   @return:     the Product* that was removed */
Comparable* ProductFactory::removeItem(char key, Comparable *&item)
{
   int hashValue = hashFunction(key);
   Comparable* toReturn = get(item->getItem());
   hashTable_[hashValue].remove(*item);
   return toReturn;
} // end removeItem

/**  -----------------------------------------------------------------
   get
   -- Retrieves a Product* 
   @pre:               none
   @post:              a Product* is returned to the caller
   @param key:         the correlating key for a specific Product
   @param description: the full description of the Product
   @return:            a Product* matching the description given */
Comparable* ProductFactory::get(string description)
{
   string delimiter = ", ";
   string s = description;


   //parse key
   string ke = s.substr(0, s.find(delimiter));
   char key = s[0];
   // erase substring
   s.erase(0, (s.find(delimiter) + delimiter.length()));
  
   int hashValue = hashFunction(key);

   if (key == 'P') {
      Product p;
      Comparable* pp = p.build(key, s);
      Comparable* toReturn = hashTable_[hashValue].retrieve(*pp);
      delete pp;
      return toReturn;
   } else if (key == 'M') {
      Coin m;
      Comparable* mp = m.build(key, s);
      Comparable* toReturn = hashTable_[hashValue].retrieve(*mp);
      delete mp;
      return toReturn;
   } else if (key == 'C') {
      Comic c;
      Comparable* cp = c.build(key, s);
      Comparable* toReturn = hashTable_[hashValue].retrieve(*cp);
      delete cp;
      return toReturn;
   } else if (key == 'S') {
      SportsCard sp;
      Comparable* spo = sp.build(key, s);
      Comparable* toReturn = hashTable_[hashValue].retrieve(*spo);
      delete spo;
      return toReturn;
   }
   return nullptr;
} // end get

/**  -----------------------------------------------------------------
   Output Stream operator
   -- Prints all Products with a quantity of at least 1
   @pre:       none
   @post:      a list of Products is sent to the Output Stream operator
   @param out: the output stream operator
   @param pf: *this  */
ostream& operator<<(ostream &out, ProductFactory& pf)
{
   for (int i = 0; i < BUCKETS_; i++) {
      out << pf.hashTable_[i];
   } // end for
   return out;
} // end output stream operator