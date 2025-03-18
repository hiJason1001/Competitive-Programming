#include <bits/stdc++.h>
using namespace std;

bool allEmpty(const vector<unordered_set<string>>& v) {
    for (auto& s : v) {
        if (!s.empty()) return false;
    }
    return true;
}

int main () {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    int n;
    cin >> n;
    vector<unordered_set<string>> cows;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        unordered_set<string> curr(k);
        for (int j = 0; j < k; j++) {
            string s;
            cin>>s;
            curr.insert(s);
        }
        cows.push_back(curr);
    }

    
    while (!allEmpty(cows)) {
        for (int currCow = 0; currCow < n; currCow++) {
            unordered_set<string> updateCow = cows[currCow];
            // for(auto s : cows[currCow]) cout<<s<<" ";cout<<endl;
            
            for (auto& currTrait : cows[currCow]) {
                bool currTraitFound = false;
                for (int otherCow = 0; otherCow < n; otherCow++) {
                    if (currCow == otherCow) continue;
                    for (const string& otherTrait : cows[otherCow]) {
                        if (currTrait == otherTrait) {
                            currTraitFound = true;
                            break;
                        }
                    }
                    if (currTraitFound) break;
                }
                if (!currTraitFound) {
                    updateCow.erase(currTrait);
                }
            }
            
            cows[currCow] = updateCow;
            // for(auto s : cows[currCow]) cout<<s<<" ";cout<<endl;
        }
        // for (int currCow = 0; currCow < n; currCow++) {for(auto s : cows[currCow]) cout<<s<<" ";cout<<endl;}
        
        bool nothingHappened = true;
        for (int currCow = 0; currCow < n; currCow++) {
            if (cows[currCow].empty()) continue;
            unordered_set<int> toRemove{currCow};

            vector<string> currTrait(cows[currCow].begin(), cows[currCow].end());
            sort(currTrait.begin(), currTrait.end());
            for (int otherCow = 0; otherCow < n; otherCow++) {
                if (cows[otherCow].empty() || currCow == otherCow) continue;

                vector<string> otherTrait(cows[otherCow].begin(), cows[otherCow].end());
                sort(otherTrait.begin(), otherTrait.end());
                if (currTrait == otherTrait) {
                    toRemove.insert(otherCow);
                    nothingHappened = false;
                }
            }
            if (toRemove.size() >= 2) {
                for (int idx : toRemove) cows[idx].clear();
            }
        }
        if (nothingHappened && !allEmpty(cows)) {
            cout<<"no\n";
            return 0;
        }
        // for (int currCow = 0; currCow < n; currCow++) {
        //     for (auto s : cows[currCow]) cout<<s<<" ";cout<<endl;
        // }
    }
    cout<<"yes\n";
}
