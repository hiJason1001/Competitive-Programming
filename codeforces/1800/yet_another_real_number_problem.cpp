#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b % 2 == 1) res = (res * a) % MOD;
		b /= 2;
		a = (a * a) % MOD;
	}
	return res;
}

unordered_map<ll, ll> inv;
ll modinv(int b) {
	if (inv.count(b)) return inv[b];
	return inv[b] = modpow(b, MOD - 2);
}

void solve() {
	int n; cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	ll total = nums[0];
	ll prev = nums[0];
	ll res = total;
	cout<<total<<" ";
	for (int i = 1; i < n; i++) {
		total = (total + nums[i]) % MOD;
		res = max(res, total);
		ll curr = nums[i];
		ll curr_prev = curr + prev;
		while (prev > 1 && prev % 2 == 0) {
			curr = (curr * 2) % MOD;
			prev = (prev * modinv(2)) % MOD;
		}
		ll both = (curr + prev) % MOD;
		total = (total + both - curr_prev + MOD) % MOD;

		prev = curr;
		res = max(res, total);
		cout<<res<<" ";
	}
	cout<<endl;
}


int main () {
	int t = 1; 
	cin >> t;
	for (int _ = 0; _ < t; _++)
		solve();
}
