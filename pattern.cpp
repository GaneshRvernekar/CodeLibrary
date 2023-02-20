#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int j= n-2;
    int i=0;

    for(;i<=n;i++)
    {
        for(int m=0;m<i;m++)
        {
            cout<<" ";
        }
        cout<<i+1;
        if((i+1)==(n/2)+1)
       {
        break;
       }          
       for(int k=0;k<j;k++)
       {
        cout<<" ";
       }
       j-=2;
       cout<<n-i<<endl;    
    }
    int k=i;

    while(i>=0)
    {
        for(int m=0;m<i;m++)
        {
            cout<<" ";
        }
        cout<<i

    }
  
}