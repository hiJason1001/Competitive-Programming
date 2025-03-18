#include <bits/stdc++.h>
using namespace std;


int main () {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> road(n);
    vector<pair<int, int>> driver(m);
    for (int i = 0; i < n; i++) {
        cin >> road[i].first >> road[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> driver[i].first >> driver[i].second;
        driver[i].second = min(driver[i].second, 100);
    }

    // int j = 0;
    // int prevSpeed = road[0].second;
    // int roadDist = 0;
    // int driverDist = 0;
    // int res = 0;
    // for (int i = 0; i < m; i++) {
    //     auto [dist, speed] = driver[i];
    //     res = max(res, speed - prevSpeed);

    //     while (j < n && roadDist < driverDist + dist) {
    //         res = max(res, speed - prevSpeed);
    //         roadDist += road[j].first;
    //         prevSpeed = road[j].second;
    //         j++;
    //     }

    //     driverDist += dist;
    //     // cout<<roadDist<<" "<<driverDist<<" "<<prevSpeed<<endl;
    // }

    int roadIdx = 0, bessieIdx = 0;
    int roadPos = 0, bessiePos = 0;
    int res = 0;

    while (roadIdx < n && bessieIdx < m) {
        int roadLimit = road[roadIdx].second;
        int bessieSpeed = driver[bessieIdx].second;

        int roadRemain = road[roadIdx].first - roadPos;
        int bessieRemain = driver[bessieIdx].first - bessiePos;

        res = max(res, bessieSpeed - roadLimit);

        if (roadRemain < bessieRemain) {
            bessiePos += roadRemain;
            roadIdx++;
            roadPos = 0;
        } else if (roadRemain > bessieRemain) {
            roadPos += bessieRemain;
            bessieIdx++;
            bessiePos = 0;
        } else {
            roadIdx++;
            bessieIdx++;
            roadPos = 0;
            bessiePos = 0;
        }
    }

    cout << res << '\n';
}