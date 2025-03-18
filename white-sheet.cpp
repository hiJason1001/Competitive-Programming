#include <bits/stdc++.h>
using namespace std;

struct Rec {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main () {
    Rec w, b1, b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    auto allCornersCovered = [&]() -> bool {
        return ((b1.x1 <= w.x1 && b1.x2 >= w.x1 && b1.y1 <= w.y1 && b1.y2 >= w.y1) ||
                (b2.x1 <= w.x1 && b2.x2 >= w.x1 && b2.y1 <= w.y1 && b2.y2 >= w.y1)) &&
                ((b1.x1 <= w.x2 && b1.x2 >= w.x2 && b1.y1 <= w.y2 && b1.y2 >= w.y2) ||
                (b2.x1 <= w.x2 && b2.x2 >= w.x2 && b2.y1 <= w.y2 && b2.y2 >= w.y2)) &&
                ((b1.x1 <= w.x1 && b1.x2 >= w.x1 && b1.y1 <= w.y2 && b1.y2 >= w.y2) ||
                (b2.x1 <= w.x1 && b2.x2 >= w.x1 && b2.y1 <= w.y2 && b2.y2 >= w.y2)) &&
                ((b1.x1 <= w.x2 && b1.x2 >= w.x2 && b1.y1 <= w.y1 && b1.y2 >= w.y1) ||
                (b2.x1 <= w.x2 && b2.x2 >= w.x2 && b2.y1 <= w.y1 && b2.y2 >= w.y1));
    };

    auto fullyCovered = [&]() -> bool {
        return (b1.x1 <= w.x1 && b1.x2 >= w.x2 && b1.y1 <= w.y1 && b1.y2 >= w.y2) ||
               (b2.x1 <= w.x1 && b2.x2 >= w.x2 && b2.y1 <= w.y1 && b2.y2 >= w.y2);
    };

    if (!allCornersCovered()) {
        cout<<"YES\n"; return 0;
    }

    if (fullyCovered()) {
        cout<<"No\n"; return 0;
    }

    if (b1.x1 <= w.x1 && b1.x2 >= w.x2 && b2.x1 <= w.x1 && b2.x2 >= w.x2) {
        if (b1.y1 > b2.y1 && b2.y2 < b1.y1) { // b2 is bottom
            cout<<"YES\n"; return 0;
        } else if (b1.y1 <= b2.y1 && b1.y2 < b2.y1) { // b1 is bottom
            cout<<"YES\n"; return 0;
        }
    }

    if (b1.y1 <= w.y1 && b1.y2 >= w.y2 && b2.y1 <= w.y1 && b2.y2 >= w.y2) {
        if (b1.x1 > b2.x1 && b2.x2 < b1.x1) { // b2 is left
            cout<<"YES\n"; return 0;
        } else if (b1.x1 <= b2.x1 && b1.x2 < b2.x1) { // b1 is left
            cout<<"YES\n"; return 0;
        }
    }

    cout<<"No\n";
}
