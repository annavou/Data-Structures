#include <iostream>
using namespace std;
struct tNode1 

{
    string data;
    long long int freq;
    tNode1 * left;
    tNode1 * right;
};
class avltree
{
 public:
   tNode1 *root;
   avltree();
   int height(tNode1*);
   int BalanceFactor(tNode1*);
   tNode1* createtNode(string);
   tNode1* inserttNode(tNode1*,string);
   tNode1* deletetNode(tNode1*,string);
   tNode1* avlSearch(tNode1*, string);
   tNode1* rightRotate(tNode1*);
   tNode1* leftRotate(tNode1*);
   void PreOrder(tNode1*);
   void InOrder(tNode1*);
   void PostOrder(tNode1*);
};