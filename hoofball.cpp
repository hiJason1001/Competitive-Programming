#include <bits/stdc++.h>
using namespace std;


int main () {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    
    int n;
    cin >> n;
    if (n <= 3) {
        cout<<1<<"\n";
        return EXIT_SUCCESS;
    }
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cows.push_back(p);
    }
    sort(cows.begin(), cows.end());

    vector<int> graph(n);
    graph[0] = 1;
    graph[n - 1] = n - 2;
    vector<int> indeg(n);
    indeg[1]++;
    indeg[n - 2]++;

    for (int i = 1; i < n - 1; i++) {
        if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]) {
            graph[i] = i - 1;
            indeg[i - 1]++;
        } else {
            graph[i] = i + 1;
            indeg[i + 1]++;
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            res++;
        } else if (i < n - 1 && indeg[i] == 1 && indeg[i + 1] == 1 && graph[i] == i + 1 && graph[i + 1] == i) {
            res++;
        }
    }

    cout << res << '\n';

}