#include <bits/stdc++.h>
using namespace std;

int start(const vector<vector<int>>& v, int x) {
    int pos = x;
    int res = 0;
    for (const auto& vec : v) {
        int g = vec[2];
        if (vec[0] == pos) {
            pos = vec[1];
        } else if (vec[1] == pos) {
            pos = vec[0];
        }

        if (pos == g) res++;
    }
    return res;
}

int main () {
    int n;
    cin >> n;

    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    cout << max({start(v, 1), start(v, 2), start(v, 3)}) << '\n';
}