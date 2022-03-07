/** @file Customer.cpp
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
#include "Customer.h"
using namespace std;

/**  -----------------------------------------------------------------
   Less Than Operator 
   @pre:    none.
   @post:   returns true if *this is less than rhs
   @param:  Customer on the righthand side of the equation 
   @return: true if *this is less than rhs, false otherwise */
bool Customer::operator<(const Comparable &rhs) const
{
   // Cast as Customer to override Comparable operator<:
   const Customer &c = static_cast<const Customer &>(rhs);

   if (firstName_ < c.firstName_) {
      return true;
   } else if (firstName_ == c.firstName_) {
      if (id_ < c.id_) {
         return true;
      } // end if
   } // end if
   return false;
} // end operator<


/**  -----------------------------------------------------------------
   Equal To Operator 
   @pre:       none.
   @post:      returns true if *this is equal to rhs
   @param rhs: Customer on the righthand side of the equation 
   @return:    true if *this is equal to rhs, false otherwise */
bool Customer::operator==(const Comparable &rhs) const
{
   // Cast as Customer to override Comparable operator==:
   const Customer &c = static_cast<const Customer &>(rhs);

   if (firstName_ == c.firstName_ && lastName_ == c.lastName_
      && id_ == c.id_)
      return true;
   else 
      return false;
} // end operator==


/**  -----------------------------------------------------------------
   build
   -- Creates a new Customer*
   -- Receives a description for the Customer that is parsed for attributes
   @pre:    *this has been instantiated
   @post:   a new Customer* with attributes written is returned to the caller
   @return: a new dynamically allocated Customer* */ 
Customer* Customer::build(string description)
{
   Customer* nc = new Customer();
   string s = description;
   string delimiterA = ", ";
   string delimiterB = " ";
   
   //parse id
   string id = s.substr(0, s.find(delimiterA));
   int idInt = stoi(id);
   // erase substring
   s.erase(0, (s.find(delimiterA) + delimiterA.length()));

   // parse first name
   string fn = s.substr(0, s.find(delimiterB));
   // erase substring
   s.erase(0, (s.find(delimiterB) + delimiterB.length()));

   // parse last name
   string ln = s.substr(0, s.find(delimiterB));
   
   nc->id_ = idInt;
   nc->firstName_ = fn;
   if (ln != fn) {
      nc->lastName_ = ln;
   }

   return nc;

} // end build


/**  -----------------------------------------------------------------
   getItem
   -- a string containing the Customer description is returned. Each detail is separated by a 
      comma allowing the entire Customer description to be presented on one line
   @pre:    each data member in *this must contain an initialized value
   @post:   a string containing the values for each data member is returned to the caller 
   @return: a full Customer description in string format */
string Customer::getItem() const
{
   string toReturn = to_string(id_) + ", " + firstName_ + " " + lastName_;
   return toReturn;
} // end getItem

/**  -----------------------------------------------------------------
   addS
   -- adds a Product to transactions_, marking 'S' for a Store Sale during
      a Customer buy
   @pre:           none
   @post:          a string with the transaction type, Customer id, and
                     product description has been added to transactions_
   @param product: the Product included within the transaction */
void Customer::addS(Comparable* product)
{
   string storeSale = "S, " + to_string(id_) + ", ";

   // parse product information
   string delimiter = ", ";
   string prodString = product->getItem();
   // erase key substring
   prodString.erase(0, (prodString.find(delimiter) + delimiter.length()));
   // erase quantity substring
   prodString.erase(0, (prodString.find(delimiter) + delimiter.length()));

   storeSale += prodString;
   transactions_.push_back(storeSale);
} // end addP

/**  -----------------------------------------------------------------
   addB
   -- adds a Product to transactions_, marking 'B' for a Store Buy during
      a Customer sale
   @pre:           none
   @post:          a string with the transaction type, Customer id, and
                     product description has been added to transactions_
   @param product: the Product included within the transaction */
void Customer::addB(Comparable* product)
{
   string storeBuy = "B, " + to_string(id_) + ", ";

   // parse product information
   string delimiter = ", ";
   string prodString = product->getItem();
   // erase key substring
   prodString.erase(0, (prodString.find(delimiter) + delimiter.length()));
   // erase quantity substring
   prodString.erase(0, (prodString.find(delimiter) + delimiter.length()));

   storeBuy += prodString;
   transactions_.push_back(storeBuy);
} // end addS


/**  -----------------------------------------------------------------
   Output Stream operator
   -- Prints all transactions for this Customer line by line
   @pre:        none
   @post:       a list of transactions is sent to the Output Stream operator
   @param out:  the output stream operator
   @param cstm: *this  */
ostream& operator<<(ostream &out, const Customer& cstm)
{
   for (int i = 0; i < cstm.transactions_.size(); i++) {
      out <<  cstm.transactions_[i] << endl;
   } // end for
   return out;
} // end output stream operator