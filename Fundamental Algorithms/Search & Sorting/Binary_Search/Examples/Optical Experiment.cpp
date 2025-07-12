// lalalalai lalai lalalailai hala lalailalai lalalailai
#include<bits/stdc++.h> 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second 
 
const int maxn = 1e5 + 1000;
const int maxn2 = 2e5 + 1000;
const int maxn5 = 5e5 + 1000;
const int N = 1e6 + 1000;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int lg = 24;
 
int n, a[N], b[N], c[N], ans[N];
 
int find_lis() {
	vector<int> dp;
	for (int i = n - 1; i >= 0; i--) {
		int p = lower_bound(dp.begin(), dp.end(), ans[i]) - dp.begin();
		if (p == dp.size()) 
			dp.push_back(ans[i]);
		else 
			dp[p] = ans[i];
	}
	return dp.size();
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++){
		cin >> b[i];
		c[b[i] - 1] = i;
	}
	for (int i = 0; i < n; i++) 
		ans[i] = c[a[i] - 1];
	cout << find_lis();
}