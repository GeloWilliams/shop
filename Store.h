/** @file Store.h
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
#include "ProductFactory.h"

using namespace std;

class Store {
   public:
      /**  -----------------------------------------------------------------
         Constructor 
         @pre:  none.
         @post: a new store object has been instantiated and ready for a list of 
            commands from import file.  */
      Store();

      /**  -----------------------------------------------------------------
         Destructor
         @pre:  the Constructor has been called.
         @post: all data that was dynamically allocated has been removed and deallocated. */
      ~Store();

      /**  -----------------------------------------------------------------
         sell
         -- removes item from Inventory, adds item to Customer
         @pre:               Inventory object has at least one Product* object in its 
                             private vector member
         @post:              a new Product* pointer is pushed into the Customer object's 
                             storage member while being removed from the Inventory object's 
                             storage member
         @param transaction: command passed as a string in the form: 
                             S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck  */
      void sell(string transaction);

      /**  -----------------------------------------------------------------
         buy
         -- adds item to Inventory, removes item from Customer
         @pre:               none
         @post:              a new Product* pointer is pushed into the Inventory object's storage member 
                             while being removed from the Customer object's storage member  
         @param transaction: command passed as a string in the form: 
                             B, 456, M, 1913, 70, Liberty Nickel  */
      void buy(string transaction);

      /**  -----------------------------------------------------------------
         display
         -- the total number of items and all Product* objects currently in Inventory are sent to cout
         @pre:  none
         @post: the current data in Inventory is sent to cout to print  */
      void display() const;

      /**  -----------------------------------------------------------------
         customer
         -- Customer transactions for a single Customer, sent to cout
         @pre:      at least one Customer object has been instantiated
         @post:     all Customer data including Customer information and related transactions 
                    are sent to cout to print. The data is sorted chronologically by transaction.
         @param id: 3-digit integer unique to a specific Customer */
      void customer(int id) const;

    /**  -----------------------------------------------------------------
         history
         -- Customer transactions for all Customers, sent to cout
         @pre:  none
         @post: data for all Customers and related transactions are sent to cout to print. 
                The data is sorted chronologically by Customer' first name. */
      void history() const;

      /**  -----------------------------------------------------------------
         fillInventory
         -- reads contents of inventory input file
         -- requests ProductFactory to create Product objects
         -- adds items to Inventory (without Customer interaction)
         @pre:  none
         @post: Inventory and ProductFactory contain Product* objects */
      void fillInventory();

      /**  -----------------------------------------------------------------
         inviteCustomers
         -- reads contents of customer input file
         -- adds Customer objects to customerList_
         @pre:  none
         @post: customerList_ contains a list of Customer */
      void inviteCustomers();

      /**  -----------------------------------------------------------------
         doBusiness
         -- reads contents of transaction input file
         -- adds Customer objects to customerList_
         @pre:  both Inventory and Customer objects contain at least one Product each
         @post: Inventory and Customer objects contain pointers to Products
            in line with the commands given in the input file; some data may
            be sent to cout for printing */
      void doBusiness();

   private:
         class Inventory {
            public:
               /**  -----------------------------------------------------------------
                  Constructor 
                  @pre:  a Store object is instantiated
                  @post: a new Inventory object is instantiated, numItems is initialized to zero. */
               Inventory();

               /**  -----------------------------------------------------------------
                  Destructor
                  @pre:  the Constructor has been called.
                  @post: all data that was dynamically allocated has been removed and deallocated. */
                  ~Inventory();

               /**  -----------------------------------------------------------------
                  addItem
                  -- adds an item to products_
                  @pre:        none.
                  @post:       a new Product is dynamically allocated and stored in products_
                  @param item: the Product to be added */
               void addItem(Product* item);

               /**  -----------------------------------------------------------------
                  removeItem
                  -- removes an item from products_
                  @pre:        products_ contains at least one Product*.
                  @post:       a new Product is dynamically allocated and stored in products_
                  @param item: the Product to be removed */
               Product* removeItem(Product* item);

            private:
               /** the total number of items currently in Inventory */
               int numItems_;

               /** holds all Product* objects currently in Inventory */
               vector<Product*> products_;
         };
         
         class Customer {
            public:
               /**  -----------------------------------------------------------------
                  Constructor 
                  @pre:  a Store object is instantiated.
                  @post: a new Customer object is instantiated. ID_, firstName_, and 
                     lastName_ (if applicable) are initialized to the parameters passed.
                  @param id: a 3-digit number unique to each Customer
                  @param fName: Customer's first name (no empty strings allowed)
                  @param lName: Customer's last name (empty strings allowed) */
               Customer(int id, string fName, string lName);

               /**  -----------------------------------------------------------------
                  Destructor
                  @pre:  the Constructor has been called.
                  @post: all data that was dynamically allocated has been removed and deallocated. */
               ~Customer();

              /**  -----------------------------------------------------------------
                  getInfo
                  -- ID_, firstName_, and lastName_ are presented as a string and returned to the caller
                  @pre:  none
                  @post: a string containing ID_, firstName_, and lastName_ are presented on one line 
                     (ID_ is separated by a comma). The string is returned to the caller. */
               string getInfo() const;

               /**  -----------------------------------------------------------------
                  getBag
                  -- All Product objects received during buy transactions (excluding those sold) is 
                     presented as a string and returned to the caller
                  @pre:  none, if empty, an empty string will be returned
                  @post: a string containing all Product objects currently held by *this (Customer) is
                     returned to the caller. Each Product is presented on a separate line. */
               string getBag() const;

               /**  -----------------------------------------------------------------
                  addItem
                  -- adds an item to bag_
                  @pre:        none.
                  @post:       a new Product is dynamically allocated and stored in products_
                  @param item: the Product to be added */
               void addItem(Product* item);

               /**  -----------------------------------------------------------------
                  removeItem
                  -- removes and item from bag_
                  @pre:        bag_ contains at least one Product*.
                  @post:       a new Product is dynamically allocated and stored in products_
                  @param item: the Product to be removed */
               Product* removeItem(Product* item);
            
            private:
               /** a 3-digit integer that is unique to this Customer */
               int id_;

               /** Customer first name */
               string firstName_;

               /** Customer last name */
               int lastName_;

               /** holds all Product* objects currently for Customer */
               vector<Product*> bag_;
         };
         /** vector holding all of the Customers read from input file */
         vector<Customer*> customerList_;
};