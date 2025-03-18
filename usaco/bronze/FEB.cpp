#include <bits/stdc++.h>
using namespace std;


int main () {
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<unordered_set<int>> possiblities;
    int start = 0;
    while (start < n && s[start] == 'F') {
        start++;
    }
    unordered_set<int> uset;
    for (int i = 0; i <= start; i++) {
        uset.insert(i);
    }
    if (start > 0) {
        possiblities.push_back(uset);
    }
    if (start == n) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) cout << i << '\n';
        return EXIT_SUCCESS;
    }
    int l = start;
    int guarenteed = 0;
    int fCount = 0;
    char prev = s[start];
    unordered_set<int> curr;
    for (int r = start + 1; r < n; r++) {
        if (r == n - 1 && s[r] == 'F') {
            fCount++;
            for (int i = 0; i <= fCount; i++) {
                curr.insert(i);
            }
            possiblities.push_back(curr);
        
        } else if (s[r] == 'F') {
            fCount++;
        } else if (prev == 'F') {
            curr.clear();
            if (s[l] != s[r]) {
                for (int i = fCount; i >= 0; i -= 2) {
                    curr.insert(i);
                }
            } else {
                for (int i = fCount + 1; i >= 0; i -= 2) {
                    curr.insert(i);
                }
            }
            possiblities.push_back(curr);
            curr.clear();
            l = r;
            fCount = 0;
            
        } else if (s[r] == prev) {
            guarenteed++;
            l = r;
        } else {
            l = r;
        }
        prev = s[r];
    }


    int minval = guarenteed;
    int maxval = guarenteed;
    for (int i = 0; i < possiblities.size(); i++) {
        minval += *min_element(possiblities[i].begin(), possiblities[i].end());
        maxval += *max_element(possiblities[i].begin(), possiblities[i].end());
    }
    
    if (s[0] == 'F' || s[n - 1] == 'F') {
        cout << maxval - minval + 1 << '\n';
        for (int i = minval; i <= maxval; i++) {
            cout << i << '\n';
        }
    } else {
        cout << (maxval - minval) / 2 + 1 << '\n';
        for (int i = minval; i <= maxval; i += 2) {
            cout << i << '\n';
        }
    }


}
