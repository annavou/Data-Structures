#include <iostream>
#include "arrayn.h"
#include "sortedar.h"
#include "binaryt.h"
#include "avltree.h"
#include "hashtable.h"
#include<fstream>
#include <time.h>
#include<string>
#include <stdlib.h>
#define N 1000
using namespace std;

int main() 
{ 
 
 //structures
 arrayn d;
 sortedar d1;
 binaryt d2;
 avltree d3;
 hashtable d4;

//variables needed
 clock_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
 int foundpl=0;
 tNode* r=NULL;
 tNode1* r1=NULL;
 string word,keyword,di,di2,di3,Q[N];
 unsigned int n=0;


//filehandling
ifstream file;
ofstream out;

//!!! IMPORTANT: Change the name below to the name of the input file of the folder 

file.open("gutenberg.txt");


//reading,editing and inserting each word to the structures

while (file>>word)
{
   di=word;
   
   //upper to lower
   for(int i=0;i<di.length();i++)
   {
    if(di[i]>=65 && di[i]<=90)
      di[i]+=32;
   }
   for(int i=0;i<di.length();i++)
   {
   if((di[i]<97||di[i]>122))
     {
       di.erase(i);
     }    
    }
    if(di!=" ")
    {
       d.insert(di);
       d1.insert2(di);
       r=d2.inserttNode(r,di);
       d2.SetRoot(r);
       r1=d3.inserttNode(r1,di);
       out<<di<<endl;
       d4.insert(di);
    }
  
}
file.close();

//creating a Q table with 1000 random selected words from the readen words 

srand(time(NULL));
for(int i=0;i<N;i++)
{
   Q[i]=d.data[rand()%(d.top-1)];
}
 
//searching the words of Q in non-sorted array

out.open("output.txt");

out<<"Non Sorted Array Results:"<<endl;
t1=clock();
for(int i=0;i<N;i++)
{
    if(d.Searchst(Q[i],foundpl))
    {  
       t2=clock();
       out<<"the frequency of the word "<<d.data[foundpl]<<" is:"<<d.freq[foundpl]<<endl;
    }
}
t2=clock();

//searching the words of Q in sorted array

out<<endl<<"Sorted Array Results:"<<endl;
t3=clock();
for(int i=0;i<N;i++)
{
    if(d1.binSearchst(Q[i],foundpl))
    {  
       t2=clock();
       out<<"the frequency of the word: "<<d1.data[foundpl]<<"  is: "<<d1.freq[foundpl]<<endl;
    }
}
t4=clock();

//searching the words of Q in binary search tree

out<<endl<<"Binary Search Tree Results:"<<endl;
t5=clock();
for(int i=0;i<N;i++)
{
  out<<"the frequency of the word: "<<d2.bintSearch(Q[i],d2.GetRoot())->data<<" is: "<<d2.bintSearch(Q[i],d2.GetRoot())->freq<<endl;
}
t6=clock();

//searching the words of Q in avl binary search tree

out<<endl<<"AVL Binary Search Tree Results:"<<endl;
t7=clock();
for(int i=0;i<N;i++)
{
  out<<"the frequency of the word: "<<d3.avlSearch(r1,Q[i])->data<<" is: "<<d3.avlSearch(r1,Q[i])->freq<<endl;

}
t8=clock();

//searching the words of Q in hashtable

out<<endl<<"Hashtable Results:"<<endl;
t9=clock();
 for(int i=0;i<N;i++)
 {
   if(d4.search(Q[i],n))
   {
     out<<"the frequency of the word: "<<d4.H[n]<<" is:  "<<d4.freq[n]<<endl;
   }
 }
 t10=clock();

//printing the time that each structure neeeds to find all the Q words

out<<endl<<"Time needed for each data structure to find 1000 words of Q array"<<endl;

out<<"Time taken for non-sorted array:"<<fixed<<double(t2-t1)/ double(CLOCKS_PER_SEC)<<"secs"<<endl;

out<<"Time taken for sorted array:"<<fixed<<double(t4-t3)/ double(CLOCKS_PER_SEC)<< "secs"<<endl;

out<<"Time taken for binary search tree:"<<fixed<<double(t6-t5)/ double(CLOCKS_PER_SEC)<< "secs"<<endl;

out<<"Time taken for AVL binary search tree:"<<fixed<<double(t8-t7)/ double(CLOCKS_PER_SEC)<<"secs"<<endl;

out<<"Time taken for hashtable:"<<fixed<<double(t10-t9)/ double(CLOCKS_PER_SEC)<<"secs"<<endl;
 
cout<<"File output.txt was created with Q words found in each structure and time results in the lower part"<<endl;

// delete and printing methods (remove /*,*/ to use them)
/*out<<endl;
d.printarray();
d1.printsortedarray();
d2.PreOrder(r);
d2.InOrder(r);
d2.PostOrder(r);
d3.PreOrder(r1);
d3.InOrder(r1);
d3.PostOrder(r1);
d4.printhash();

for(int i=0;i<N;i++)
{
   d.delete2(Q[i]);
   d1.delete21(Q[i]);
   d2.bintDelete(Q[i],r);
   d3.deletetNode(r1, Q[i]);
}
out<<endl;
d.printarray();
d1.printsortedarray();
d2.PreOrder(r);
d2.InOrder(r);
d2.PostOrder(r);
d3.PreOrder(r1);
d3.InOrder(r1);
d3.PostOrder(r1);
d4.printhash();*/


}
