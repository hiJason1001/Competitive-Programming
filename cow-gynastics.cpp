#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    int n, k;
    cin >> k >> n;
    vector<vector<int>> vec(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    vector<unordered_set<int>> didBetter(n + 1);
    for (int i = 0; i < k; i++) {
        unordered_set<int> curr;
        for (int j = n - 1; j >= 0; j--) {
            int currCow = vec[i][j];
            for (int cow = 1; cow <= n; cow++) {
                if (i == 0) {
                    didBetter[currCow] = curr;
                } else if (didBetter[currCow].count(cow) && !curr.count(cow)) {
                    didBetter[currCow].erase(cow);
                }
            }
            curr.insert(vec[i][j]);
        }
    }
    int res = 0;
    for (int i = 0; i < n + 1; i++) res += didBetter[i].size();
    cout << res << '\n';
}