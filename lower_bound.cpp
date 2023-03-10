#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> vec;
    cin>>n;
    int target;
    cin>>target;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    int l=0,r=n-1;

    while(l<r)
    {
        int mid=(l+r)/2;

        if(vec[mid]==target)
        {
            cout<<"found at "<<mid<<endl;
        }
        else if(vec[mid]<target)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }

    cout<<"Nearest element found is "<<vec[r]<<endl;

    return 0;
}