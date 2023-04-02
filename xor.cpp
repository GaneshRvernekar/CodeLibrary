#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> values(n + 1, -1);

	vector<int> adj[n + 1];

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<pair<int, int>> qu;

	qu.push({1, 0});

	values[1]=0;

	while (!qu.empty())
	{
		int val = qu.front().second;
		int node = qu.front().first;

		qu.pop();

		for (auto child : adj[node])
		{
			if (values[child]==-1)
			{
				if (val == 0)
				{
					val = node + child;
				}
				else
				{
					int sum_ = node + child;
					val = (values[node] ^ (sum_));
				}
				values[child] = val;
				qu.push({child,val});
			}
		}
	}

	
	long long sum_=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum_ ^= (values[i]^values[j]);
		}
	}

	cout<<sum_<<endl;



	return 0;
}