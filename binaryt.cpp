#include<fstream>
#include "binaryt.h"
#include <iostream>
#include <string>
using namespace std;
//curroot:is the current root
//each node contains: left and right child pointer, a word and the frequency of it

binaryt::binaryt()
{
  root=NULL;
  //cout<<"bst created"<<endl;
}

tNode* binaryt::createtNode(string rand)
{
  //creation of a new node with string given
  tNode* newtNode=new struct tNode();
  newtNode->data=rand;
  newtNode->freq=1;
  newtNode->left=newtNode->right=NULL;
  return newtNode;
}

tNode* binaryt::inserttNode(tNode * curroot,string rand)
{
  if (curroot==NULL)
  {
    return createtNode(rand);
  }
  //searching the right place to enter the new word
  else if(rand<curroot->data)
  {
    curroot->left=inserttNode(curroot->left,rand);
  }
  else if(rand>curroot->data)
  {
    curroot->right=inserttNode(curroot->right,rand);
  }
  else if(rand==curroot->data)
  {
    curroot->freq+=1;
  }
  return curroot;
}

void binaryt::InOrder(tNode* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  InOrder(root->left);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
  InOrder(root->right);
}

void binaryt::PreOrder(tNode* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
  PreOrder(root->left);
  PreOrder(root->right);
}

void binaryt::PostOrder(tNode* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  PostOrder(root->left);
  PostOrder(root->right);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
}

tNode* binaryt::bintSearch(string rand, tNode* root)
{
  if(root==NULL||root->data==rand)
  {
    return root;
  }
  else if(rand<root->data)
  {
    return bintSearch(rand,root->left);
  }
  return bintSearch(rand,root->right);
}

tNode* binaryt::bintDelete(string rand,tNode* curroot)
{
  if(curroot==NULL)
  {
    return curroot;
  }
  else if(curroot->data>rand)
  {
     curroot->left=bintDelete(rand,curroot->left);
     return curroot;
  }
  else if(curroot->data<rand)
  {
     curroot->right=bintDelete(rand,curroot->right);
     return curroot;
  }
  else
  {
   //if the node deleted has 0 or 1 child
   if(curroot->left==NULL)
   {
    tNode *temp=curroot->right;
    delete curroot;
    return temp;
   }
   else if(curroot->right==NULL)
   {
    tNode *temp=curroot->left;
    delete curroot;
    return temp;
   }
   else
   {
    //if the node has 2 children
    //minimum successor of right subtree
    tNode* succp=curroot,*succ=curroot->right;
    while(succ->left!=NULL)
    {
      succp=succ;
      succ=succ->left;
    }
    if(succp!=curroot)
    {
       succp->left=succ->right;
    }
    else
       succp->right=succ->right;
    curroot->data=succ->data;
    curroot->freq=succ->freq;
    delete succ;
    return curroot;
   }
  }
}