#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >>s ;
    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {cin>>queries[i].first; cin>>queries[i].second;}

    vector<vector<int>> prefixFreq{vector<int>(26, 0)};
    for (char c : s) {
        vector<int> freq(prefixFreq.back().begin(), prefixFreq.back().end());
        freq[c - 'a']++;
        prefixFreq.push_back(freq);
    }

    for (auto [l, r] : queries) {
        l--; r--;
        auto rr = prefixFreq[r + 1];
        auto ll = prefixFreq[l];
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (rr[i] > ll[i]) count++;
        }

        if (count > 2 || l == r || s[l] != s[r]) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
}

int main () {
    // int t; cin >> t;
    // for (int i=0; i < t; i++)
        solve();
}
