#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

typedef long long ll;

using namespace std;

ll GetMaximumSumFlippingSigns(vector<ll>& num) {
    ll sum = 0;
    ll minAbs = -1;
    ll cntNegative = 0;
    for(int i = 0; i < num.size(); ++i) {
        sum += abs(num[i]);
        if(num[i] < 0) {
            cntNegative += 1;
        }
        if(minAbs == -1) {
            minAbs = abs(num[i]);
        } else {
            minAbs = min(minAbs, abs(num[i]));
        }
    }
    if(cntNegative % 2 == 1){
        sum -= 2 * minAbs;
    }
    return sum;
}

int main() {
    int n = 11;
    cin >> n;
    vector<ll> num(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    ll maxSum = GetMaximumSumFlippingSigns(num);
    cout << maxSum << endl;
    return 0;
}
