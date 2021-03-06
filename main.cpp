/** @file main.cpp
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

#include <fstream>
#include <iostream>
#include "Store.h"

using namespace std;

int main() 
{
   Store stor;
   
   // get inventory
   string inventoryFile = "hw4inventory.txt";
   string customerFile = "hw4customers.txt";
   string commandsFile = "hw4commands.txt";
   ifstream invInput(inventoryFile);
   ifstream cusInput(customerFile);
   ifstream comInput(commandsFile);

   // stock inventory
   while(invInput.peek() != EOF) {
      string fileInput;
      getline(invInput,fileInput);
      stor.stockInventory(fileInput);
   } // end while

   // invite customers
   while(cusInput.peek() != EOF) {
      string fileInput;
      getline(cusInput,fileInput);
      stor.inviteCustomers(fileInput);
   } // end while


   // transact
   while(comInput.peek() != EOF) {
      string fileInput;
      getline(comInput,fileInput);
      stor.doBusiness(fileInput);
   } // end while
   
   cout << endl; 
} // end main
