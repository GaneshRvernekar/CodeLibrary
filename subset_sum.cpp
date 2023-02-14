#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int sum=0;

    cin>>sum;
    

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(dp[i-1][j]==1)
            {
                dp[i][j]=1;
            }
            else if(j>=arr[i-1])
            {
                if(dp[i-1][j-arr[i-1]]==1)
                {
                    dp[i][j]=1;
                }
            }
        }
    }

    if(dp[n][sum])
    {
        cout<<"Subset of sum "<<sum<< " possible by the given array "<<endl;
    }
    else
    {
        cout<<"Subset of sum "<<sum<< " not possible by the given array "<<endl;

    }
}

