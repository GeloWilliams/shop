/** @file CustomerHouse.cpp
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

   Key Variables: quickLookup_ holds all product object pointers. The Customer and Inventory objects may point to objects
   in quickLookup_, however, only either the Customer or Inventory will never point to the same item simultaneously.

   Exceptions: Any incorrect formatting within a file that contains some correct formatting will be ignored. 
   If all entries are incorrectly formatted, an error message will be printed to the user. */

#include <iostream>
#include <string>
#include "CustomerHouse.h"
using namespace std;

/**  -----------------------------------------------------------------
   Constructor 
   @pre:  none.
   @post: a new CustomerHouse object has been instantiated.  */
CustomerHouse::CustomerHouse()
{
   for (int i = 0; i < CLIST_; i++) {
      quickLookup_[i] = nullptr;
   }
} // end Constructor

/**  -----------------------------------------------------------------
   create
   -- Calls insertItem to store a Product* object in quickLookup_
   -- Used for callers to create a dynamically allocated Comparable
   @pre:               quickLookup_ contains at least one non-conflicting slot
   @post:              a Comparable is stored in quickLookup_
   @param description: the full description of the Customer
   @return:            a new Customer* with attributes written */
Comparable* CustomerHouse::create(string description)
{
   string id = description.substr(0, description.find(", "));
   int idInt = stoi(id);

   Customer c;
   Customer* x = c.build(description);
   addCustomer(idInt, x);
   return x;
} // end create

/**  -----------------------------------------------------------------
   hashFunction
   -- Generates an index integer for the caller
   @pre:       none
   @post:      An array index in quickLookup_ is returned to the caller
   @param id:  an int representing Customer* id
   @param i:   the current iteration after a collision
   @return:    an integer for the slot in which Customer* should be inserted into quickLookup_. */
int CustomerHouse::hashFunction(int id, int i)
{
   int idx = (id + i * (7 - (id % 7)) ) % CLIST_;
   return idx;
} // end hashFunction

/**  -----------------------------------------------------------------
   addCustomer
   -- Calls hashFunction and uses returned index to store a Customer* object in quickLookup_.
   @pre:        quickLookup_ contains at least one non-conflicting slot
   @post:       a Comparable is stored in quickLookup_
   @param id:   an int representing Customer* id
   @param cstm: a Customer* object */
void CustomerHouse::addCustomer(int id, Customer *&cstm)
{
   for (int i = 0; i < CLIST_; i++) {
      int hashValue = hashFunction(id, i);
      if (quickLookup_[hashValue] == nullptr) {
         quickLookup_[hashValue] = cstm; // add to quickLookup_
         sortedList_.insert(quickLookup_[hashValue]); // add to sortedList_
         break;
      } // end if
   } // end for
} // end addCustomer

/**  -----------------------------------------------------------------
   remove
   -- Calls hashFunction and uses the returned index to 
      remove a Customer* object in hashTable_
   @pre:      none
   @post:     a Comparable is removed from hashTable_
   @param id: the Customer's unique id  */
void CustomerHouse::remove(int id)
{
   for (int i = 0; i < CLIST_; i++) {
      int hashValue = hashFunction(id, i);
      if (quickLookup_[hashValue] != nullptr) {
         string s = quickLookup_[hashValue]->getItem();
         string i = s.substr(0, s.find(", "));
         int idInt = stoi(i);
         if (idInt == id) {
            // remove from sortedList_
            sortedList_.remove(*(quickLookup_[hashValue]));
            // remove from quickLookup_
            quickLookup_[hashValue] = nullptr;
         } // end if
      } // end if
   } // end for
} // end remove

/**  -----------------------------------------------------------------
   get
   -- Retrieves a Customer* 
   @pre:       id should be valid to avoid returning nullptr
   @post:      a Customer* is returned to the caller
   @param id:  the Customer's unique id
   @return:    a Customer* with the id given */
Customer* CustomerHouse::get(int id)
{
   for (int i = 0; i < CLIST_; i++) {
      int hashValue = hashFunction(id, i);
      if (quickLookup_[hashValue] != nullptr) {
         string s = quickLookup_[hashValue]->getInfo();
         string i = s.substr(0, s.find(", "));
         int idInt = stoi(i);
         if (idInt == id) {
            return quickLookup_[hashValue];
         } // end if
      } // end if
   } // end for
   return nullptr;
} // end get


/**  -----------------------------------------------------------------
   getTransactions
   -- Prints all transactions for an individual Customer
   @pre:      none
   @post:     a list of Customer transactions is sent to the caller in
               string format
   @param id: the Customer's unique id
   @return:   a list of transactions for a single Customer in string format */
string CustomerHouse::getTransactions(int id)
{
   string s = "";
   Customer* c = get(id);
   if (c != nullptr)
      s = c->getItem();
   return s;
} // end get


/**  -----------------------------------------------------------------
   buy
   -- Adds a Product to or increases quantity of Product in 
      Customer object's purchases_ vector
   @pre:           the Product must be instantiated
   @post:          The Product quantity within Inventory is reduced 
                   by 1 while the Product is added or increased in
                   Customer object's purchases_ vector
   @param id:      Customer's unique id
   @param product: the Product in the transaction */
void CustomerHouse::cBuy(int id, Comparable* product)
{
   Customer* c = get(id);
   c->addS(product);
} // end cBuy

/**  -----------------------------------------------------------------
   sell
   -- Adds a Product to or increases quantity of Product in 
      Customer object's sales_ vector
   @pre:           the Product must be instantiated
   @post:          The Product quantity within Inventory is increased 
                   by 1 while the Product is added or increased in
                   Customer object's sales_ vector
   @param id:      Customer's unique id
   @param product: the Product in the transaction */
void CustomerHouse::cSell(int id, Comparable* product)
{
   Customer* c = get(id);
   c->addB(product);
} // end cSell

/**  -----------------------------------------------------------------
   Output Stream operator
   -- Prints all transactions for all Customers
   @pre:       none
   @post:      a list of Customer transactions is sent to the 
               Output Stream operator
   @param out: the output stream operator
   @param ch:  *this  */
ostream& operator<<(ostream &out, CustomerHouse& ch)
{
   cout << ch.sortedList_ << endl;
   return out;
} // end output stream operator