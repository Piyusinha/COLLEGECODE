#include <bits/stdc++.h>
using namespace std;
struct interval
{
    int low,high;
};

struct itnode{

interval *i;
itnode *left;
itnode *right;
int maxl;

};

itnode *newnode(interval i)
{
    itnode *temp=new itnode;
    temp->i=new interval(i);
    temp->maxl=i.high;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

};


itnode *insertnode( itnode *root,interval i)
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

bool dooverlap(interval i1,interval i2)
{

    if(i1.low<=i2.high && i1.high>=i2.low)
        return true;
    return false;
}

interval *overlapsearch(itnode *root,interval i)
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
void inorder(itnode *root)
{   if (root == NULL) return;
    inorder(root->left);
   cout << "[" << root->i->low << ", " << root->i->high << "]"
         << " max = " << root->maxl << endl;
    inorder(root->right);
}
int main()
{
    interval i[]= {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}} ;
    int n=sizeof(i)/sizeof(i[0]);
    itnode *root=NULL;
    cout<<n;
    for(int j=0;j<n;j++)
    {
        root=insertnode(root,i[j]);
    }
    cout<<"INORDER TRANSVERSAL"<<endl;
    inorder(root);
    interval check={6,7};
    cout<<"CHECK INTERVAL FOR"<<check.low<<","<<check.high<<endl;
    interval *res=overlapsearch(root,check);
    cout<<res->low<<","<<res->high;
}
