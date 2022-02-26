#include <iostream>
using namespace std;

class sortedar
{
  public:
   string *data;
   int *freq;
   int top;
   int size;
   sortedar();
   void insert2(string);
   void sorinsert(string);
   //based on word delete
   void delete21(string);
   bool binSearchst(string r,int &p);
   void printsortedarray();
};