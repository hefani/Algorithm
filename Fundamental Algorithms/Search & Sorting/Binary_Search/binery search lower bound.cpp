#include<bits/stdc++.h>
using namespace std;
int n;
int q1;
int a[100];
int q[100];

int binery(int l , int r , int h) {
	if(r==l and a[l]>=q[h]) {
		return l+1;
	}
	if(r==l and a[l]<q[h]) {
		return -1;
	}

	int mid=(r+l)/2;
	
	if(a[mid]>=q[h]) {
		return binery(l,mid,h);
	}
	else {
		return binery(mid+1,r,h);
	}
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	cin>>q1;
	for(int i=0;i<q1;i++) {
		cin>>q[i];
	}
	for(int i=0;i<q1;i++) {
		cout<<binery(0,n,i)<<" ";
	}
}
