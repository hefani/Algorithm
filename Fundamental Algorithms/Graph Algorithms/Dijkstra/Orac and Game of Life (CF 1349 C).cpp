#include<bits/stdc++.h>
using namespace std;
bool b[2000][2000];
bool isgood[2000][2000];
int dis[4000000];
int x[5];
int y[5];
int n,m,t;
long long int N=1e9;
vector <int> v;
	
 
bool valid( int a, int b)
{
	if(a>=0 and a<n and b>=0 and b<m)
	{
		return 1;
	}
	return 0;
}
 
 
bool ok( int a, int b)
{
	if(a<0 or a>=n*m)
	{
		return 0;
	}
	if(a==b+1 and a%m==0)
	{
		return 0;
	}
	if(b==a+1 and b%m==0)
	{
		return 0;
	}
	return 1;
}
 
 
void test()
{
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<i*m+j<<" "<<dis[i*m+j]<<endl;
		}
	}
}
 
 
void bfs()
{
	int a[5];
	a[0]=-1,a[1]=1,a[2]=m,a[3]=-1*m;
	for(int i=0;i<v.size();i++)
	{
	//	cout<<v[i]<<" "<<dis[v[i]]<<endl;
		for(int j=0;j<4;j++)
		{
		//	cout<<a[j]+v[i]<<" "<<dis[a[j]+v[i]]<<" "<<dis[v[i]]+1<<" "<<ok(a[j]+v[i])<<endl;
			if(ok(a[j]+v[i],v[i])==1 and dis[v[i]]+1 < dis[a[j]+v[i]])
			{
				dis[v[i]+a[j]]=dis[v[i]]+1;
				v.push_back(v[i]+a[j]);
			}
		}
	}
}
 
 
void good()
{
	x[0]=0,x[1]=0,x[2]=1,x[3]=-1;
	y[0]=1,y[1]=-1,y[2]=0,y[3]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(valid(i+x[k],j+y[k])==1)
				{
					if(b[i][j]==b[i+x[k]][j+y[k]])
					{
						isgood[i][j]=1;
					}
				}
			}
		}
	}
}
 
 
void queries()
{
	for(int k=0;k<t;k++)
	{
		int i,j;
		long long int p;
		cin>>i>>j>>p;
		i--;
		j--;
		if(dis[i*m+j]==1e9)
		{
			cout<<b[i][j];
		}
		else if(p<=dis[i*m+j])
		{
			cout<<b[i][j];
		}
		else if((p-dis[i*m+j])%2==0)
		{
			cout<<b[i][j];
		}
		else
		{
			int help=b[i][j]+1;
			help=help%2;
			cout<<help;
		}
		cout<<endl;
	}
}
 
 
int main()
{
	cin>>n>>m>>t;
	string s[1500];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='0')
			{
				b[i][j]=0;
			}
			else
			{
				b[i][j]=1;
			}
		}
	}
	good();
	int help=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(isgood[i][j]==1)
			{
				v.push_back(i*m+j);
			}
			else
			{
				dis[i*m+j]=N;
			}
		}
	}
	bfs();
//	test();
	queries();
}