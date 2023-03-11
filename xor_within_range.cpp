#include<bits/stdc++.h>

using namespace std;

int perform_xor(int n)
{
    // The problem could be solved by onserving the patterns within the set of the solutions being obtained from the test case inputs

    if(n%4==0)
    {
        return n;
    }
    else if(n%4==1)
    {
        return 1;
    }
    else if(n%4==2)
    {
        return n+1;
    }
    else
    {
        return 0;
    }
}

int xor_within_ranges(int l,int r)
{
    return (perform_xor(l-1)^perform_xor(r));
}

int main()
{
    int n;
    cin>>n;
    // inorder to find the XOR within the ranges of two elements provided perform the XOR of there edges then perform the xor inorder to cancel the common values between them 

}