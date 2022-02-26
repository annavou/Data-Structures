#include "sortedar.h"
#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;
 
sortedar::sortedar()
{
  //cout<<"sorted array created"<<endl;
  data=new string[1024];
  freq= new int[1024];
  for(int i=0;i<10;i++)
    freq[i]=0;
  size=10;
  top=-1;
}
 
bool sortedar::binSearchst(string rand,int &place)
{
  //binary search
  char state=0;
  place=-1;
  int mid,sta=0,fin=top;
  while(sta<=fin)
  {
    mid=(sta+fin+1)/2;
    if(rand==data[mid])//comparing strings
    {
      place=mid;
      sta=fin+1;
    }
    else if(data[mid]<rand)
      sta=mid+1;
    else if(data[mid]>rand)
      fin=mid-1;
  }
  if(place==-1)
    return false;
  else
    return true;
}
 
void sortedar::sorinsert(string rand)
{
  int rp=-1;
  if (top>=0)//sorting strings by finding the right place for each word
  {
    for(int i=0;i<=top&&rp==-1;i++)
    {
      if(rand<=data[i])
      {
        rp=i;
      }
    }
    top+=1;
    if(rp!=-1)
    {
      if(top==size)
      {
        //reallocate everytime top==size
        string *temp;
        int *temp1;
        size+=100000;
        temp1= new int[size];
        temp= new string[size];
        for(int i=0;i<top;i++)
        { 
          temp[i]=data[i];
          temp1[i]=freq[i];
        }
        for(int i=top;i<size;i++)
        { 
          temp1[i]=0;
        }
        delete []data;
        delete []freq;
        freq=temp1;
        data=temp;
      }
      for(int i=top-1;i>=rp;i--)
      {
        data[i+1]=data[i];
        freq[i+1]=freq[i];
      }
      data[rp]=rand;
      freq[rp]=1;
    }
    else
    {
      data[top]=rand;
      freq[top]+=1;
    }
  }
  else
  {
    top=0;
    data[0]=rand;
    freq[0]=1;
  }
}
 
void sortedar::insert2(string rand)
{
  int place=0;
  if(binSearchst(rand,place))
  { // word already registered
    freq[place]+=1;
  }
  else
  {
    //new word
    sorinsert(rand);
  }
}
 
void sortedar::delete21 (string k)
{
 int pl;
 //deleting a word and replacing the elemenents
 while(binSearchst(k, pl))
 {
   freq[pl]-=1;
   for(int i=pl;i<top;i++)
   {
     data[i]=data[i+1];
     freq[i]=freq[i+1];
   }
   top-=1;
 }
}

void sortedar::printsortedarray()
{
  //printing in output file
  ofstream out;
  out.open("output.txt",ios::app);
  for(int i=0;i<=top;i++)
  {
   out<<"the frequency of the word "<<data[i]<<" is:"<<freq[i]<<endl;
  }
  out<<endl;
  out.close();
}
