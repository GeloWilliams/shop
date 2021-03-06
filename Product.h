/** @file Product.h
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
#include "Comparable.h"

using namespace std;

class Product : public Comparable {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new Product object has been instantiated. */
      Product() : name_(""), year_("") {}

      /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      virtual ~Product() {}

      /**  -----------------------------------------------------------------
         Less Than Operator 
         @pre:       none.
         @post:      returns true if *this is less than rhs
         @param rhs: Product on the righthand side of the equation 
         @return:    true if *this is less than rhs, false otherwise */
      virtual bool operator<(const Comparable &rhs) const;

      /**  -----------------------------------------------------------------
         Equal To Operator 
         @pre:       none.
         @post:      returns true if *this is equal to rhs
         @param rhs: Product on the righthand side of the equation 
         @return:    true if *this is equal to rhs, false otherwise */
      virtual bool operator==(const Comparable &rhs) const;

      /**  -----------------------------------------------------------------
         build
         -- Creates a new Product*
         -- Receives a description for the Product that is parsed for attributes
         @pre:               *this has been instantiated
         @post:              a new Product* with attributes written is returned 
                              to the caller
         @param key:         the Product key code
         @param description: the Product description
         @return:            a new dynamically allocated Product */ 
      virtual Product* build(char key, string description);

      /**  -----------------------------------------------------------------
         getItem
         -- a string containing the Product description is returned. Each detail is separated by a 
            comma allowing the entire Product description to be presented on one line
         @pre:    each data member in *this must contain an initialized value
         @post:   a string containing the values for each data member is returned to the caller 
         @return: a full Product description in string format */
      virtual string getItem() const;

      /**  -----------------------------------------------------------------
         isEmpty
         -- returns quantity_
         @pre:    none
         @post:   none
         @return: true if quantity_ is empty, false otherwise */
      virtual bool isEmpty();

      /**  -----------------------------------------------------------------
         reduce
         -- decreases the quantity of a Comparable by 1 if quantity >= 1
         @pre:    quantity_ in *this must contain an initialized value
         @post:   quantity_ has been decreased by 1 if >= 1 */
      virtual void reduce();

      /**  -----------------------------------------------------------------
         increase
         -- increases the quantity of a Comparable by 1
         @pre:    quantity_ in *this must contain an initialized value
         @post:   quantity_ has been increase by 1 */
      virtual void increase();

   protected:
      /** The name of *this product */
      string name_;
      
      /** The year in which *this was released */
      string year_;   
      
};

