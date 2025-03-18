#include <bits/stdc++.h>
using namespace std;

struct Rec {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main () {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        Rec t1;
        int w, h; cin >> w >> h;
        cin >> t1.x1 >> t1.y1 >> t1.x2 >> t1.y2;
        int t2x, t2y; cin >> t2x >> t2y;
    
        if (t1.x2 - t1.x1 + t2x > w && t1.y2 - t1.y1 + t2y > h) {
            cout << -1 << '\n'; continue;
        }
    
        int res = INT_MAX;
        if (t1.y2 - t1.y1 + t2y <= h) {
            res = min(res, max(0, t2y - t1.y1));
        }
        if (t1.y2 - t1.y1 + t2y <= h) {
            res = min(res, max(0, t1.y2 - (h - t2y)));
        }
        if (t1.x2 - t1.x1 + t2x <= w) {
            res = min(res, max(0, t2x - t1.x1));
        }
        if (t1.x2 - t1.x1 + t2x <= w) {
            res = min(res, max(0, t1.x2 - (w - t2x)));
        }
        if (res == INT_MAX) {
            cout<<0<<'\n';
        } else {
            cout<<res<<'\n';
        }
    }
}
