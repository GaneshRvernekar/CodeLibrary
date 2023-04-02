#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    int n = s.length(),cnt=0;
     

    for(int i=0;i<n;i++)
    {
        string temp;
        
        for(int j=i+1;j<=n;j++)
        {
            string temp =  s.substr(i,(j-i)); 
            sort(temp.begin(),temp.end());
            int len = j-i;
            
            for(int k=0;k<=(n-len);k++)
            {
                if(k!=i)
                {
                    string temp2 =s.substr(k,len);
                  sort(temp2.begin(),temp2.end());
                    if(temp2== temp)
                    {
                        
                       cnt++;
                    }
                    
                }
            }   
        }
        
    }
    cout<<cnt/2<<endl;
    return 0;
}