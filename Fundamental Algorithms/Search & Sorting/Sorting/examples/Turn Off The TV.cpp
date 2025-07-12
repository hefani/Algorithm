// lalalalay lalay lalalaylayyyy hala lalay lalay lalalaylay
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) x.begin(),x.end()
#define fi first
#define se second 
 
const int N = 5e5;
const int INF = 1e9;
const int mod = 1e9+7;
const int lg = 25;
vector <pii> work;
vi v;
int n, ps[N], rmq[lg][N], p2[N], a[N];
 
void solve() {
	for (int i = 0; i <= 2 * n; i++) 
		rmq[0][i] = a[i];
	for (int i = 1; (1 << i) <= 2 * n; i++) {
		for (int j = 0; j + (1 << i) <= 2* n; j++) {
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		//	cout << i << " " << j << " " << rmq[i][j] << " " << rmq[i - 1][j] << " " << rmq[i - 1][j + (1 >> (i - 1))] << '\n';
		}
	}
}
 
int check(int x, int y) {
	if (x == y) return a[x];
	int d = y - x + 1;
	d = p2[d];
	int x2 = rmq[d][y - (1 << d) + 1];
	int y2 = rmq[d][x];
	//cout << d << " " << (1 << d) << " " << x2 << " " <<y2 <<endl;
	return min(x2, y2);
}
 
void t() {
	p2[1] = 0;
	for (int i = 2; i < N; i++) p2[i] = p2[(i/2)] + 1;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	t();
	for (int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		work.pb(make_pair(l, r + 1));
		v.pb(l);
		v.pb(r + 1);
	}
	sort (all (v) ) ;
	v.resize(unique(all(v)) - v.begin() ) ;
	for (int i = 0; i < n; i++) {
		work[i].fi = lower_bound (all(v), work[i].fi) - v.begin() ;
		work[i].se = lower_bound (all(v), work[i].se) - v.begin() ;
	}
	for (int i = 0; i < n; i++) {
		ps[work[i].fi]++;
		ps[work[i].se]--;
	}
	for (int  i = 0; i < lg; i++) {
		for (int  j = 0; j < N; j++) {
			rmq[i][j] = INF;
		}
	}
	int cur = 0;
	for (int i = 0; i <= 2 * n; i++) {
		cur += ps[i];
		a[i] = cur;
	}
	solve();
	for (int i = 0; i < n; i++) {
		int m = check(work[i].fi, work[i].se - 1);
	//	cout << work[i].fi << " " << work[i].se << endl;
		if (m > 1) {
			cout << i + 1 ;
			return 0;
		}
	}
	cout << -1;
}