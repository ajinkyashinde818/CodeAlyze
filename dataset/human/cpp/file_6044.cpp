#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long best = 0;

    int n;
    long long c;

    cin >> n >> c;

    vector<pair<long long, long long> > values(n);
    for (int i=0; i<n; i++) {
        cin >> values[i].first >> values[i].second;
    }

    long long left[n + 1], right[n + 1];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));

    sort(values.begin(), values.end());

    vector<pair<long long, long long> > rvalues(values);
    reverse(rvalues.begin(), rvalues.end());

    for (int i=1; i <= n; i++) {
        left[i] = left[i-1] + values[i - 1].second;
    }

    for (int i=1; i <= n; i++) {
        left[i] = max(left[i] - values[i - 1].first, left[i-1]);
    }

    for (int i=1; i <= n; i++) {
        right[i] = right[i-1] + rvalues[i - 1].second;
    }

    for (int i=1; i <= n; i++) {
        right[i] = max(right[i] - (c - rvalues[i - 1].first), right[i-1]);
    }

    //how many to take on the left
    for (int i=0; i <= n; i++) {

        long long current = left[i];
        long long other = right[n-i];

        if (i > 0) {
            other -= values[i - 1].first;
        }

        best = max(best, current + max(other, 0ll));
    }



    //how many to take on the right
    for (int i=0; i <= n; i++) {

        long long current = right[i];
        long long other = left[n-i];

        if (i > 0) {
            other -= (c - rvalues[i - 1].first);
        }

        best = max(best, current + max(other, 0ll));
    }


    cout << best << endl;
    return 0;
}
