#include<bits/stdc++.h>
using namespace std;
long long int b=0,s=0,c=0;
long long int a[3];
long long  int d[3];
long long int k;
bool valid(long long int m)
{
	long long int ans=0;
	long long int help[3];
	for(int i=0;i<3;i++)
	{
		help[i]=a[i];
	}
	long long int b1=b*m;
	long long int c1=c*m;
	long long int s1=s*m;
	if(help[0]>=b1)
	{
		help[0]=0;
	}
	else
	{
		help[0]=b1-help[0];
	}
	ans+=help[0]*d[0];
	if(ans>k)
	{
		return false;
	}
	if(help[1]>=s1)
	{
		help[1]=0;
	}
	else
	{
		help[1]=s1-help[1];
	}
	ans+=help[1]*d[1];
	if(ans>k)
	{
		return false;
	}
	if(help[2]>=c1)
	{
		help[2]=0;
	}
	else
	{
		help[2]=c1-help[2];
	}
	ans+=help[2]*d[2];
	if(ans>k)
	{
		return false;
	}
	return true;
}
void binery(long long int l,long long int r)
{
	long long int mid=(l+r)/2;
	if(r-l<2)
	{
		cout<<l;
		return;
	}
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
	string s2;
	cin>>s2;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]=='b' or s2[i]=='B')
		{
			b++;
		}
		else if(s2[i]=='s' or s2[i]=='S')
		{
			s++;
		}
		else if(s2[i]=='c' or s2[i]=='C')
		{
			c++;
		}
	}
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<3;i++)
	{
		cin>>d[i];
	}
	cin>>k;
	binery(0,1000000001000);
}