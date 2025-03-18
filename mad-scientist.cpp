#include <bits/stdc++.h>
using namespace std;


int main () {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;

    int seq = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            if (i > 0 && A[i - 1] != B[i - 1]) {
                continue;
            }
            seq++;
        }
    }   

    cout << seq << '\n';
}