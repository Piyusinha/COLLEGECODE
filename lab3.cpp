#include <bits/stdc++.h>
using namespace std;
struct range
{
    int low,high;
};

struct itnode{

range *i;
itnode *left;
itnode *right;
int maxl;

};

itnode *newnode(range i)
{
    itnode *temp=new itnode;
    temp->i=new range(i);
    temp->maxl=i.high;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

};


itnode *insertnode( itnode *root,range i)
{
    if(root==NULL)
    {
        return newnode(i);
    }
    int l=root->i->low;
    if(i.low<l)
    {
        root->left=insertnode(root->left,i);
    }
    else
    {
        root->right=insertnode(root->right,i);

    }
    if(root->maxl<i.high)
    {
        root->maxl=i.high;
    }
    return root;
}

bool dooverlap(range i1,range i2)
{

    if(i1.low<=i2.high && i1.high>=i2.low)
        return true;
    return false;
}

range *overlapsearch(itnode *root,range i)
{
    if(root==NULL)
    {
        return NULL;

    }
    if(dooverlap(*(root->i),i))
    {
        return root->i;
    }
    if(root->left!=NULL && root->left->maxl>=i.low)
        return overlapsearch(root->left,i);
    return overlapsearch(root->right,i);




}
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void delete1(int ar[],itnode *root,int size)

{
    for(int i=0;i<size;i++)
    {

       if(i==size-1)
       {
           delete root;
       }
      if(ar[i]==root->i->low)
         {
             swap(ar[i],ar[i++]);
         }

    }

}
void inorder(itnode *root)
{   if (root == NULL) return;
    inorder(root->left);
   cout << "[" << root->i->low << ", " << root->i->high << "]"
         << root->maxl << endl;
    inorder(root->right);
}

int main()
{
     range i[]= {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40}} ;
    int n=sizeof(i)/sizeof(i[0]);
    itnode *root=NULL;
    cout<<n;
    for(int j=0;j<n;j++)
    {
        root=insertnode(root,i[j]);
    }
    range i1;
    cout<<"ENTER LOW VALUE FOR INSERT"<<endl;
    cin>>i1.low;
      cout<<"ENTER HIGH VALUE FOR INSERT"<<endl;
      cin>>i1.high;
    insertnode(root,i1);
    cout<<"INORDER TRANSVERSAL"<<endl;
    inorder(root);
    range check={12,15};
    cout<<"CHECK INTERVAL FOR"<<check.low<<","<<check.high<<endl;
    range *res=overlapsearch(root,check);
    cout<<res->low<<","<<res->high;
    cout<<"ENTER INTERVAL TO DELETE"<<endl;

}
