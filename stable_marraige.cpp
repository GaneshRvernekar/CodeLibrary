#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a,
		 pair<int, int> &b)
{
	return a.second < b.second;
}

bool check(vector<bool> &male_committed)
{
	for (int i = 0; i < male_committed.size(); i++)
	{
		if (!male_committed[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{

	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<vector<int>> male;
		vector<vector<int>> female;

		vector<int> vec2;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			vec2.clear();
			for (int j = 0; j < n; j++)
			{
				cin >> a;
				vec2.push_back(a);
			}
			female.push_back(vec2);
		}

		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			vec2.clear();
			for (int j = 0; j < n; j++)
			{
				cin >> a;
				vec2.push_back(a);
			}
			male.push_back(vec2);
		}

		vector<bool> committed(n, false);
		vector<bool> male_committed(n, false);

		int i = 0;
		map<int, int> setup;

		while (check(male_committed) == false)
		{
			if (male_committed[i] == false)
			{
				for (int j = 0; j < n; j++)
				{
					if (committed[male[i][j] - 1] == false)
					{
						committed[male[i][j] - 1] = true;
						setup[male[i][j] - 1] = i + 1;
						male_committed[i] = true;
						break;
					}
					else
					{
						int already = setup[male[i][j] - 1];
						int now = i + 1;
						for (int k = 0; k < n; k++)
						{
							if (female[male[i][j] - 1][k] == now)
							{
								setup[male[i][j] - 1] = i + 1;
								male_committed[i] = true;
								male_committed[already] = false;
								cout << "seems new actually :" << male[i][j] << "->" << i + 1 << endl;
							}
							else if (female[male[i][j] - 1][k] == already)
							{
								break;
							}
						}
					}
				}
			}

			i = ((i + 1) % n);
		}

		vector<pair<int, int>> A;

		// Copy key-value pair from Map
		// to vector of pairs
		for (auto &it : setup)
		{
			A.push_back(it);
		}

		// Sort using comparator function
		sort(A.begin(), A.end(), cmp);

		// Print the sorted value
		for (auto &it : A)
		{
			cout << it.second << " " << it.first + 1 << endl;
		}
	}
	return 0;
}
