#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

void solve() {

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}




class SegTree {
private:
    ll n;
    vector<ll> st;
    vector<ll> lazy;

public:
    SegTree(ll n) : n(n), st(4 * n), lazy(4 * n) {}

    void propagate(ll l, ll r, ll i) {
        if (lazy[i] != 0) {
            st[i] = lazy[i];
            if (l != r) {
                lazy[2 * i + 1] = lazy[i];
                lazy[2 * i + 2] = lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void update(ll l, ll r, ll i, ll left, ll right, ll val) {
        propagate(l, r, i);
        if (left <= l && right >= r) {
            lazy[i] = val;
            st[i] = val;
            return;
        } else if (left > r || right < l) {
            return;
        }
        ll mid = l + (r - l) / 2;
        update(l, mid, 2 * i + 1, left, right, val);
        update(mid + 1, r, 2 * i + 2, left, right, val);
        st[i] = max(st[2 * i + 1], st[2 * i + 2]);
    }

    ll query(ll l, ll r, ll i, ll left, ll right) {
        propagate(l, r, i);
        if (left <= l && right >= r) {
            return st[i];
        } else if (left > r || right < l) {
            return 0;
        }
        ll mid = l + (r - l) / 2;
        return max(query(l, mid, 2 * i + 1, left, right),
                   query(mid + 1, r, 2 * i + 2, left, right));
    }
};



/*

Binary Trie

*/

class Trie {
private:
    
    struct Node {
        array<Node*, 2> child;
        int count;
        Node() : child({nullptr, nullptr}), count(0) {}
    };

    Node* root;

public:
    
    Trie() : root(new Node()) {}

    void insert(int num) {
        Node* node = root;
        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            if (!node->child[b]) 
                node->child[b] = new Node();
            node = node->child[b];
            node->count++;
        }
    }

    void remove(int num) {
        Node* node = root;
        for (int bit = 31; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            node = node->child[b];
            node->count--;
        }
    }
};



/*

Fraction and fraction hash

*/

struct Frac {
    ll numer;
    ll denom;
    
    Frac(ll num, ll den = 1) : numer(num), denom(1) {
        if (den == 0) throw runtime_error("denominator is zero???");
        ll g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        numer = num;
        denom = den;
    }
    
    Frac operator+(const Frac& f) const {
        return Frac(numer * f.denom + f.numer * denom, denom * f.denom);
    }

    Frac operator-(const Frac& f) const {
        return Frac(numer * f.denom - f.numer * denom, denom * f.denom);
    }

    Frac operator*(const Frac& f) const {
        return Frac(numer * f.numer, denom * f.denom);
    }

    Frac operator/(const Frac& f) const {
        if (f.numer == 0) throw runtime_error("division by zero???");
        return Frac(numer * f.denom, denom * f.numer);
    }

    Frac& operator+=(const Frac& f) {
        return *this = *this + f;
    }

    Frac& operator-=(const Frac& f) {
        return *this = *this - f;
    }

    Frac& operator*=(const Frac& f) {
        return *this = *this * f;
    }

    Frac& operator/=(const Frac& f) {
        return *this = *this / f;
    }

    bool operator==(const Frac& f) const {
        return numer == f.numer && denom == f.denom;
    }

    friend ostream& operator<<(ostream& os, const Frac& f) {
        return os << f.numer << "/" << f.denom;
    }
};

struct FracHash {
    size_t operator()(const Frac& f) const {
        size_t h1 = hash<ll>()(f.numer);
        size_t h2 = hash<ll>()(f.denom);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

/*

binary exponentiation

*/

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}









