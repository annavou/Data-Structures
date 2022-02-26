#include <iostream>
#include <string>
using namespace std;

class hashtable
{
  private:
     int m;
     int k;
     unsigned int hashcode(string &);
     unsigned int hashcode2(unsigned int);
  public:
     hashtable();
     ~hashtable();
     string *H;
     int *freq;
     void insert(string);
     bool search(string &,unsigned int &); 
     void printhash(); 
};
