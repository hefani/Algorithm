#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int ps[1000100];
string s;
int ans;
int cnt;
stack <int> st;
int rm[1000100];
int pos[2000200];
int main()
{
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			ps[i+1]=ps[i]+1;
			a[i]=1;
		}
		else
		{
			ps[i+1]=ps[i]-1;
			a[i]=-1;
		}
		pos[ps[i+1]+n]=i+1;
	}
	for(int i=0;i<=n;i++)
	{
	//	cout<<i<<" "<<ps[i]<<endl;
	}
	for(int i=n;i>=0;i--)
	{
		while(st.size()>0 and ps[st.top()]>=ps[i])
		{
			st.pop();
		}
		if(st.size()==0)
		{
			rm[i]=n+1;
		}
		else
		{
			rm[i]=st.top();
		}
	//	cout<<i<<" "<<rm[i]<<" "<<a[i-1]<<" "<<ps[i]<<endl;
		st.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		int help;
		if(rm[i-1]<=n)
		{
			help=rm[i-1]-i;
		}
		else
		{
			help=pos[ps[i-1]+n]-i+1;
		}
		if(ans==help)
		{
			cnt++;
		}
		else if(ans<help)
		{
			cnt=1;
			ans=help;
		}
	}
	if(ans==0)
	{
		cout<<0<<" "<<1;
		return 0;
	}
	cout<<ans<<" "<<cnt;
}
