#include<bits/stdc++.h>
using namespace std;
long long int n,k;
long long int a[100010];
long long int b[100010];
bool valid(long long int m)
{
	long long int help[100010];
	for(int i=0;i<n;i++)
	{
		help[i]=a[i];
	}
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		help[i]*=m;
		if(b[i]>=help[i])
		{
			help[i]=0;
		}
		else
		{
			help[i]=help[i]-b[i];
		}
		ans+=help[i];
		if(ans>k)
		{
			return false;
		}
	}
	return true;
}
void binery(long long int l, long long int r)
{
	if(r-l<2)
	{
		cout<<l;
		return;
	}
	long long int mid=(r+l)/2;
//	cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<endl;
	if(valid(mid))
	{
		binery(mid,r);
	}
	else
	{
		binery(l,mid);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	binery(0,10000000001);
}