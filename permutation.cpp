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
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			vec.push_back(a);
		}

		for(int i=n;i>0;i--)
		{
            vector<int> ans;
			int b = (i-vec[0]);
			if(b<0)
			{
				cout<<-1<<endl;
                break;
			}
			ans.push_back(b);
			ans.push_back(n);
			for(int j=1;j<n;j++)
			{
                int num = vector.back()+vec[j];
                if((ans.begin(),ans.end(),num)!=ans.end())
                {
                    break;
                }
                if(num<1 || num>(n+1))
                {
                    break;
                }
				ans.push_back(num);
			}

            if(ans.size()==(n+1))
            {
                break;
            }
		}
	}
}
