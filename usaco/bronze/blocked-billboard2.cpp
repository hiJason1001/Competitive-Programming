#include <bits/stdc++.h>
using namespace std;

struct Rec {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    long long area() { return (x2 - x1) * (y2 - y1); }
};

int main () {
    // freopen("family.in", "r", stdin);
    // freopen("family.out", "w", stdout);

    Rec a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    // fully overlaps
    if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y1 <= a.y1 && b.y2 >= a.y2) {
        cout << 0 << '\n';
        return 0;
    }  

    // x fully overlaps, y partially
    if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y2 > a.y1 && b.y1 < a.y2) {
        // make sure b has to extend through y1 or y2
        if (b.y1 <= a.y1) {
            Rec res{ a.x1, b.y2, a.x2, a.y2 };
            cout << res.area() << '\n';
            return 0;
        } else if (b.y2 >= a.y2) {
            Rec res{ a.x1, a.y1, a.x2, b.y1 };
            cout << res.area() << '\n';
            return 0;
        }
    }

    // x partially overlaps, y fully
    if (b.y1 <= a.y1 && b.y2 >= a.y2 && b.x2 > a.x1 && b.x1 < a.x2) {
        // make sure b has to extend through x1 or x2
        if (b.x1 <= a.x1) {
            Rec res{ b.x2, a.y1, a.x2, a.y2 };
            cout << res.area() << '\n';
            return 0;
        } else if (b.x2 >= a.x2) {
            Rec res{ a.x1, a.y1, b.x1, a.y2 };
            cout << res.area() << '\n';
            return 0;
        }
    }

    cout << a.area() << '\n';
}
