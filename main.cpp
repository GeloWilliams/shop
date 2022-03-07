
/**
g++ -g -std=c++11 -o main main.cpp ProductFactory.cpp Product.cpp Coin.cpp Comic.cpp SportsCard.cpp CustomerHouse.cpp Customer.cpp BST.cpp
   cd Desktop/Main/Study/CSS502/Programs/Program4
*/  

#include <iostream>
#include <sstream>
#include <vector>
#include "ProductFactory.h"
#include "CustomerHouse.h"

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
   // ProductFactory pf;

   // for (int i = 0; i < 3; i++) {
   //    string userString;
   //    cout << "Enter a word: ";

   //    char userInput;
   //    cout << "Enter a char: ";
   //    cin >> userInput;
   //    int idx = pf.hashFunction(userInput);
   // }
   // cout << endl;
   // cout << "Your words: " << endl;
   // pf.print();
   // cout << endl;
}

void test2()
{
   // string userString;
   // cout << "Enter a word: ";
   // cin >> userString;

}

void test3()
{

   ProductFactory pf;
   
   Comparable* h = pf.create("P, 3, 1998, testing");
   Comparable* o = pf.create("P, 1, 2020, messing");
   Comparable* q = pf.create("P, 6, 1963, dressing");
   Comparable* r = pf.create("P, 10, 2076, feasting");
   Comparable* v = pf.create("P, 2, 1999, cresting");
   Comparable* c = pf.create("M, 7, 2001, 65, Lincoln Cent");
   Comparable* d = pf.create("M, 6, 2015, 70, Abraham Nickel");
   Comparable* m = pf.create("C, 1, 2000, Excellent, Lord of the Rings, Tolken");
   Comparable* n = pf.create("C, 8, 1992, Decent, Sonic the Hedgehog, BestCorp");
   Comparable* t = pf.create("C, 10, 1979, Good, Garfield, TheBest Place");
   Comparable* w = pf.create("S, 9, 2002, Near Mint, Ryu the Great, Upper Deck");
   Comparable* s = pf.create("S, 4, 2003, Very Good, Ken the Master, Topps"); 

   pf.print();

   Comparable* x = pf.create("P, 1, 2020, messing");

   Comparable* item = pf.get("C, 8, 1992, Decent, Sonic the Hedgehog, BestCorp");
   cout << "getting: ";
   cout << item->getItem() << endl;

   if (item->isEmpty()) {
      cout << "item is empty." << endl;
   } else {
      cout << "item is NOT empty" << endl;
   }

   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   cout << "reduce by 1: " << endl;
      item->reduce();
   cout << item->getItem() << endl;
   cout << endl;
   if (item->isEmpty()) {
      cout << "item is empty." << endl;
   } else {
      cout << "item is NOT empty" << endl;
   }
   cout << endl;
   cout << "increase by 1: " << endl;
      item->increase();
   cout << item->getItem() << endl;
   cout << endl;

   if (item->isEmpty()) {
      cout << "item is empty." << endl;
   } else {
      cout << "item is NOT empty" << endl;
   }

   cout << endl;
   cout << "Removing item: " << endl;
   cout << endl;
   item->reduce();
   cout << item->getItem() << endl;
   cout << endl;

///// IMPORTANT REMOVE INFORMATION - old //;//

   // // Remove if quantity_ drops below 1:
   // item->reduce(); // last one
   // // check
   // if (item->isEmpty()) {
   //    char key = item->getItem()[0];
   //    pf.remove("C, 8, 1992, Decent, Sonic the Hedgehog, BestCorp");
   // }

   //// NOW, just check if empty before printing in BST /////




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
//   std::stringstream ssa("b"); // comp
//   std::stringstream ssb("a"); // fly
//   std::stringstream ssc("c"); // door
//   std::stringstream ssd("f"); // water

//   std::stringstream sse("z"); // tv
//   std::stringstream ssf("a"); // air
//   std::stringstream ssg("i"); // clean
//   std::stringstream ssh("t"); // free
  
//   std::stringstream ssi("i"); // bed
//   std::stringstream ssj("p"); // snow
//   std::stringstream ssk("i"); // hat

//   Comparable* comp = new Comparable;
//   Comparable* fly = new Comparable;
//   Comparable* door = new Comparable;
//   Comparable* water = new Comparable;
//   Comparable* tv = new Comparable;
//   Comparable* air = new Comparable;
//   Comparable* clean = new Comparable;
//   Comparable* free = new Comparable;
//   Comparable* bed = new Comparable;
//   Comparable* snow = new Comparable;
//   Comparable* hat = new Comparable;

//   ssa >> *comp;
//   ssb >> *fly;
//   ssc >> *door;
//   ssd >> *water;

//   sse >> *tv;
//   ssf >> *air;
//   ssg >> *clean;
//   ssh >> *free;

//   ssi >> *bed;
//   ssj >> *snow;
//   ssk >> *hat;


//   BST st1;
  
//   st1.insert(comp);
//   st1.insert(fly);
//   st1.insert(door);
//   st1.insert(water);
//   st1.insert(tv);
//   st1.insert(air);
//   st1.insert(clean);
//   st1.insert(free);
//   st1.insert(bed);
//   st1.insert(snow);
//   st1.insert(hat);

//   cout << st1 << endl;


}

void test5()
{
   cout << "-------------------------------------------------------------------"  << endl;
   BST bt;
   Comic h;
   Comic d;
   Comic a;
   Comic y;
   

   Comparable* p = h.build("C, 12, 2000, Excellent, Lord of the Rings, Tolken");
   Comparable* x = d.build("C, 7, 1979, Good, Garfield, TheBest Place");
   Comparable* r = a.build("C, 9, 2000, Excellent, Lord of the Rings, Tolken");
   Comparable* t = y.build("C, 3, 1992, Decent, Sonic the Hedgehog, BestCorp");

   bt.insert(p);
   bt.insert(x);
   bt.insert(r);
   bt.insert(t);

   cout << bt << endl;
   cout << endl;
   bt.remove(*x);

   cout << bt << endl;

}

void test6()
{
   // Customer c;
   // CustomerHouse ch;
   // Customer* y = c.build("179, Ryan");
   // Customer* b = c.build("15, Sarah Blade");
   // Customer* m = c.build("28, Tom Selter");

   // cout << y->getItem() << endl;
   // cout << b->getItem() << endl;

   // // can see actual index inserted with cout inside addCustomer
   // ch.addCustomer(15, y);
   // ch.addCustomer(15, b);
   // ch.addCustomer(15, m);
   // ch.addCustomer(27, b);
   

   // cout << "Testing hash values: " << endl;
   // cout << "017: " << ch.hashFunction(017, 0) << endl;

   // cout << "004: " << ch.hashFunction(004, 0) << endl;
   // cout << "983: " << ch.hashFunction(983, 0) << endl;
   // cout << "666: " << ch.hashFunction(666, 0) << endl;
   // cout << "017: " << ch.hashFunction(017, 0) << endl;
   // cout << "1865: " << ch.hashFunction(1865, 0) << endl;
   // cout << "036: " << ch.hashFunction(036, 0) << endl;
   // cout << "7: " << ch.hashFunction(7, 0) << endl;
   // cout << "425: " << ch.hashFunction(425, 0) << endl;
   // cout << "17: " << ch.hashFunction(17, 0) << endl;
   // cout << "017: " << ch.hashFunction(007, 0) << endl;
   // cout << "015: " << ch.hashFunction(015, 0) << endl;
   // cout << "15: " << ch.hashFunction(15, 0) << endl;
}

void test7()
{
   CustomerHouse ch;
   ch.create("179, Ryan");
   ch.create("15, Sara");
   ch.create("88, Philip Kim");

   Comparable* p = ch.get(179);
   cout << "retrieved: " << p->getItem() << endl;
   cout << endl;

   ch.print();
   
   cout << endl;
   cout << "deleted: Ryan" << endl;
   cout << endl;
   ch.remove(179);

   ch.print();
   cout << "delete: Philip Kim " << endl;
   ch.remove(88);
   cout << endl;
   
   ch.print();

}

void test8()
{
   CustomerHouse ch;
   ProductFactory pf;

   // create products
   Comparable* h = pf.create("P, 3, 1998, testing");
   Comparable* o = pf.create("P, 1, 2020, messing");
   Comparable* q = pf.create("P, 6, 1963, dressing");
   Comparable* r = pf.create("P, 10, 2076, feasting");
   Comparable* v = pf.create("P, 2, 1999, cresting");
   Comparable* c = pf.create("M, 7, 2001, 65, Lincoln Cent");
   Comparable* d = pf.create("M, 6, 2015, 70, Abraham Nickel");
   Comparable* m = pf.create("C, 1, 2000, Excellent, Lord of the Rings, Tolken");
   Comparable* n = pf.create("C, 8, 1992, Decent, Sonic the Hedgehog, BestCorp");
   Comparable* t = pf.create("C, 10, 1979, Good, Garfield, TheBest Place");
   Comparable* w = pf.create("S, 9, 2002, Near Mint, Ryu the Great, Upper Deck");
   Comparable* s = pf.create("S, 4, 2003, Very Good, Ken the Master, Topps"); 

   // get customers
   ch.create("179, Ryan");
   ch.create("15, Sara");
   ch.create("88, Philip Kim");

   ch.cBuy(15,h);
   ch.cBuy(15,d);
   ch.cBuy(15,t);
   ch.cSell(15,c);
   ch.cSell(88,m);

   cout << "Sara's transactions:" << endl;
   cout << endl;
   cout << *ch.get(15) << endl;



}


int main()
{
   // test1();
   // test2();
   // test3();
   // test4();
   test5();
   // test6();
   test7();
   test8();


   return 0;
}





