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
 
const int N = 1e6 + 500;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int lg = 20;
 
int n, f[N];
string t, ans;
 
void kmp() {
	int k = f[0] = f[1] = 0;
	for (int i = 1; i < t.size(); i++) {
		while (k > 0 && t[k] != t[i]) k = f[k];
		if (t[k] == t[i]) k++;
		f[i + 1] = k;
	}
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() >= ans.size()) {
			t = s;
			t += '#';
			t += ans;
 
		}
		else {
			t = s;
			t += '#';
			for (int j = ans.size() - s.size(); j < ans.size(); j++) 
				t += ans[j];
		}
		kmp();
	/*	for (int j = 1; j <= t.size(); j++){ 
			cout << t[j - 1] << " " << f[j] << endl;
		}*/
		int x = f[t.size()];
		for (int j = x; j < s.size(); j++)
			ans += s[j];
	}
	cout << ans;
}