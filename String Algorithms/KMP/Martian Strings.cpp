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
 
const int N = 2e5 + 1500;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int lg = 20;
 
int m, f[N], a[N], a2[N], n, ans;
string t, s;
 
void kmp() {
	int k = f[0] = f[1] = 0;
    for(int i = 1; i < t.size(); i++){
        while(k > 0 && t[k] != t[i]) k = f[k];
        if(t[k] == t[i]) k++;
        f[i + 1] = k;
    }
    return;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.size();
	cin >> m;
	for (int i = 0; i < m; i++) {
		string b; cin >> b;
		t = b;
		t += '#';
		t += s;
		for (int j = 0; j <= t.size(); j++) {
			a[j] = 0;
			a2[j] = 0;
		}
		kmp();
		for (int j = b.size() + 1; j <= t.size(); j++) {
			if (f[j] > 0 and a[f[j]] == 0) 
				a[f[j]] = j - b.size() - 1;
		}
	/*	for (int j = 1; j <= t.size(); j++) {
			cout << t[j - 1] << " " << f[j] << " " << a[f[j]] << endl;
		}
		cout << endl << endl;*/
		t.clear();
		for (int j = b.size() - 1; j >= 0; j--)
			t += b[j];
		t += '#';
		for (int j = n - 1; j >= 0; j--)
			t += s[j];
		kmp();
		for (int j = b.size() + 1; j <= t.size(); j++) {
			if (f[j] > 0 and a2[f[j]] == 0) {
				a2[f[j]] = j - b.size() - 1;
				a2[f[j]] = n - a2[f[j]];
				a2[f[j]]++;
			}
		}
		if (a[b.size()] > 0 and b.size() > 1) {
			ans++;
			continue;
		}
		/*for (int j = 1; j <= t.size(); j++) {
			cout << t[j - 1] << " " << f[j] << " " << a2[f[j]] << endl;
		}*/
		for (int j = 1; j < b.size(); j++) {
	//		cout << j << " " << a[j] << " " << a2[b.size() - j] << endl;
			if (a[j] > 0 and a2[b.size() - j] > 0 and a2[b.size() - j] > a[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans ;
}