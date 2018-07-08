#include <iostream>
#include <algorithm>
#include <unordered_map>
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


long long int triangles(vector<int> a, int np, int parallel, int p)
{
    //cout<<np<<" "<<parallel<<" "<<p<<endl;
	if(np < 3) 
		return 0;
	int i=1;
	long long int ans=0; 
	//cout<<a.size()<<endl;
	for(int j=0;j<a.size();j++,i++) 
	{
		int remain_np = a.size()-i;
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
	unordered_map<int, int> hm;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		char ch;
		if(i<n-1)
			cin>>ch;
		if(hm.find(x)!=hm.end()) {
			hm[x]++;
		} else {
			hm.emplace(x,1);
		}
	}

	unordered_map<int, int > :: iterator it;
	int p=0,parallel=0, non_parallel=0;
	for ( it = hm.begin(); it!= hm.end(); it++)
	{
		a.push_back(it->second);
		if(it->second > 1) {
			p++;
			parallel+=it->second;
		}
		non_parallel++;
	}
	sort(a.begin(),a.end(), myfunction);
	long long int res = triangles(a, non_parallel,parallel,p);
	cout<<res;
	return 0;
}