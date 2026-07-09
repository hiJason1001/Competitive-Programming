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



/*
Segment Tree (sum)
*/
class SegTree {
private:
    ll n;
    vector<ll> st;
    vector<ll> lazy;

public:
    SegTree(ll n) : n(n), st(4 * n), lazy(4 * n) {}

    void propagate(ll l, ll r, ll i) {
        if (lazy[i] != 0) {
            st[i] += (r - l + 1) * lazy[i];
            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void update(ll l, ll r, ll i, ll left, ll right, ll val) {
        propagate(l, r, i);
        if (left <= l && right >= r) {
            lazy[i] += val;
            propagate(l, r, i);
            return;
        } else if (left > r || right < l) {
            return;
        }
        ll mid = l + (r - l) / 2;
        update(l, mid, 2 * i + 1, left, right, val);
        update(mid + 1, r, 2 * i + 2, left, right, val);
        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }

    ll query(ll l, ll r, ll i, ll left, ll right) {
        propagate(l, r, i);
        if (left <= l && right >= r) {
            return st[i];
        } else if (left > r || right < l) {
            return 0;
        }
        ll mid = l + (r - l) / 2;
        return query(l, mid, 2 * i + 1, left, right) + query(mid + 1, r, 2 * i + 2, left, right);
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
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


/*
Union Find
*/
class UnionFind {
public:
    UnionFind(int size) : root(size), rank(size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = root[rootX];
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = root[rootY];
            } else {
                root[rootY] = root[rootX];
                rank[rootX] += 1;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
private:
    vector<int> root;
    vector<int> rank;
};


/*
Binary Lifting
*/
class BinLift {
private:
    int n, l;
    vector<vector<int>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

public:
    BinLift(int n, vector<vector<int>>& graph) : n(n), adj(graph) {}

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    void preprocess(int root) {
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }
};






























