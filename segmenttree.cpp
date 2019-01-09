#include<bits\stdc++.h>
using namespace std;

void cst(int ar[],int tree[],int index,int start,int end1)
{

  if(start==end1)
  {
     tree[index]=ar[start];

  }
  else{
   int mid=(start+end1)/2;
   cst(ar,tree,2*index+1,start,mid);
   cst(ar,tree,2*index+2,mid+1,end1);
   tree[index]=min(tree[2*index+1],tree[2*index+2]);
  }

}
int query(int tree[],int qst, int qend, int cindex, int start,int end1)

{
    if(qst<start && qend>end1)
    {

        return 0;
    }

    else if(qst>=start && qend<=end1)
    {
        return tree[cindex];
    }
    else
    {   int mid=(start+end1)/2;
        int min1=query(tree,qst,qend,2*cindex+1,start,mid);
         min1=query(tree,qst,qend,2*cindex+2,mid+1,end1);
        return min1;
    }
}
int main()
{
  int ar[]={1,2,5,7,9};
  int tree[9];
  cst(ar,tree,0,0,4);
 int ans=query(tree,0,2,0,3,4);
 cout<<ans;

}

