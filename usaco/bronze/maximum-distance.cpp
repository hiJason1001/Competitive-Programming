#include <bits/stdc++.h>
using namespace std;

int main () {
    // freopen("blocks.in", "r", stdin);
    // freopen("blocks.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
        }
    }
    cout<<res<<'\n';
}