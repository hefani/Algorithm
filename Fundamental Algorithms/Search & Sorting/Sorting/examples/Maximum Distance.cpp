#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=2e5+500;
vector <pair<int,pair<int,int>>> edges;
vector <pair<int,int>> G[N];
vi com[N];
bool mark[N];
bool markd[N];
int n,m,k,ans,cmp[N],special[N],dis[N];
 
void dfs(int v)
{
	markd[v]=1;
//	cout<<v<<" "<<dis[v]<<'\n';
	for(auto p:G[v])
	{
		int u=p.first;
		int w=p.second;
		if(markd[u]==1) continue;
		dis[u]=max(dis[v],w);
		dfs(u);
	}
}
 
void u_s(int a,int b)
{
	a=cmp[a];
	b=cmp[b];
	if(com[a].size()<com[b].size())
		swap(a,b);
	for(auto u:com[b])
	{
		cmp[u]=a;
		com[a].pb(u);
	}
}
 
void mst()
{
	for(int i=1;i<=n;i++)
	{
		cmp[i]=i;
		com[i].pb(i);
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		pair<int,pair<int,int>> p;
		pair<int,int>p2;
		p2.first=u;
		p2.second=v;
		p.first=w;
		p.second=p2;
		edges.pb(p);
	}
	sort(edges.begin(),edges.end());
	for(auto p:edges)
	{
		int w=p.first;
		pair<int,int> p2=p.second;
		int u=p2.first;
		int v=p2.second;
		if(cmp[u]==cmp[v]) continue;
		pair<int,int> p3;
		pair<int,int> p4;
		p3.first=v;
		p4.first=u;
		p3.second=w;
		p4.second=w;
		G[v].pb(p4);
		G[u].pb(p3);
		u_s(u,v);
	}
}
 
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<k;i++) 
	{
		int x;
		cin>>x;
		special[i]=x;
		mark[x]=1;
	}
	mst();
	dfs(special[0]);
	for(int i=1;i<k;i++)
	{
		int x=special[i];
		ans=max(ans,dis[x]);
	//	cout<<dis[i]<<" ";
	}
//	cout<<'\n';
	for(int i=0;i<k;i++) cout<<ans<<" ";
}