#include<bits/stdc++.h>
using namespace std;
const int N=2*100000;
int n,m;
vector <pair<int,int>> G[N];
set<pair<long long int,int>> s;
long long int dis[N];
long long int inf=1e12;
int change[N];
void dijk()
{
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			pair<long long int,int> p={0,1};
			s.insert(p);
			dis[1]=0;
		}
		else
		{
			pair<long long int,int> p={inf,i};
			s.insert(p);
			dis[i]=inf;
		}
	}
	while(s.size()>0)
	{
		pair<long long int,int> aval=(*s.begin());
		int u=aval.second;
		int d=aval.first;
		s.erase(aval);
		for(int i=0;i<G[u].size();i++)
		{
			long long int v,w;
			pair<long long int,int> p2;
			p2=G[u][i];
			v=p2.first;
			w=p2.second;
			if(dis[v]>dis[u]+w)
			{
				s.erase(p2);
				s.insert({dis[u]+w , v});
				dis[v]=dis[u]+w;
				change[v]=u;
			}
		}
	}
}
 
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	dijk();
	/*for(int i=1;i<=n;i++)
	{
		cout<<dis[i]<<" ";
	}*/
	vector<int>v;
	int help=n;
	v.push_back(n);
	if(change[n]==0)
	{
		cout<<-1;
		return 0;
	}
	while(help>1)
	{
		v.push_back(change[help]);
		help=change[help];
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<" ";
	}
}