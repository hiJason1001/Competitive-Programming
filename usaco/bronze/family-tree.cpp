#include <bits/stdc++.h>
using namespace std;


int main () {
    // freopen("family.in", "r", stdin);
    // freopen("family.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    unordered_map<string, string> tree;
    unordered_map<string, unordered_set<string>> reverseTree;
    for (int i = 0; i < n ; i++) {
        string mother, daughter;
        cin >> mother >> daughter;
        tree[daughter] = mother;
        reverseTree[mother].insert(daughter);
    }

    string name = a;
    auto goUp = [&]() -> bool {
        int level = 1;
        while (tree.count(name)) {
            name = tree[name];
            if (name == b) {
                string message = b + " is the ";
                if (level == 1) {
                    message += "mother ";
                } else {
                    for (int i = 3; i <= level; i++) {
                        message += "great-";
                    }
                    message += "grand-mother ";
                }
                message += "of " + a;
                cout << message << '\n';
                return true;
            }
    
            for (const string& child : reverseTree[name]) {
                if (child != b) continue;
    
                if (level == 1) {
                    cout << "SIBLINGS\n";
                    return true;
                }
                string message = b + " is the ";
                for (int i = 3; i <= level; i++) {
                    message += "great-";
                }
                message += "aunt of " + a;
                cout << message << '\n';
                return true;
            }
            level++;
        }
        return false;
    };
    if (goUp()) return 0;
    swap(a, b);
    name = a;
    if (goUp()) return 0;


    deque<string> q{name};
    while (!q.empty()) {
        auto curr = q.front();
        q.pop_front();
        if (curr == b) {
            cout << "COUSINS\n";
            return 0;
        }
        for (auto neigh : reverseTree[curr]) {
            q.push_back(neigh);
        }
    }

    cout << "NOT RELATED\n";
}
