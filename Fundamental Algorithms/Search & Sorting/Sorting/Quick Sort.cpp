#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
using namespace std;

const int N=1e5+20;
int a[N];

void input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int partition(int s, int e) {
	int pivot = a[e - 1];
	int i = s - 1;

	for (int j = s; j < e - 1; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[e - 1]);
	return i + 1;
}

void quick_sort(int s, int e) {
	if (e - s <= 1) 
		return;

	int p = partition(s, e);
	quick_sort(s, p);
	quick_sort(p + 1, e);
}

int main() {
	int n;
	cin >> n;
	input(n);
	quick_sort(0, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}