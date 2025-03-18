#include <bits/stdc++.h>
using namespace std;


int main () {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<int> x(n);
    for (int i= 0 ; i <n; i++) cin >> x[i];

    for (int finish : x) {
        int time = 0;
        int speed = 0;
        int dist = 0;
        int totalDist = k;
        while (dist < totalDist) {
            speed++;
            dist += speed;
            time++;
            if (speed == finish) {
                if (dist + speed + 1 >= totalDist) {
                    speed--;
                    continue;
                }

                finish++;
                totalDist -= speed;
                time++;
            }
        }
        cout<<time<<'\n';
    }

}
