/** @file SportsCard.cpp
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
#include "SportsCard.h"
using namespace std;

/**  -----------------------------------------------------------------
   Less Than Operator 
   @pre:    none.
   @post:   returns true if *this is less than rhs
   @param:  SportsCard on the righthand side of the equation 
   @return: true if *this is less than rhs, false otherwise */
bool SportsCard::operator<(const Comparable &rhs) const
{
   // Cast as SportsCard to override Comparable operator<:
   const SportsCard &s = static_cast<const SportsCard &>(rhs);

   // sorted by player, year, manufacturer, grade
   if (player_ < s.player_) {
      return true;
   } else if (player_ == s.player_) {
      if (year_ < s.year_) {
         return true;
      } else if (year_ == s.year_) {
         if (manufacturer_ < s.manufacturer_) {
            return true;
         } else if (manufacturer_ == s.manufacturer_) {
            if (grade_ < s.grade_) {
               return true;
            } // end if
         } // end if
      }// end if
   } // end if
   return false;
} // end operator<

/**  -----------------------------------------------------------------
   Equal To Operator 
   @pre:       none.
   @post:      returns true if *this is equal to rhs
   @param rhs: SportsCard on the righthand side of the equation 
   @return:    true if *this is equal to rhs, false otherwise */
bool SportsCard::operator==(const Comparable &rhs) const
{
   // Cast as SportsCard to override Comparable operator==:
   const SportsCard &s = static_cast<const SportsCard &>(rhs);

   if (player_ == s.player_ && year_ == s.year_ 
      && manufacturer_ == s.manufacturer_ && grade_ == s.grade_)
      return true;
   else 
      return false;
} // end operator==


/**  -----------------------------------------------------------------
   build
   -- Creates a new SportsCard*
   -- Receives a description for the SportsCard that is parsed for attributes
   @pre:    *this has been instantiated
   @post:   a new SportsCard* with attributes written is returned to the caller
   @param key:         the Product key code
   @param description: the Product description
   @return: a new dynamically allocated SportsCard* */ 
SportsCard* SportsCard::build(char key, string description)
{
   SportsCard* sc = new SportsCard();
   string s = description;
   string delimiter = ", ";

   // parse year
   string yr = s.substr(0, s.find(delimiter));
   // erase substring
   s.erase(0, (s.find(delimiter) + delimiter.length()));

   // parse grade
   string gd = s.substr(0, s.find(delimiter));
   // erase substring
   s.erase(0, (s.find(delimiter) + delimiter.length()));

   // parse title
   string pl = s.substr(0, s.find(delimiter));
   // erase substring
   s.erase(0, (s.find(delimiter) + delimiter.length()));
   
   // parse manufacturer
   string mn = s.substr(0, s.find(delimiter));

   sc->key_ = key;
   sc->year_ = yr;
   sc->grade_ = gd;
   sc->player_ = pl;
   sc->manufacturer_ = mn;

   return sc;
} // end build

/**  -----------------------------------------------------------------
   getItem
   -- a string containing the SportsCard description is returned. Each detail is separated by a 
      comma allowing the entire SportsCard description to be presented on one line
   @pre:    each data member in *this must contain an initialized value
   @post:   a string containing the values for each data member is returned to the caller 
   @return: a full SportsCard description in string format */
string SportsCard::getItem() const
{
   string k(1, key_);
   string toReturn = "(" + to_string(quantity_) + ") " + "Sports Card : " + year_ + ", " 
   + grade_ + ", " + player_ + ", " + manufacturer_ ;
   return toReturn;
} // end getItem

