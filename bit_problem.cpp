#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    int xor_=vec[0];

    for(int i=1;i<n;i++)
    {
        xor_^=vec[i];
    }

    // check for the setted bit within this number so that can distinguish between these number in the further wards
    int index=0;
    while(xor_)
    {
        if(xor_&1)
        {
            break;
        }
        xor_= xor_>>1;
        index++;
    }

    int xor_1=0,xor_2=0;

    for(int i=0;i<n;i++)
    {
        if(vec[i]&(1<<index))
        {
            xor_1 ^=vec[i];
        }
        else
        {
            xor_2 ^=vec[i];
        }
    }

    cout<<"The two numbers are "<<xor_1<<" "<<xor_2<<endl;

}