#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i>j); }


int ncr1(int n, int r)
{
	int dp[51];
	dp[0]=1;
	dp[1]=1;
	for (int i = 2; i < 51; ++i)
	{
		dp[i]=dp[i-1]*i;
	}
	return dp[n]/(dp[n-r] * dp[r]);
}


int triangles(vector<int> a, int np, int parallel, int p)
{
    //cout<<np<<" "<<parallel<<" "<<p<<endl;
	if(np < 3) 
		return 0;
	int i=1;
	int ans=0; 
	//cout<<a.size()<<endl;
	int n = a.size();
	for(int j=0;j<n;j++,i++) 
	{
		int remain_np = n-i;
		//cout<<"---"<<remain_np<<endl;
		//cout<<"ans"<<ans<<endl;
		if(remain_np >= 2) {
			ans+=ncr1(remain_np,2)*a[j];
			if(p>0 && parallel>0) 
			    ans+= (parallel-(a[j])-(p-i))*a[j];
		}else {
			break;
		}
		parallel-=a[j];
	}
	return ans;
}

int main() 
{
	int n;
	cin>>n;
	vector<int > a;
	int count[180]={0};
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		char ch;
		if(i<n-1)
			cin>>ch;
		count[x-(-89)]++;// -89<=angle<=90
	}

	int p=0,parallel=0, non_parallel=0;
	for ( int i = 0; i < 180; ++i)
	{
		if(count[i]>0)
		{
			a.push_back(count[i]);
			non_parallel++;
		}
		if(count[i] > 1) {
			p++;
			parallel+=count[i];
		}
	}
	sort(a.begin(),a.end(), myfunction);
	int res = triangles(a, non_parallel,parallel,p);
	cout<<res;
	return 0;
}