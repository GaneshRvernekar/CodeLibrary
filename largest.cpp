#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    long long n,k;
 
    cin>>n>>k;
    if(n<k)
    {
        cout<<0<<endl;
    }
 
    stack<int> st;
 
    vector<int> vec;
 
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }
 
    n= vec.size();
 
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top() < vec[i] && k>0 )
        {
            st.pop();
            k--;
        }
        st.push(vec[i]);
    }
    
        
        long long ans=1;
        long long sum_=0;
 
        while(k--)
        {
            st.pop();
        }
 
        while(!st.empty())
        {
            sum_ += st.top()*ans;
            ans=ans*10;
            st.pop();
        }
 
        
        cout<<sum_<<endl;
	
}