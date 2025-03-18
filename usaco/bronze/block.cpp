#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<pair<string, string>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for (int i = 0; i < 26; i++) {
        int total = 0;
        for (const auto& [s1, s2] : vec) {
            total += max(count(s1.begin(), s1.end(), i + 'a'), count(s2.begin(), s2.end(), i + 'a'));
        }
        cout<<total<<'\n';
    }
}