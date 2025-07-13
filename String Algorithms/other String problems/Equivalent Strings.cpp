#include<bits/stdc++.h>
using namespace std;
string a,b;
int help;
bool check(int a1, int a2 , int b1, int b2)
{
	string A,B;
	int mida=(a1+a2)/2;
	int midb=(b1+b2)/2;
	for(int i=a1 ; i<a2 ; i++)
		A+=a[i];
		
	for(int i=b1 ; i<b2 ; i++)
		B+=b[i];
		
	if(A==B)
	{
		return true;		
	}
	else if ((a2-a1)%2==1 or (b2-b1)%2==1)
	{
		return false;
	}
	else if(a2-a1<2 or b2-b1<2) 
		return false;  
	else
	{
	//	cout<<"a1=="<<a1<<"  a2=="<<a2<<" mida=="<< mida<<endl<<"b1=="<<b1<<"  b2=="<<b2<<"  midb=="<<midb<<endl;
		if(check(a1,mida,b1,midb)==1 and check(mida,a2,midb,b2)==1  )
		{
			return true;
		}
		
		if(check(mida,a2,b1,midb)==1 and check(a1,mida,midb,b2)==1  )
		{
			return true;		
		}		
	}
	return false;
}
int main()
{
	cin>>a>>b; 
	if(a.size()!=b.size())
	{
		cout<<"NO";
		return 0;
	}
	if(check(0,a.size(),0,b.size()) ) 
		cout<<"YES";
	else
		cout<<"NO";	
}