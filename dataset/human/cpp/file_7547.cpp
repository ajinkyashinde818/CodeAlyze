#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, a;
    cin >> n;
    vector<int> input;
    for (int i=0; i<n; ++i) {
        cin >> a;
        input.push_back(a);
    }
    ll sum = 0;
    for (auto&e : input) {
        sum += e;
    }
    ll minDiff = LLONG_MAX;
    ll x = 0, y = sum;
    
    for (int i=0; i < input.size()-1; ++i) {
        x += input[i];
        y -= input[i];
        minDiff = min(minDiff, abs(x - y));
    }
    cout << minDiff << endl;
}
