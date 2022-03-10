/** @file Transaction.h
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
using namespace std;

class Transaction {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new Transaction object has been instantiated. */
      Transaction() {}

      /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      virtual ~Transaction(){}

      /**  -----------------------------------------------------------------
         sell
         -- a string containing the Transaction description is read and parsed. The details
            of the transaction will generate an interaction between ProductFactory 
            and CustomerHouse
         -- a Product is bought by a Customer and sold by Store
         @pre:                  ProductFactory and CustomerHouse are instantiated, 
                                containing at least one Product and one Customer respectively
         @post:                 ProductFactory decrements the quantity of Product by 1, 
                                CustomerHouse adds a transaction to a Customer object's 
                                transactions_ vector
         @param subDescription: substring of transaction descripton without key
         @param pf              a ProductFactory object
         @param ch              a CustomerHouse object  */
      virtual void sell(string subDescription, ProductFactory &pf, CustomerHouse &ch) {}

      /**  -----------------------------------------------------------------
         buy
         -- a string containing the Transaction description is read and parsed. The details
            of the transaction will generate an interaction between ProductFactory and 
            CustomerHouse
         -- a Product is sold by a Customer and bought by Store
         @pre:                  ProductFactory and CustomerHouse are instantiated, 
                                containing at least one Product and one Customer respectively
         @post:                 ProductFactory increments the quantity of Product by 1, 
                                CustomerHouse adds a transaction to a Customer object's 
                                transactions_ vector 
         @param subDescription: substring of transaction descripton without key
         @param pf              a ProductFactory object
         @param ch              a CustomerHouse object  */
      virtual void buy(string subDescription, ProductFactory &pf, CustomerHouse &ch) {}

      /**  -----------------------------------------------------------------
         display
         -- Commands ProductFactory to print the contents of its inventory, 
         skipping any items with a quantity of 0
         @pre:  none
         @post: the contents of the ProductFactory inventory is sent to the output
                stream operator, accounting for any transactional changes
         @param pf              a ProductFactory object */
      virtual void display(ProductFactory &pf) {}

      /**  -----------------------------------------------------------------
         customer
         -- Commands CustomerHouse to call the Customer matching the id passed 
            to call the Customer to print out all transactions in chronological order
         @pre:      none
         @post:     all transactions of a single Customer is sent to the output stream
                    operator 
         @param id: the id of the Customer with transactions listed 
         @param ch           a CustomerHouse object*/
      virtual void customer(int id, CustomerHouse &ch) {}

      /**  -----------------------------------------------------------------
         history
         -- Commands CustomerHouse to print all transactions by every Customer,
            listed in alphabetical order by first name
         @pre:      none
         @post:     transactions all Customer objects are sent to the output stream operator
         @param ch: a CustomerHouse object   */
      virtual void history(CustomerHouse &ch) const {}
};