#include<bits/stdc++.h>

using namespace std;

void sorting(stack<int> &st)
{
    if(st.size()==1)
    {
        return ;
    }
    int up = st.top();
    st.pop();
    sorting(st);
    stack<int> st2;
    while(!st.empty() && st.top()>up)
    {
        st2.push(st.top());
        st.pop();
    }
    st.push(up);

    while(!st2.empty())
    {
        st.push(st2.top());
        st2.pop();
    }
}

int main()
{
    stack<int> st;
    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
        st.push(a);
    }

    sorting(st);

    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}