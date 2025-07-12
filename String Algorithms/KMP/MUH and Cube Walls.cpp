// lalalalai lalai lalalailai hala lalai lalai lalalailai
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second 
 
const int N = 2e5 + 500;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int lg = 20;
 
int n, w, a[N], b[N], f[N], ans;
vector <int> v;
 
void kmp() {
	int k = f[0] = f[1] = 0;
	for (int i = 1; i < v.size(); i++) {
		while (k > 0 && v[k] != v[i]) k = f[k];
		if (v[k] == v[i]) k++;
		f[i + 1] = k;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < w; i++) 
		cin >> b[i];
	for (int i = 1; i < w; i++)
		v.pb(b[i] - b[i - 1]);
	v.pb(INF);
	for (int i = 1; i < n; i++) 
		v.pb(a[i] - a[i - 1]);
	kmp();
	if (w == 1) {
		cout << n;
		return 0;
	}
	for (int i = 0; i <= v.size(); i++) if (f[i] == w - 1) 
		ans++;
	cout << ans ;
}