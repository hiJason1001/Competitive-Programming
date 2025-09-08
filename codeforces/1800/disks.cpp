#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

// C++ program for Union by Size with Path Compression
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    std::vector<int> parent, rank, size;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
            size[rootX] += size[rootY];
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

void solve() {
	int n; cin >> n;
	vector<array<int, 3>> nums(n);
	for (auto& i : nums) {
		cin >> i[0] >> i[1] >> i[2];
	}

	UnionFind uf(n);
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto [x1, y1, r1] = nums[i];
			auto [x2, y2, r2] = nums[j];
			double lenx = abs(x1 - x2);
			double leny = abs(y1 - y2);
			double dist = sqrt(lenx * lenx + leny * leny);
			if (abs(dist - (r1 + r2)) < 1e-9) {
				uf.unite(i, j);
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	unordered_map<int, vector<int>> comps;
	for (int i = 0; i < n; i++) {
		comps[uf.find(i)].push_back(i);
	}
	
	auto isBipartite = [&](vector<int>& nodes) -> bool {
		vector<int> colour(n, -1);
		colour[nodes[0]] = 0;
		deque<int> q{nodes[0]};
		while (!q.empty()) {
			int node = q.front();
			q.pop_front();
			for (int neigh : graph[node]) {
				if (colour[neigh] == -1) {
					colour[neigh] = 1 - colour[node];
					q.push_back(neigh);
				} else if (colour[node] == colour[neigh]) {
					return false;
				}
			}
		}

		int A = 0, B = 0;
		for (int i = 0; i < n; i++) {
			if (colour[i] == 0) {
				A++;
			} else if (colour[i] == 1) {
				B++;
			}
		}
		return abs(A - B) > 0;
	};

	for (auto& [rep, nodes] : comps) {
		if (isBipartite(nodes)) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}


int main () {
	ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();
}
