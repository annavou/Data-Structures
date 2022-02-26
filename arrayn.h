#include <iostream>
using namespace std;

class arrayn
{
  public:
   string *data;
   int *freq;
   int top;
   int size;
   arrayn();
   void insert(string);
   //based on word delete
   void delete2(string);
   bool Searchst(string r,int &p);
   void printarray();
};