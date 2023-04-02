#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> tree(100005);
vector<int> vec;

void segmentes_tree(int ind,int low,int high)
{
    if(low==high)
    {
        tree[ind]=vec[low];
        return;
    }
    int mid =(low+high)/2;
    segmentes_tree(2*ind+1,low,mid);
    segmentes_tree(2*ind+2,mid+1,high);
    tree[ind] = max(tree[2*ind+1],tree[2*ind+2]);
}

int query(int ind,int l,int r,int high,int low)
{
    if(low>= l && high<=r)
    {
        return tree[ind];
    }
    if(high<l || low >r)
    {
        return INT_MIN;
    }
    int mid= (low+high)/2;
    int left = query(2*ind+1,l,r,mid,low);
    int right = query(2*ind+2,l,r,high,mid+1);

    return max(left,right);
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    segmentes_tree(0,0,n-1);

    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,l,r,n-1,0);
    }
}