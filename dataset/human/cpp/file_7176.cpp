#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int s = accumulate(v.begin(), v.end(), (long long int)0);
    long long int res = -1;
    long long int c = 0;
    for (int i = 0; i < n - 1; i++) {
        c += v[i];
        long long int diff = abs(s - c - c);
        if (res == -1 || res > diff) {
            res = diff;
        }
    }
    cout << res << endl;
}
