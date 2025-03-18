#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<string> dna(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> dna[i];
    }
    int res = 0;
    for (int j = 0; j < m; j++) {
        unordered_set<char> seen;
        for (int i = 0; i <  n; i++) {
            seen.insert(dna[i][j]);
        }
        bool valid = true;
        for (int i = n; i < 2 * n; i++) {
            if (seen.count(dna[i][j])) {
                valid = false;
                break;
            }
        }
        if (valid) res++;
    }
    cout<<res<<'\n';
}