#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,target;

    cin>>n;

    vector<int> vec(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    cin>>target;

    int l=0,r=n-1;

    bool flag=true;

    while(l<r)
    {
        int mid =(l+r)/2;

        if(vec[mid]==target)
        {
            if(mid-1>=0 && vec[mid-1]==target)
            {
                r=mid;
            }
            else
            {
                flag=false;
                cout<<"Found at the location "<<mid<<endl;
                break;
            }
        }
        else if(vec[mid]<target)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(flag)
    {

    cout<<"Target value did not matched to any one of the value"<<endl;
    }

}