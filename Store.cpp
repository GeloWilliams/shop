/** @file Store.cpp
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
#include "Store.h"

/**  -----------------------------------------------------------------
   stockInventory
   -- reads contents of inventory input file
   -- requests inventory_ to create Product objects
   -- adds Product objects to inventory_
   @pre:           none
   @post:          if Product description is valid, a Product object 
                   has been added to inventory_ 
   @param product: a description of the Product in string format */
   void Store::stockInventory(string product)
   {
         string delimiter = ", ";
         string s = product;

         //parse key
         string ke = s.substr(0, s.find(delimiter));
         char keCh = s[0];
         // erase substring
         s.erase(0, (s.find(delimiter) + delimiter.length()));

         // parse quantity
         string qt = s.substr(0, s.find(delimiter));
         int qtInt = stoi(qt);
         // erase substring
         s.erase(0, (s.find(delimiter) + delimiter.length()));

         inventory_.create(keCh, qtInt, s);
   } // end stockInventory

/**  -----------------------------------------------------------------
   inviteCustomers
   -- reads contents of customer input file
   -- adds Customer objects to customerList_
   @pre:            none
   @post:           if Customer description is valid, a Customer object
                    has been added to customerList_ 
   @param customer: a description of the Customer in string format */
   void Store::inviteCustomers(string customer)
   {
      customerList_.create(customer);
   } // end inviteCustomers

/**  -----------------------------------------------------------------
   doBusiness
   -- reads contents of transaction input file
   -- generates an interaction between inventory_ and customerList_ or 
      prints data to output
   @pre:               inventory_ has at least one Product, customerList_ 
                       has at least one Customer 
   @post:              An interaction between inventory_ and customerList_ 
                       has taken place
                       or Store information has been sent to output
   @param transaction: a description of the Transaction in string format */
   void Store::doBusiness(string transaction)
   {
      commands_.transact(transaction, inventory_, customerList_);
   } // end doBusiness