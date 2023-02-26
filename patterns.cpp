#include<bits/stdc++.h>

using namespace std;

void stars()
{
    int n;

     cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(2*n);j++)
        {
            if(j<=i)
            {
                cout<<j;
            }
            else if(j>(2*n-i))
            {
                cout<<(2*n)-j+1;
               
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void letters()
{
    int n;
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        char a = 'A'+(n-i);
        for(int j=0;j<=i;j++)
        {
            cout<<a++<<" ";
        }
        cout<<endl;
    }
}

void diamond(int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=(2*n);j++)
        {
            if(j<(n-i))
            {
                cout<<'*';
            }
            else if(j>(n+i))
            {
                cout<<'*';
            }
            else 
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++)
       {
        for(int j=0;j<=(2*n);j++)
        {
            if(j<=i)
            {
                cout<<'*';
            }
            else if(j>=(2*n-i))
            {
                cout<<'*';
               
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
       }

}

void damaru(int n)
{
    for(int i=0;i<n;i++)
       {
        for(int j=0;j<=(2*n);j++)
        {
            if(j<=i)
            {
                cout<<'*';
            }
            else if(j>=(2*n-i))
            {
                cout<<'*';
               
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
       }

       for(int i=1;i<n;i++)
    {
        for(int j=0;j<=(2*n);j++)
        {
            if(j<(n-i))
            {
                cout<<'*';
            }
            else if(j>(n+i))
            {
                cout<<'*';
            }
            else 
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    damaru(n);
}