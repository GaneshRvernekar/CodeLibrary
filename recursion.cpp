#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> vec;
		bool found=false;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			vec.push_back(a);
		}
 
		vector<int> ans;
 
		for(int i=n+1;i>0;i--)
		{
			ans.clear();
			int b = (i-vec[0]);
			if(b<=0)
			{
				continue;
			}
 
			ans.push_back(b);
			ans.push_back(i);
			for(int j=1;j<n;j++)
			{
				int num = ans.back()+vec[j];
                if(find(ans.begin(),ans.end(),num)!=ans.end())
                {
					j=n+1;
                    break;
                }
                if(num<1 || num>(n+1))
                {
					j=n+1;
                    break;
                }
				if(j<n)
				{
				ans.push_back(num);

				}
			}
 
 
			if(ans.size()==(n+1))
            {
				found=true;
                break;
            }
		}
		if(found)
		{
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}
 
 
 
 
 
