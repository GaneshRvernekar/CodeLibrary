#include<bits/stdc++.h>

// This is one of the most standard approach in solving the problem with bitwise operation .
// as we deal here with the all the combinations within the given input number .
// that can be checked with the help of the bits which are setted in the ith number within the total number.
// inorder to check within it considered number should be within the  range from 0 to 2^n-1
// The bits which are setted within the considered number we can find out all the combinations within the given set of numbers .



// Petr called his car dealer, who instructed him to rotate the lock's wheel exactly n
//  times. The i
// -th rotation should be ai
//  degrees, either clockwise or counterclockwise, and after all n
//  rotations the pointer should again point at zero.

// This confused Petr a little bit as he isn't sure which rotations should be done clockwise and which should be done counterclockwise. As there are many possible ways of rotating the lock, help him and find out whether there exists at least one, such that after all n
//  rotations the pointer will point at zero again.


using namespace std;

int main()
{
    int n;
    vector<int> vec;

    bool flag=true;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum+=vec[i];
            }
            else
            {
                sum-=vec[i];
            }
        }

        if(sum==0)
        {
            cout<<"YES"<<endl;
            flag=false;
        }
    }

    if(flag)
    {
        cout<<"No "<<endl;
    }
}