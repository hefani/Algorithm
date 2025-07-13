#include<bits/stdc++.h>
using namespace std;
string s;
bool check[5010][5010];
int dp[5010][5010];
 
 
 
void checking()
{
	for(int i=1;i<=s.size();i++)
	{
		check[i][i]=1;
		if(i+1<=s.size() and s[i-1]==s[i])
		{
			check[i][i+1]=1;
		}
	}
	for(int i=2;i<s.size();i++)
	{
		for(int j=1;j<=s.size();j++)
		{
			if(i+j<=s.size() and s[i+j-1]==s[j-1] and check[j+1][i+j-1] == 1)
			{
				check[j][j+i] = 1;
		//		cout<<endl<<j<<"  "<<j+i<<endl;
			}
		}
	}
}
 
 
 
void dynamic()
{
	for(int i=1;i<=s.size();i++)
	{
		dp[i][i]=1;
	}
	for(int i=1;i<=s.size();i++)
	{
		for(int j=1;j<=s.size();j++)
		{
			if(j+i<=s.size())
			{
				dp[j][j+i] = dp[j][j+i-1] + dp[j+1][j+i] - dp[j+1][j+i-1];
				dp[j][j+i]+=check[j][j+i];
			}
			else
			{
				break;
			}
		}
	}
}
 
 
 
 
int main()
{
	cin>>s;
	checking();
//	cout<<s.size()<<" ";
	dynamic();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d ",dp[l][r]);
	}
}