/** @file ActionStation.h
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
#include "ProductFactory.h"
#include "CustomerHouse.h"
#include "Transaction.h"
#include "Buy.h"
#include "Sell.h"
#include "CustTransaction.h"
#include "Display.h"
#include "History.h"

using namespace std;

static const int ACTIONS_ = 11;

class ActionStation {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new ActionStation object has been instantiated. */
      ActionStation();

      /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      ~ActionStation();

         /**  -----------------------------------------------------------------
         transact
         -- Parses a key from transaction description (command), passes the remaining
            substring in a call to use or calls view if 
         @pre:               actionTable_ has at least one derived Transaction class
                             instantiated
         @post:              a derived Transaction object calls an overridden method
         @param description: a full transaction description
         @param pf           a ProductFactory object
         @param ch           a CustomerHouse object */
      void transact(string description, ProductFactory &pf, CustomerHouse &ch);

   private:

      /**  -----------------------------------------------------------------
         use
         -- Helper method for transact
         -- Calls a specific method contingent on a key triggering its 
            overridden version within one of the derived classes
         @pre:                  actionTable_ has at least one derived Transaction class
                                instantiated
         @post:                 a derived Transaction object calls an overridden method
         @param key:            identifier associated with a specific derived Transaction
         @param subDescription: substring of transaction descripton without key
         @param pf           a ProductFactory object
         @param ch           a CustomerHouse object  */
      void use(char key, string subDescription, ProductFactory &pf, CustomerHouse &ch);

      /**  -----------------------------------------------------------------
         viewInv
         -- Helper method for transact
         -- Calls a specific method contingent on a key triggering its 
            overridden version within one of the derived classes
         @pre:        actionTable_ has at least one derived Transaction class
                      instantiated
         @post:       a derived Transaction object calls an overridden method
         @param pf    a ProductFactory object */
      void viewInv(ProductFactory &pf);

      /**  -----------------------------------------------------------------
         viewCus
         -- Helper method for transact
         -- Calls a specific method contingent on a key triggering its 
            overridden version within one of the derived classes
         @pre:        actionTable_ has at least one derived Transaction class
                      instantiated
         @post:       a derived Transaction object calls an overridden method
         @param ch    a CustomerHouse object  */
      void viewCus(CustomerHouse &ch);

      /** array holding BSTs */
      Transaction* actionTable_[ACTIONS_];
};