#include<bits/stdc++.h>
using namespace std;
int a[1000];

void input (int n) {
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
}

void merge_sort(int s, int e) {
	if (e - s <= 1) return;

	int mid = (s + e) / 2;

	merge_sort(s, mid);
	merge_sort(mid, e);

	vector<int> temp;
	int i = s, j = mid;

	while (i < mid && j < e) {
		if (a[i] < a[j]) temp.push_back(a[i++]);
		else temp.push_back(a[j++]);
	}

	while (i < mid) temp.push_back(a[i++]);
	while (j < e) temp.push_back(a[j++]);

	for (int k = s; k < e; ++k) {
		a[k] = temp[k - s];
	}
}

int main() {
	int n;
	cin>>n;
	input (n);
	merge_sort(0,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
