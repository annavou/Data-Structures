#include <iostream>
#include "avltree.h"
#include <fstream>
using namespace std;

//curroot:is the current root
//each node contains: left and right child pointer, a word and the frequency of it

tNode1* avltree::createtNode(string rand)
{
  //creation of a new node with string given
  //cout<<"new node"<<endl;
  tNode1* newtNode=new struct tNode1();
  newtNode->data=rand;
  newtNode->freq=1;
  newtNode->left=newtNode->right=NULL;
  return newtNode;
}

avltree::avltree()
{
  root=NULL;
  //cout<<"avl created"<<endl;
}

int avltree::height(tNode1* curroot)
{
    if(curroot==NULL)
      return -1;
    else{
      //height of each subtree
      int leftheight=height(curroot->left);
      int rightheight=height(curroot->right);
      //selecting the bigger one
      if(leftheight>rightheight)
        return (leftheight+1);
      else 
        return (rightheight+1);
    }
}

int avltree::BalanceFactor(tNode1* curroot)
{
    if(curroot==NULL)
      return -1;
    //returning the difference of heights
    return height(curroot->left)-height(curroot->right);
}

tNode1* avltree::rightRotate(tNode1* y)
{
   tNode1* x=y->left;
   tNode1* temp=x->right;
   x->right=y;
   y->left=temp;
   return x;
}

tNode1* avltree::leftRotate(tNode1* x)
{
   tNode1* y=x->right;
   tNode1* temp=y->left;
   y->left=x;
   x->right=temp;
   return y;
}

tNode1* avltree::inserttNode(tNode1* curroot,string rand)
{
    if(curroot==NULL)
      return createtNode(rand);
    //searching the right place to enter the new word
    if(rand<curroot->data)
      curroot->left=inserttNode(curroot->left,rand);
    else if(rand>curroot->data)
      curroot->right=inserttNode(curroot->right,rand);
    else{
      curroot->freq+=1;
      return curroot;
    }
    //checking the balance to see if rotation is neeeded
    int bf = BalanceFactor(curroot);
    // LL Case 
    if(bf>1 && rand<curroot->left->data)
      return rightRotate(curroot);
    // RR Case 
    if(bf<-1 && rand>curroot->right->data)
      return leftRotate(curroot);
    // LR Case  
    if(bf>1 && rand>curroot->left->data){
      curroot->left=leftRotate(curroot->left);
      return rightRotate(curroot);
    }
    // RL Case  
    if(bf<-1 && rand<curroot->right->data){
      curroot->right=rightRotate(curroot->right);
      return leftRotate(curroot);
    }
    return curroot;
}

tNode1* minvaluetnode(tNode1* curroot){
  tNode1* succNode=curroot;
  //finding the leftmost min to use it as successor in deletetNode
  while(succNode->left!=NULL)
    succNode=succNode->left;
  return succNode;
}

tNode1* avltree::deletetNode(tNode1 * curroot, string rand)
{
    if(curroot==NULL)
      return NULL;
    else if(rand<curroot->data)
      curroot->left=deletetNode(curroot->left,rand);
    else if(rand>curroot->data)
      curroot->right=deletetNode(curroot->right,rand);
    else{
      //if the node deleted has 0 or 1 child
      if(curroot->left==NULL){
        tNode1* temp=curroot->right;
        delete curroot;
        return temp;
      }
      else if(curroot->right==NULL){
        tNode1* temp=curroot->left;
        delete curroot;
        return temp;
      }
      else{
        //if the node has 2 children
        //minimum successor of right subtree
        tNode1* temp=minvaluetnode(curroot->right);
        curroot->data=temp->data;
        curroot->freq=temp->freq;
        curroot->right=deletetNode(curroot->right,temp->data);
      }
    }
    int bf=BalanceFactor(curroot);
    //left height greater than right by 2 so at least one right rotation is needed
    if(bf==2 && BalanceFactor(curroot->left)>=0)
      return rightRotate(curroot);
    else if(bf==2 && BalanceFactor(curroot->left)==-1){
      curroot->left=leftRotate(curroot->left);
      return rightRotate(curroot);
    }
    //right height greater than right by 2 so at least one left rotation is needed
    if(bf==-2 && BalanceFactor(curroot->right)<=0)
      return leftRotate(curroot);
    else if(bf==-2 && BalanceFactor(curroot->right)==1){
      curroot->right=rightRotate(curroot->right);
      return leftRotate(curroot);
    }
   return curroot;
}

tNode1* avltree::avlSearch(tNode1* curroot,string rand)
{
  //binary search with recursion same as in binary
  if(curroot==NULL || rand==curroot->data)
    return curroot;
  else if(rand<curroot->data)
    return avlSearch(curroot->left,rand);
  else
    return avlSearch(curroot->right,rand);
}

void avltree::InOrder(tNode1* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  InOrder(root->left);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
  InOrder(root->right);
}

void avltree::PreOrder(tNode1* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
  PreOrder(root->left);
  PreOrder(root->right);
}

void avltree::PostOrder(tNode1* root)
{
  if(root==NULL)
   return;
  ofstream out;
  out.open("output.txt",ios::app);
  PostOrder(root->left);
  PostOrder(root->right);
  out<<"The frequency of the word "<<root->data<<" is:"<<root->freq<<endl;
}
