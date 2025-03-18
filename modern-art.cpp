#include <bits/stdc++.h>
using namespace std;


int main () {
    // freopen("art.in", "r", stdin);
    // freopen("art.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cows.push_back(p);
    }
    sort(cows.begin(), cows.end());
    if (n == 1) {
        cout<<1<<"\n";
        return EXIT_SUCCESS;
    }
    vector<int> indeg(n);

    indeg[1]++;
    indeg[n - 2]++;
    for (int i = 1; i < n - 1; i++) {
        if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]) {
            indeg[i - 1]++;
        } else {
            indeg[i + 1]++;
        }
    }
    
    cout << count_if(indeg.begin(), indeg.end(), [](int x) {
        return x == 0;
    }) << '\n';

}