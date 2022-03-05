/** @file Coin.h
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

   There are three types of Coins that the store contains:

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
#include <vector>
#include "Product.h"

using namespace std;

class Comparable;
class Coin : public Product {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new Coin object has been instantiated.  */
      Coin() : type_(""), grade_(0) {}

 /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      virtual ~Coin() {}

      /**  -----------------------------------------------------------------
         Less Than Operator 
         @pre:       none.
         @post:      returns true if *this is less than rhs
         @param rhs: Coin on the righthand side of the equation 
         @return:    true if *this is less than rhs, false otherwise */
      virtual bool operator<(const Comparable &rhs) const;

      /**  -----------------------------------------------------------------
         Equal To Operator 
         @pre:       none.
         @post:      returns true if *this is equal to rhs
         @param rhs: Coin on the righthand side of the equation 
         @return:    true if *this is equal to rhs, false otherwise */
      virtual bool operator==(const Comparable &rhs) const;

      /**  -----------------------------------------------------------------
         build
         -- Creates a new Coin*
         -- Receives a description for the Coin that is parsed for attributes
         @pre:    *this has been instantiated
         @post:   a new Coin* with attributes written is returned to the caller
         @return: a new dynamically allocated Coin* */ 
      virtual Coin* build(string description);

      /**  -----------------------------------------------------------------
         getItem
         -- a string containing the Coin description is returned. Each detail is separated by a 
            comma allowing the entire Coin description to be presented on one line
         @pre:    each data member in *this must contain an initialized value
         @post:   a string containing the values for each data member is returned to the caller 
         @return: a full Coin description in string format */
      virtual string getItem() const;

   protected:
      /** The name or description of *this */
      string type_;
      
      /** A measure of quality within its Coin category */
      int grade_;   
};