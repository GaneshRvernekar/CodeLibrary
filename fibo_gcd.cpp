#include<bits/stdc++.h>

using namespace std;

long long fibo(int n,vector<long long> &dp)
{
    if(n<=1)
    {
        return n;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    return dp[n]=(fibo(n-1,dp)+fibo(n-2,dp));
}

long long gcd(long long a,long long b,vector<vector<long long>> &dp)
{
    if(b==0)
    {
        return a;
    }
    if(dp[a][b]!=-1)
    {
        return dp[a][b];
    }
    return dp[a][b]=gcd(b,a%b,dp);
}

int main()
{
    int n;
    cin>>n;

    vector<long long > vec;

    long long max_=INT_MIN;

    for(int i=0;i<n;i++)
    {
           long long a;
           cin>>a;
           vec.push_back(a); 
           max_= max(max_,a);
    }

    vector<long long> dp(max_,-1);

    long long ans=1;

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                long long a= fibo(vec[i],dp);
                long long b= fibo(vec[i+1],dp);
                long long c= max(a,b);
                vector<vector<long long>> dp2(c,vector<long long>(c,-1));
                ans = gcd(a,b,dp2);
                i++;
            }
            else
            {
                 long long b= fibo(vec[i],dp);
                  long long c= max(ans,b);
                vector<vector<long long>> dp2(c,vector<long long>(c,-1));
                ans = gcd(ans,b,dp2);
            }
            
        }

        cout<<ans<<endl;

        return 0;

      

}