#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=2e5;
vector <int> v[N];
int cmp[N],n;
 
void union_sets(int a, int b)
{
	a=cmp[a];
	b=cmp[b];
	if(v[a].size()>v[b].size())
		swap(a,b);
	for(auto u:v[a])
	{
		cmp[u]=b;
		v[b].pb(u);
	}
}
 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cmp[i]=i;
		v[i].pb(i);
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		union_sets(a,b);
	}
	int com=cmp[1];
	for(auto u:v[com])
	{
		cout<<u<<" ";
	}
}