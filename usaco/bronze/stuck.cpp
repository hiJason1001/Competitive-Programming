#include <bits/stdc++.h>
using namespace std;

struct Cow {
	int x, y;
	int ind;
};

int main () {
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<Cow> n_cows;
	vector<Cow> e_cows;

	for (int i = 0; i < n; i++) {
		char dir;
		int x, y;
		cin >> dir >> x >> y;
		if (dir == 'N') {
			n_cows.push_back({x, y, i});
		} else if (dir == 'E') {
			e_cows.push_back({x, y, i});
		}
	}

	sort(n_cows.begin(), n_cows.end(),
	     [&](const Cow &c1, const Cow &c2) { return c1.x < c2.x; });
	sort(e_cows.begin(), e_cows.end(),
	     [&](const Cow &c1, const Cow &c2) { return c1.y < c2.y; });

    vector<int> stop(n, INT_MAX);
    for (int i = 0; i < n_cows.size(); i++) {
        int x = n_cows[i].x;
        int y = n_cows[i].y;
        int ID = n_cows[i].ind;
        for (int j = 0; j < e_cows.size(); j++) {
            int xj = e_cows[j].x;
            int yj = e_cows[j].y;
            int IDj = e_cows[j].ind;
            // i'th cow going north
            // j'th cow going east
            if (x > xj && y < yj) { 
                int interX = x;
                int interY = yj;
                int iDist = interY - y;
                int jDist = interX - xj;
                // cout<<x<<" "<<y<<" "<<xj<<" "<<yj<<" "<<iDist<<" "<<jDist<<endl;
                // cout<<((stop.count(IDj) && xj + stop[IDj] < x))<<endl;

                if (iDist < jDist) { // east cow is stopped
                    if (stop[IDj] != INT_MAX) { // east cow already stopped
                        continue;
                    }

                    stop[IDj] = jDist;

                } else if (jDist < iDist && stop[IDj] == INT_MAX) { // north cow is stopped
                    stop[ID] = iDist;
                    break;
                }

            } 
        }
    }


    for (int i = 0; i < n; i++) {
        cout << ((stop[i] == INT_MAX) ? "Infinity" : to_string(stop[i])) << '\n';
    }
}