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
const int maxn6 = 1e6 + 10;
const int N = 5050;
const int INF = 1e9 + 100;
const int mod = 1e9 + 7;
const int lg = 24;
 
ull n, a[N], dp[N][30], sum[N], e[N][N];
ull ans;
string s;
 
void entekhab() {
	for (int i = 0; i < N; i++)
		e[i][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i and j < N; j++) {
			e[i][j] = e[i - 1][j - 1] + e[i - 1][j];
			e[i][j] = e[i][j] % mod;
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	entekhab();
	cin >> n >> s;
	for (int i = 0; i < n; i++) 
		a[i] = (int)s[i] - 97;
	dp[1][a[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int c = 0; c < 26; c++) {
				if (a[i] == c){ 
					dp[k][c] = 0;
					if (k == 1) {
						dp[k][c] = 1;
						continue;
					}
					for (int j = 0; j < 26; j++)
						dp[k][c] += dp[k - 1][j];
					dp[k][c] -= dp[k - 1][c];
					dp[k][c] = dp[k][c] % mod;
				}
			//	cout << i << " " << k << " " << c << " " << dp[k][c] << '\n';
			}
		}
	}
	for (int i = 0; i <= n; i++){
		for (int c = 0; c < 26; c++) if (dp[i][c] > 0) {
			sum[i] += dp[i][c];
			sum[i] = sum[i] % mod;
 		}
	}
	for (int i = 1; i <= n; i++) {
		ans += sum[i] * e[n - 1][i - 1];
		ans = ans % mod;
	}
	cout << ans ;
}