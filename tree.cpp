#include <bits/stdc++.h>
using namespace std;

vector<int> values;
vector<int> all_nodes;
int k,n;

void make_dfs(vector<int> adjs[],vector<int> &vis,int node,int cnt,vector<int> &track)
{
	if(cnt==(k+1))
	{
		int a = *max_element(track.begin(),track.end());
		all_nodes.push_back(a);
		return;
	}

	for(auto it:adjs[node])
	{
		if(vis[it]==false)
		{
			vis[it]=true;
			track.push_back(values[it]);
			make_dfs(adjs,vis,it,cnt+1,track);
			track.pop_back();
		}
	}
}
int main() {
	

	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		values.push_back(a);
	}

	vector<int> adjs[n];

	for(int i=0;i<n-1;i++)
	{
		int f,s;
		cin>>f>>s;
		adjs[f-1].push_back(s-1);
		adjs[s-1].push_back(f-1);
	}

	for(int i=0;i<n;i++)
	{
		vector<int> vis(n,false);
		vector<int> track;
		make_dfs(adjs,vis,i,0,track);
	}

	cout<<*min_element(all_nodes.begin(),all_nodes.end())<<endl;



}