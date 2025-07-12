#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

void input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void heapify(int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(n, largest);
	}
}

void heap_sort(int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(i, 0);
	}
}

int main() {
	int n;
	cin >> n;
	input(n);
	heap_sort(n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}