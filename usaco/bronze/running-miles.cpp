#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums(n); for(int i= 0; i < n; i++) cin>>nums[i];

    vector<int> suffix(n);
    int maxSoFar = 0;
    for (int i = n - 2; i >= 0; i--) {
        maxSoFar = max(maxSoFar, nums[i + 1]) - 1;
        suffix[i] = maxSoFar;
    }
    int res = 0;
    maxSoFar = 0;
    for (int i = 1; i < n; i++) {
        maxSoFar = max(maxSoFar, nums[i - 1]) - 1;
        res = max(res, maxSoFar + nums[i] + suffix[i]);
    }
    cout<<res<<'\n';
}

int main () {
    int t; cin >> t;
    for (int i=0; i < t; i++)
        solve();
}
