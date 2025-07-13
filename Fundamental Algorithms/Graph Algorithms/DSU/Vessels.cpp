#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
const int N=2e5+500;
vector<int> com[N];
int n,m,a[N],r[N],cmp[N];
ll int b[N],cap[N],sum[N];
 
void u_s(int x,int y)
{
	x=cmp[x];
	y=cmp[y];
	if(x==y) return;
	if(com[x].size()<com[y].size())
	{
		swap(x,y);
	}
	cap[x]=cap[y]+cap[x];
	sum[x]=sum[x]+sum[y];
	r[x]=max(r[x],r[y]);
	for(auto u:com[y])
	{
		com[x].push_back(u);
		cmp[u]=x;
	}
}
 
void p_w(int p,int l)
{
	p=cmp[p];
//	cout<<r[p]<<" "<<p<<" "<<cap[p]<<" "<<sum[p]<<" "<<l<<endl;
	if(cap[p]>=sum[p]+l)
	{
		b[p[r]]+=l;
		sum[p]+=l;
	}
	else
	{
		if(r[p]<n)
		{
			int help=a[r[p]]-b[r[p]];
			b[r[p]]=a[r[p]];
	//		cout<<p<<" "<<l<<endl;
			sum[p]+=help;
			u_s(r[p],r[p]+1);
			p_w(p,l-help);
		}
		else
		{
			b[r[p]]=a[r[p]];
			sum[p]=cap[p];
		}
	}
}
 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		cap[i]=a[i];
		cmp[i]=i;
		com[i].push_back(i);
		r[i]=i;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int h;
		cin>>h;
		if(h==1)
		{
			int p,l;
			cin>>p>>l;
			p_w(p,l);
		}
		else
		{
			int p;
			cin>>p;
			cout<<b[p]<<'\n';
		}
	}
}