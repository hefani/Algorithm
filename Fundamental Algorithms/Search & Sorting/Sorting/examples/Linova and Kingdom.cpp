#include<bits/stdc++.h>
using namespace std;
vector <int> e[200005];
vector <int> v;
bool check[200005];
int dis[200005];
long long int ans; 
int b[200005];
int mkh[200005];
int n,k;
 
 
 
void bfs(int s)
{
	v.push_back(s);
	check[s]=1;
	dis[s]=0;
	for(int i=0 ; i < v.size() ; i++)
	{
		for(int j=0 ; j < e[v[i]].size() ; j++)
		{
			if(check [ e[v[i]][j]] == 0)
			{
				v.push_back( e [v[i]][j]);
				check [ e [v[i]][j] ] = 1;
				dis[ e [v[i]][j] ] = dis [v[i]] + 1;
			}
		}
	}
}
 
 
 
void baby()
{
	for(int i=v.size()-1 ; i>0 ; i--)
	{
		for(int j=0 ; j < e[v[i]].size() ; j++)
		{
			b[v[i]] += b[e[v[i]][j]] + 1 ;
		}
		b[v[i]]--;
	}
	b[1]=n-1;
}
 
 
 
int main()
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	bfs(1);
	baby();
	for(int i = v.size() ; i>=0 ; i--)
	{
		mkh[i] = dis[i] - b[i] ;
	}
	sort(mkh+1 , mkh+n+1);
	for(int i=n ; i>n-k ;i--)
	{
		ans+=mkh[i];
	}
	cout<<ans;
}