#include <bits/stdc++.h>
using namespace std;



int main () {
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<tuple<int, string, int>> vec;
    for (int i = 0; i < n; i++) {
        int a, c;
        string b;
        cin >> a >> b >> c;
        vec.emplace_back(a, b, c);
    }

    sort(vec.begin(), vec.end());

    int M = 7, E = 7, B = 7;
    vector<char> currMax{'B', 'E', 'M'};
    int res = 0;
    for (const tuple<int, string, int>& t : vec) {
        int day = get<0>(t);
        string name = get<1>(t);
        int change = get<2>(t);
        
        switch (name[0]) {
            case 'M':
            M += change;
            break;
            case 'E':
            E += change;
            break;
            case 'B':
            B += change;
            break;
            default:
            break;
        }
        
        int maxVal = max({M, E, B});
        // cout << day<<" "<<name<<" "<<change<<" "<<M<<" "<<E<<" "<<B<<" "<<maxVal<<endl;
        vector<char> curr;
        if (B == maxVal) {
            curr.push_back('B');
        }
        if (E == maxVal) {
            curr.push_back('E');
        }
        if (M == maxVal) {
            curr.push_back('M');
        }

        if (currMax != curr) {
            res++;
        }
        currMax = curr;
    }

    cout << res << '\n';
}