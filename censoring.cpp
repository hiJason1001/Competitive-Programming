#include <bits/stdc++.h>
using namespace std;

bool onStack(const vector<char>& stk, string_view sv) {
    if (stk.size() < sv.size()) return false;

    int i = stk.size() - sv.size();
    for (int j = 0; j < sv.size(); j++) {
        if (stk[i] != sv[j]) return false;
        i++;
    }
    return true;
}

int main () {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    vector<char> stk;
    stk.reserve(s.size());

    int j = 0;
    for (char c : s) {
        stk.push_back(c);
        while (onStack(stk, t)) {
            for (int i = 0; i < t.size(); i++) {
                stk.pop_back();
            }
        }
    }
    
    string res;
    for (char c: stk) res += c;
    cout << res << '\n';
}