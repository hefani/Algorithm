#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5*2;
const int inf =1e9;
int n,m,l,cap,ans;
vector<pair<int,int>> G[N];
set<pair<int,int>> s;
int dis[N];
void dijk()
{
	for(int i=1;i<=n;i++)
	{
		if(i==cap)
		{
			pair<int,int> p={0,cap};
			s.insert(p);
			dis[cap]=0;
		}
		else
		{
			pair<int,int> p={inf,i};
			s.insert(p);
			dis[i]=inf;
		}
	}
	while(s.size()>0)
	{
		pair<int,int> aval=(*s.begin());
		int v=aval.second;
		int d=aval.first;
		s.erase(aval);
		for(int i=0;i<G[v].size();i++)
		{
			int u,w;
			pair<int,int> p;
			p=G[v][i];
			u=p.second;
			w=p.first;
			if(dis[u]>dis[v]+w)
			{
				s.erase(p);
				dis[u]=dis[v]+w;
				s.insert({dis[u],u});
			}
		}
	}
}
int main()
{
	cin>>n>>m>>cap;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[v].push_back({w,u});
		G[u].push_back({w,v});
	}
	cin>>l;
	dijk();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			pair<int,int> p=G[i][j];
			int x=p.second;
			int w=p.first;
		//	cout<<i<<" "<<x<<" "<<dis[i]<<" "<<dis[x]<<" "<<w<<'\n';
			if(dis[x]<l and dis[x]+w>l)
			{
				int y=l-dis[x];
				if(dis[i]+w-y==l)	ans++;
			}
		}
	}
	ans/=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			pair<int,int> p=G[i][j];
			int x=p.second;
			int w=p.first;
		//	cout<<i<<" "<<x<<" "<<dis[i]<<" "<<dis[x]<<" "<<w<<'\n';
			if(dis[x]<l and dis[x]+w>l)
			{
				int y=l-dis[x];
				if(dis[i]+w-y>l)
				{
					ans++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
	//	cout<<dis[i]<<" ";
		if(dis[i]==l)	ans++;
	}
	cout<<ans;
}