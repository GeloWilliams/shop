
/**
   g++ -g -std=c++11 -o main main.cpp ProductFactory.cpp Product.cpp Coin.cpp Comic.cpp SportsCard.cpp BST.cpp Comparable.cpp
   cd Desktop/Main/Study/CSS502/Programs/Program4Test
*/  

#include <iostream>
#include <sstream>
#include <vector>
#include "ProductFactory.h"
#include "BST.h"
#include "Comparable.h"

using namespace std;

// 1. Original Process:

   // Product* p = new Product();
   // ProductFactory pf;

   // pf.insertItem('P', p->clone("testing"));
   // Product* h = pf.pfTable_[0]->item_->clone("testing again");
   // Product* r = pf.pfTable_[0]->item_->clone("another round");
   
   // cout << h << endl;
   // cout << r << endl;

// 2. Reduced to:
   // ProductFactory pf;
   // Product* h = pf.create('P',"testing");
   // cout << h->getItem() << endl;


void test1()
{
   ProductFactory pf;

   for (int i = 0; i < 3; i++) {
      string userString;
      cout << "Enter a word: ";

      char userInput;
      cout << "Enter a char: ";
      cin >> userInput;
      int idx = pf.hashFunction(userInput);
   }
   cout << endl;
   cout << "Your words: " << endl;
   pf.print();
   cout << endl;
}

void test2()
{
   string userString;
   cout << "Enter a word: ";
   cin >> userString;

}

void test3()
{

   ProductFactory pf;
   Product* h = pf.create('P',"1998, testing");
   Product* o = pf.create('P',"2020, messing");
   Product* q = pf.create('P',"1963, dressing");
   Product* r = pf.create('P',"2076, feasting");
   Product* v = pf.create('P',"1999, cresting");
   Product* c = pf.create('M', "2001, 65, Lincoln Cent");
   Product* d = pf.create('M', "2015, 70, Abraham Nickel");
   Product* m = pf.create('C', "2000, Excellent, Lord of the Rings, Tolken");
   Product* n = pf.create('C', "1992, Decent, Sonic the Hedgehog, BestCorp");
   Product* t = pf.create('C', "1979, Good, Garfield, TheBest Place");
   Product* w = pf.create('S', "2002, Near Mint, Ryu the Great, Upper Deck");
   Product* s = pf.create('S', "2003, Very Good, Ken the Master, Topps"); 

   pf.print();

   // Product* a = new Product();
   // Product* b = new Product();
   
   // Product* c = a->build("2008, a");
   // Product* d = b->build("2008, a");

   // if (*c < *d) {
   //    cout << "c is less than d" << endl;
   // } else if (*c == *d) {
   //    cout << "c is equal to d" << endl;
   // } else {
   //    cout << "d is less than c" << endl;
   // }

   // cout << c->getItem() << endl;
   // cout << d->getItem() << endl;
   // cout << endl;


   // if (*a < *b) {
   //    cout << "a is less than b" << endl;
   // } else if (*a == *b) {
   //    cout << "a is equal to b" << endl;
   // } else {
   //    cout << "b is less than a" << endl;
   // }


}


void test4()
{
  std::stringstream ssa("b"); // comp
  std::stringstream ssb("a"); // fly
  std::stringstream ssc("c"); // door
  std::stringstream ssd("f"); // water

  std::stringstream sse("z"); // tv
  std::stringstream ssf("a"); // air
  std::stringstream ssg("i"); // clean
  std::stringstream ssh("t"); // free
  
  std::stringstream ssi("i"); // bed
  std::stringstream ssj("p"); // snow
  std::stringstream ssk("i"); // hat

  Comparable* comp = new Comparable;
  Comparable* fly = new Comparable;
  Comparable* door = new Comparable;
  Comparable* water = new Comparable;
  Comparable* tv = new Comparable;
  Comparable* air = new Comparable;
  Comparable* clean = new Comparable;
  Comparable* free = new Comparable;
  Comparable* bed = new Comparable;
  Comparable* snow = new Comparable;
  Comparable* hat = new Comparable;

  ssa >> *comp;
  ssb >> *fly;
  ssc >> *door;
  ssd >> *water;

  sse >> *tv;
  ssf >> *air;
  ssg >> *clean;
  ssh >> *free;

  ssi >> *bed;
  ssj >> *snow;
  ssk >> *hat;


  BST st1;
  
  st1.insert(comp);
  st1.insert(fly);
  st1.insert(door);
  st1.insert(water);
  st1.insert(tv);
  st1.insert(air);
  st1.insert(clean);
  st1.insert(free);
  st1.insert(bed);
  st1.insert(snow);
  st1.insert(hat);

  cout << st1 << endl;


}

int main()
{
   // test1();
   // test2();
   // test3();
   test4();


   return 0;
}





