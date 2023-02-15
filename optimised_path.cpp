#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> dp(pow(2,n),INT_MAX);
    vector<vector<int>> vec(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            vec[i][j]=a;
             
        }
       
    }

    dp[0]=0;

    for(int mask=0;mask<pow(2,n);mask++)
    {
        int x = __builtin_popcount(mask);
 
        for(int j=0;j<n;j++)
        {
            if(( mask & (1<<j))==0)
            {
                dp[mask|1<<j]=min(vec[x][j]+dp[mask],dp[mask|1<<j]);
            }
        }
    }

    cout<<dp[pow(2,n)-1]<<endl;

}
