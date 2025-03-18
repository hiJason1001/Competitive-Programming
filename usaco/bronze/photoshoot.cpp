#include <bits/stdc++.h>
using namespace std;


int main () {
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;

    int n, ans=0;
    cin >> n;
    char str[200001];
    cin >> str;
    for (int i = n - 1; i >= 1; i -= 2) {
        if (str[i] == str[i - 1]) continue;
        if (str[i] == 'G' && ans % 2 == 1) ans++;
        if (str[i] == 'H' && ans % 2 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
