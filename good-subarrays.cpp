#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
	int t; cin >> t;
	for (int _ = 0; _ < t; _++) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> prefix{0};
		for (char c : s) {
			prefix.push_back(prefix.back() + (c - '0'));
		}
		// for (auto it : prefix)cout<<it<<" ";cout<<endl;

		ll res = 0;
		unordered_map<ll, ll> freq;
		for (int i = 0; i < n; i++) {
			freq[prefix[i] - i]++;
			int r = i + 1;
			ll a = prefix[r] - r;
			res += freq[a];
			// cout<<i<<" "<<s[i]<<" "<<a<<" "<<res<<endl;
		}
		cout<<res<<'\n';
	}
}
