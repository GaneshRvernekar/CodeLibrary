#include <bits/stdc++.h>
using namespace std;

long long dfs(long long s,long long d,vector<long long> &weight,vector<long long> &path)
{
	if(s==d)
	{
		return 0;
	}
	return weight[s]+dfs(path[s],d,weight,path);
}

int main() {
	
	int n;
	cin>>n;
	vector<long long> weight(n+1,0);
	vector<long long> path(n+1,0);
	vector<long long> moves(n+1,0);

	path[1]=-1;

	for(int i=0;i<n-1;i++)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		path[b]=a;
		weight[b]=c;
	}

	for(int i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		moves[i]=a;
	}

    for(int i=1;i<=n;i++)
    {
        cout<<moves[i]<<endl;
    }

	int q;
	cin>>q;

	while(q--)
	{
		long long s,d;
		cin>>s>>d;
		long long ans =dfs(s,d,weight,path);
		long long new_1 =moves[s]+moves[d]+ans;
		long long new_2 = ans*2;
		cout<<min(new_2,new_1)<<endl;
	}
}