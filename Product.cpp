/** @file Product.cpp
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
#include "Product.h"
using namespace std;

/**  -----------------------------------------------------------------
   Less Than Operator 
   @pre:    none.
   @post:   returns true if *this is less than rhs
   @param:  Product on the righthand side of the equation 
   @return: true if *this is less than rhs, false otherwise */
bool Product::operator<(const Product &rhs) const
{
   if (name_ < rhs.name_) {
      return true;
   } else if (name_ == rhs.name_) {
      if (year_ < rhs.year_) {
         return true;
      } // end if
   } // end if
   return false;
} // end operator<

/**  -----------------------------------------------------------------
   Equal To Operator 
   @pre:       none.
   @post:      returns true if *this is equal to rhs
   @param rhs: Product on the righthand side of the equation 
   @return:    true if *this is equal to rhs, false otherwise */
bool Product::operator==(const Product &rhs) const
{
   if (name_ == rhs.name_ && year_ == rhs.year_)
      return true;
   else 
      return false;
} // end operator==


/**  -----------------------------------------------------------------
   build
   -- Creates a new Product*
   -- Receives a description for the Product that is parsed for attributes
   @pre:    *this has been instantiated
   @post:   a new Product* with attributes written is returned to the caller
   @return: a new dynamically allocated Product* */ 
Product* Product::build(string description)
{
   Product* np = new Product();
   string s = description;
   string delimiter = ", ";

   // parse year
   string yr = s.substr(0, s.find(delimiter));
   int yrInt = stoi(yr);
   // erase substring
   s.erase(0, (s.find(delimiter) + delimiter.length()));
   
   // parse name
   string nm = s.substr(0, s.find(delimiter));
   
   np->year_ = yrInt;
   np->name_ = nm;
   return np;
} // end build

/**  -----------------------------------------------------------------
   getItem
   -- a string containing the Product description is returned. Each detail is separated by a 
      comma allowing the entire Product description to be presented on one line
   @pre:    each data member in *this must contain an initialized value
   @post:   a string containing the values for each data member is returned to the caller 
   @return: a full Product description in string format */
string Product::getItem() const
{
   string toReturn = to_string(year_) + ", " + name_;
   return toReturn;
} // end getItem

