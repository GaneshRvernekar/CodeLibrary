#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,vector<int>>> structure(n);

   

    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        vector<int> vec =structure[a].second;
        vec.push_back(i);
        structure[a].second=vec;
        structure[a].first+=1;
    }

    

    


}