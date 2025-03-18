#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<int>& nums, vector<int>::iterator begin, vector<int>::iterator end) {
    begin = next(begin);
    for (auto it = begin; it != end; it++) {
        if (*it < *(prev(it))) return false;
    }
    return true;
}

int main () {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> sorted(nums.begin(), nums.end());
    sort(sorted.begin(), sorted.end());
    // int bessie = 0;
    // for (int i = 1; i < n; i++) {
    //     if (nums[i] < nums[i - 1]) {
    //         int temp = nums[i - 1];
    //         nums[i - 1] = nums[i];
    //         if (isSorted(nums, nums.begin(), nums.end())) {
    //             bessie = i - 1;
    //         } else {
    //             bessie = i;
    //         }
    //         nums[i - 1] = temp;
    //         break;
    //     }
    // }

    // int correctIdx = 0;
    // for (int i = 0; i < n; i++) {
    //     if (sorted[i] == nums[bessie]) {
    //         correctIdx = i;
    //         break;
    //     }
    // }

    // int res = 0;
    // int prev = -1;
    // if (nums[bessie] == nums[correctIdx]) res--;
    // while (bessie != correctIdx) {
    //     if (prev != -1 && nums[bessie] != prev) {
    //         res++;
    //     }

    //     prev = nums[bessie];
    //     if (correctIdx > bessie) {
    //         bessie++;
    //     } else {
    //         bessie--;
    //     }
    // }
    // if (nums[bessie] != prev) res++;
    
    // cout << res << '\n';


}
