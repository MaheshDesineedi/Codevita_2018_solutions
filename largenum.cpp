#include <iostream>
#include<climits>
#include<string>
using namespace std;


int main() 
{
	int m,n;
	char ch;
	cin>>m;cin>>ch;
	cin>>n;
	int a[m][n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
			if(j<n-1)
				cin>>ch;
		}
	}
	int index[m];
	for(int i=0;i<m;i++)
	    index[i]=n-1;
	unsigned long long ans=0;
	string temp="";
	int local_max = INT_MIN;
	int cnt=0;
	while(1)
	{
		int j,p;
		local_max = INT_MIN;
		for ( j = 0; j < m; ++j)
		{
			int k = index[j];
			
			if( k !=-1 && local_max < a[j][k] ) {
				local_max = a[j][k];
				p=j;
			}
		}
		temp= temp+ to_string(local_max);
		index[p]--;
		if(index[p]== -1)
				cnt++;
		if(cnt==m)
			break;
	}
	cout<<temp;
	return 0;
}