#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a1=0;
	int b1=0;
	int a2=0;
	int b2=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==(int)'A' and s[i-1]==(int)'B' and a1==0)
		{
			a1++;
			i++;
		}
		else if(s[i]==(int)'B' and s[i-1]==(int)'A' and b1==0 and a1>0)
		{
			b1++;
			i++;
		}
	}
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==(int)'B' and s[i-1]==(int)'A' and a2==0)
		{
			a2++;
			i++;
		}
		else if(s[i]==(int)'A' and s[i-1]==(int)'B' and b2==0 and a2>0)
		{
			b2++;
			i++;
		}
	}
	if(a1>0 and b1>0)
	{
		cout<<"YES";
	}
	else if(a2>0 and b2>0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}