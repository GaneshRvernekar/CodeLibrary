#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int m_r=-1;
int m_l=0;
int ans=1000001;

void add(int &arr[],int ele)
{
    
}

void remove(int *arr,int ele)
{
    
}

int main() {
    
    int m,n;
    scanf("%d%d",&m,&n);
    int arr[m];
    
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        arr[i]=a;
    }
    
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        
        while(m_r<r)
        {
            m_r++;
            add(arr,arr[m_r]);
        }
        
        while(m_r>r)
        {
            remove(arr,arr[m_r]);
            m_r--;
        }
        
        while(m_l<l)
        {
            remove(arr,arr[m_l]);
            m_l++;
        }
        
        while(m_l>l)
        {
            m_l--;
            add(arr,arr[m_l]);
        }
    }
    
    
   
    return 0;
}
