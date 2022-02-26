#include <iostream>
using namespace std;

struct tNode
{
  string data;
  long long int freq;
  tNode *left,*right;
};

class binaryt
{
  private:
    struct tNode *root;
  public:
    binaryt();
    tNode *GetRoot(){return root;};
    tNode* createtNode(string);
    tNode* inserttNode(tNode*,string);
    void PreOrder(tNode*);
    void InOrder(tNode*);
    void PostOrder(tNode*);
    void SetRoot(tNode * p){root=p;};
    tNode* bintSearch(string, tNode*);
    tNode* bintDelete(string,tNode*);
};