#include <iostream>
#include <string>
#include "hashtable.h"
#include <fstream>
using namespace std;

hashtable::hashtable()
{
  m=100; //the size of the arrays
  k=0; //the elements of the array
  H=new string[m]; //array with the words
  freq=new int[m]; //array with the frequency of the words
  for(int i=0;i<m;i++)
    H[i]=" ";
  for(int i=0;i<m;i++)
    freq[i]=0;
}

hashtable::~hashtable()
{
  delete []H;
  delete []freq;
  freq=nullptr;
  H=nullptr;
  m=0;
  k=0;
}

unsigned int hashtable::hashcode(string &rand) //finds the place to be in the array
{
  int hash;
  for(int i=0;i<rand.length();i++)
    hash+=rand[i]; 
  return hash%m;
}

unsigned int hashtable::hashcode2(unsigned int d) //if there is a collizion we increase the place by one
{
  return (d+1)%m;
}

void hashtable::insert(string rand)
{
  if(k>=m/2) //if the array is 50% or over 50% full we restain more space
  {
    //cout<<"hash realloc"<<endl;
    string *temp;
    int *temp2;
    m*=2;
    temp=new string [m];
    temp2=new int [m];
    for(int i=0;i<m;i++)
    {
      temp[i]=" ";
      temp2[i]=0;
    }
    for(int i=0;i<m/2;i++)
    {
      if(H[i]!=" ")  //after we double the space of the array we reorder the data
      {
        unsigned int d=hashcode(H[i]);
        while(temp[d]!=" ")
          d=hashcode2(d);
        temp[d]=H[i];
        temp2[d]=freq[i];
        H[i]=" ";
        freq[i]=-1;
      }
    }
    delete []H;
    delete []freq;
    H=temp;
    freq=temp2;
  }
  unsigned int d=hashcode(rand); //insert the new data
  if(H[d]==" ") //if we find the word for the first time we put it the place and we increase the elements that's in the array
  {
    H[d]=rand;
    freq[d]=1;
    k++;
  }
  else if(H[d]==rand) //if the word is the same with the one that's already in the that place we increase the frequency of the word
  {
    freq[d]+=1;
  }
  else
  {
    while (H[d]!=" " && H[d]!=rand) //if there is a collizion we increase the place by 1 until we find empty space or the word we want to insert is the same with the word in some other place
    d=hashcode2(d);
    if(H[d]==rand)
      freq[d]+=1;
    else if(H[d]==" ")   
    {
      H[d]=rand;
      freq[d]=1;
      k++;
    }
  }
}

bool hashtable::search(string &rand,unsigned int &p) //finds the place that the word supposed to be and then if the word is in the book
{
  p=hashcode(rand);
  while(H[p]!=rand)
    p=hashcode2(p);
  if(H[p]==rand)
    return true;
  else
    return false;
}

void hashtable::printhash()
{
  ofstream out;
  out.open("output.txt",ios::app);
  for(int i=0;i<m;i++)
  {
   if(H[i]!=" ")
    out<<"the frequency of the word "<<H[i]<<" is:"<<freq[i]<<endl;
  }
  out<<endl;
  out.close();
}

