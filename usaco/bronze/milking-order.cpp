#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> order(m);
    unordered_set<int> hasOrder;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        order[i] = num;
        hasOrder.insert(num);
    }

    vector<int> cows(n);
    for (int i = 0; i < k; i++) {
        int c, pos;
        cin >> c >> pos;
        pos--;
        cows[pos] = c;
        if (c == 1) {
            cout<<pos + 1<<'\n';
            return EXIT_SUCCESS;
        }
    }

        
    if (hasOrder.count(1)) {
        int orderIdx = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (hasOrder.count(cows[i])) {
                while (orderIdx < m && order[orderIdx] != cows[i]) {
                    while (l < n && cows[l] != 0) l++;
                    cows[l] = order[orderIdx];
                    if (cows[l] == 1) {
                        cout<<l + 1<<'\n';
                        return EXIT_SUCCESS;
                    }
                    orderIdx++;
                }
                orderIdx++;
                l = i;
            }
        }
        // for (auto num : cows) cout<<num<<" ";cout<<endl;cout<<orderIdx<<endl;
        for (; orderIdx < m; orderIdx++) {
            while (l < n && cows[l] != 0) l++;
                cows[l] = order[orderIdx];
                if (cows[l] == 1) {
                    cout<<l + 1<<'\n';
                    return EXIT_SUCCESS;
            }
        }
        return EXIT_FAILURE;
    }
    
    int orderIdx = 0;
    for (int i = 0; i < n; i++) {
        if (!hasOrder.count(cows[i])) { // only process when cows[i] has to be ordered
            continue;
        }
        
        int start = orderIdx;
        while (orderIdx < m && order[orderIdx] != cows[i]) {
            orderIdx++;
        }
        if (orderIdx == m) {
            break;
        }
        int finish = orderIdx;
        int idx = i - 1;
        for (auto j = finish - 1; j >= start; j--) {
            while (idx >= 0 && cows[idx] != 0) {
                idx--;
            }
            cows[idx] = order[j];
            hasOrder.erase(order[j]);
        }
        hasOrder.erase(order[finish]);
        orderIdx++;
    }

    // int idx = n - 1;
    // for (int i = m - 1; i >= 0; i--) {
    //     if (!hasOrder.count(order[i])) { // only process when cow isn't ordered yet
    //         continue;
    //     }
    //     while (idx > 0 && cows[idx] != 0) {
    //         idx--;
    //     }
    //     cows[idx] = order[i];
    // }
    // for (auto a : cows) cout<<a<<" ";cout<<endl;



    for (int i = 0; i < n; i++) {
        if (cows[i] == 0) {
            cout<< i + 1 << '\n';
            break;
        }
    }

}