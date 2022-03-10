/** @file Buy.h
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
#include <vector>
#include "Transaction.h"

using namespace std;

class ProductFactory;
class CustomerHouse;

class Buy : public Transaction {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new Transaction object has been instantiated. */
      Buy() {}

      /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      ~Buy() = default;

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
      virtual void buy(string subDescription, ProductFactory &pf, CustomerHouse &ch)
      {
         string delimiter = ", ";
         
         // parse Customer id
         string cs = subDescription.substr(0, subDescription.find(delimiter));
         int cId = stoi(cs);
         // erase substring
         subDescription.erase(0, (subDescription.find(delimiter) + delimiter.length()));

         // increase quantity
         Comparable* c = pf.get(subDescription);
         if (c != nullptr) {
            c->increase();

            // customer sell
            ch.cSell(cId, c);
         } // end if

      } // end buy
};
