#include <bits/stdc++.h>
using namespace std;


int main () {
    array<int, 3> c;
    array<int, 3> a;
    cin >> c[0] >> a[0] >> c[1] >> a[1] >> c[2] >> a[2];

    int curr = 0;
    for (int i = 0; i < 5; i++) {
        int prev = (curr - 1 + 3) % 3;

        int cap = c[curr] - a[curr];
        int avail = a[prev];
        a[curr] += min(cap, avail);
        a[prev] -= min(cap, avail);
        
        curr = (curr + 1) % 3;
    }

    cout << a[0] << '\n' << a[1] << '\n' << a[2] << '\n';
}