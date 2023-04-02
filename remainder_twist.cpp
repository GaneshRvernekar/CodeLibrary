#include <iostream>
using namespace std;


bool remainder_count(long long num,long long r,long long num2)
{
	int cnt=0;

    long long val = num-num2;

    long long total = val * (val+1)/2;
    
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=num;j++)
		{
			if(((i%j) >= num2))
			{
				cnt++;
			}
		}
	}

	if(cnt>=r)
	{
		return true;
	}
	else
	{
		return false;
	}

}
int main() {

	string ans;
	cin>>ans;

	for(int i=0;i<ans.length();i++)
	{
		if(i==2)
		{
		ans.erase(i,1);
		cout<<ans[i]<<" "<<i<<endl;
		}
	}
	
	// int t;
	// cin>>t;

	// while(t--)
	// {
	// 	long long n,r;
	// 	cin>>n>>r;
	// 	long long l=1,h=n;
	// 	int ans=-1;

    //     // remainder_count(n,r,3);

	// 	while(l<=h)
	// 	{
	// 		long long mid =(l+h)/2;
	// 		if(remainder_count(n,r,mid))
	// 		{
	// 			l=mid+1;
	// 			ans=mid;
	// 		}
	// 		else
	// 		{
	// 			h=mid-1;
	// 		}
	// 	}

	// 	cout<<ans<<endl;		
	// }
}