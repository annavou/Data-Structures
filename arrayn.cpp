#include "arrayn.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

arrayn::arrayn()
{
  data=new string[1001]; //array with the words
  freq= new int[1001]; //array with the frequencies
  //cout<<"array created"<<endl; 
  for(int i=0;i<1001;i++)
  {
    freq[i]=0;
  }
  size=1001;
  top=0;
}

bool arrayn::Searchst(string rand,int &place)
{
  char state=0;
  //searching the word till its found or till elements are over
  for(int i=0;i<=top&&state==0;i++)
  {
   if (data[i]==rand)
   {
     state=1;
     place=i;
   }
  }
  if(state)
    return true;
  else
    return false;
}

void arrayn::insert(string rand)
{
  int place=0;
  if(top==size)
  {
    //reallocate everytime top==size
    string *temp;
    int *temp1;
    size=size+10000;
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
  if(!Searchst(rand,place))
  { //if word is not already found in array
    data[top]= rand;
    freq[top]=1;
    top+=1;
  }
  else
  {
    //if word is already found in array
    freq[place]+=1;
  }
}

void arrayn::delete2 (string k)
{
  int pl;
  //deleting a word and replacing the elemenents
  while(Searchst(k, pl)){
    freq[pl]-=1;
    for(int i=pl;i<top;i++){
      data[i]=data[i+1];
      freq[i]=freq[i+1];
    }
    top-=1;
  }
}

void arrayn::printarray()
{
  //printing in output file
  ofstream out;
  out.open("output.txt",ios::app);
  for(int i=0;i<top;i++)
  {
   out<<"the frequency of the word "<<data[i]<<" is:"<<freq[i]<<endl;
  }
  out<<endl;
  out.close();
}