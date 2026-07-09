#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

struct SegTree {
    static constexpr ll NEG = -(1LL << 60);

    int n;
    vector<ll> st;
    vector<ll> lazyAdd;
    vector<bool> lazySet;
    vector<int> flipState; // 0: all good, 1: all flipped, 2: mixed
    vector<bool> lazyFlip;

    SegTree(int sz)
        : n(sz),
          st(4 * sz),
          lazyAdd(4 * sz),
          lazySet(4 * sz),
          flipState(4 * sz),
          lazyFlip(4 * sz) {}

    void applySet(int p) {
        st[p] = 0;
        lazySet[p] = true;
        lazyAdd[p] = 0;
    }

    void applyAdd(int p, ll x) {
        if (flipState[p] == 0)
            st[p] += x;
        if (flipState[p] != 1)
            lazyAdd[p] += x;
    }

    void push(int p) {
        if (lazySet[p]) {
            applySet(p * 2);
            applySet(p * 2 + 1);
            lazySet[p] = false;
        }

        if (lazyAdd[p] != 0) {
            applyAdd(p * 2, lazyAdd[p]);
            applyAdd(p * 2 + 1, lazyAdd[p]);
            lazyAdd[p] = 0;
        }
    }

    void pull(int p) {
        st[p] = max(st[p * 2], st[p * 2 + 1]);
    }

    void rangeAdd(int ql, int qr, ll x, int p, int l, int r) {
        if (qr < l || r < ql) return;
        if (flipState[p] == 1) return;
        if (ql <= l && r <= qr) {
            applyAdd(p, x);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        rangeAdd(ql, qr, x, p * 2, l, m);
        rangeAdd(ql, qr, x, p * 2 + 1, m + 1, r);
        pull(p);
    }

    void rangeSetZero(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            applySet(p);
            return;
        }
        push(p);
        int m = (l + r) / 2;
        rangeSetZero(ql, qr, p * 2, l, m);
        rangeSetZero(ql, qr, p * 2 + 1, m + 1, r);
        pull(p);
    }

    void rangeFlip(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            if (lazyFlip[p]) lazyFlip[p] = false;
            else {
                lazyFlip[p] = true;
                if (flipState[p] == 0) flipState[p] = 1;
                else if (flipState[p] == 1) flipState[p] = 0;
            }
            return;
        }
        if (lazyFlip[p]) {
            lazyFlip[p * 2] = !lazyFlip[p * 2];
            lazyFlip[p * 2 + 1] = !lazyFlip[p * 2 + 1];
            lazyFlip[p] = false;
        }
        int m = (l + r) / 2;
        rangeFlip(ql, qr, p * 2, l, m);
        rangeFlip(ql, qr, p * 2 + 1, m + 1, r);
        if (flipState[p * 2] == flipState[p * 2 + 1]) 
            flipState[p] = flipState[p * 2];
        else 
            flipState[p] = 2;
    }

    ll query(int ql, int qr, int p, int l, int r) {
        if (qr < l || r < ql) return NEG;
        if (ql <= l && r <= qr) return st[p];
        push(p);
        int m = (l + r) / 2;
        return max(query(ql, qr, p * 2, l, m),
                   query(ql, qr, p * 2 + 1, m + 1, r));
    }

    void rangeAdd(int l, int r, ll x) {
        rangeAdd(l, r, x, 1, 0, n - 1);
    }

    void rangeSetZero(int l, int r) {
        rangeSetZero(l, r, 1, 0, n - 1);
    }

    void rangeFlip(int l, int r) {
        rangeSetZero(l, r);
        rangeFlip(l, r, 1, 0, n - 1);
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }
};



void solve() {
    int n, q; cin >> n >> q;
    SegTree st(n + 1);
    for (int i = 0; i < q; i++) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) {
            int x; cin >> x;
            st.rangeAdd(l, r, x);
        } else if (t == 3) {
            cout<<st.query(l, r)<<endl;
        } else {
            st.rangeFlip(l, r);
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

