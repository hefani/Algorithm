// lalalalai lalai lalalailai hala lalailalai lalalailai
#include<bits/stdc++.h> 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second 
 
const int maxn = 1e5 + 10;
const int maxn2 = 2e5 + 10;
const int maxn3 = 3e5 + 10;
const int maxn5 = 5e5 + 10;
const int maxn6 = 5e6 + 10;
const int N = 1005;
const int INF = 1e9 + 100;
const int mod = 1e9 + 7;
const int lg = 24;
 
string s;
ll pw[maxn6], phs[3][maxn6], n, dp[maxn6], ans;
ll base = 101;
 
int get_val(char a) {
	if (a >= 'a' and a <= 'z')
		return a - 'a' + 1;
	if (a >= 'A' and a <= 'Z')
		return a - 'A' + 27;
	return a - '0' + 55;
}
 
int get_hash(int ty, int l, int r) {
	if (l > 0)
		return (phs[ty][r] + (mod - (phs[ty][l - 1] * pw[r - l + 1] % mod))) % mod;
	return phs[ty][r];
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	pw[0] = 1;
	for (int i = 1; i < maxn6; i++)
		pw[i] = pw[i - 1] * base % mod;
	cin >> s;
	n = s.size();
	phs[0][0] = get_val(s[0]);
	for (int i = 1; i < n; i++)
		phs[0][i] = (phs[0][i - 1] * base + get_val(s[i])) % mod;
	reverse(all(s));
	phs[1][0] = get_val(s[0]);
	for (int i = 1; i < n; i++)
		phs[1][i] = (phs[1][i - 1] * base + get_val(s[i])) % mod;
	dp[0] = 1;
	ans = 1;
	for (int i = 1; i < n; i++) {
		if (get_hash(0, 0, ((i - 1) / 2)) == get_hash(1, (n - i - 1), (n - (i / 2) - 2)))
			dp[i] = dp[(i - 1) / 2] + 1;
		else
			dp[i] = 0;
		ans += dp[i]; 
	}
	cout << ans << '\n';
}