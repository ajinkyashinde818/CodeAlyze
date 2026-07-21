#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

long long x[100001];
long long v[100001];
long long cw[100001];
long long counter_cw[100001];
long long cw_ret[100001];
long long counter_cw_ret[100001];
long long best_cw_ret[100001];
long long best_counter_cw_ret[100001];

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(12);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    long long n, c;
    cin >> n >> c;

    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
    }

    long long cur_sum = 0;
    long long best_val = 0;
    for(int i = 0; i < n; ++i) {
        cur_sum += v[i];
        cw[i] = cur_sum - x[i];
        cw_ret[i] = cur_sum - 2 * x[i];
        best_val = max(best_val, cw_ret[i]);
        best_cw_ret[i] = best_val;
    }

    cur_sum = 0;
    best_val = 0;
    for(int i = n - 1; i >= 0; --i) {
        cur_sum += v[i];
        counter_cw[i] = cur_sum - (c - x[i]);
        counter_cw_ret[i] = cur_sum - 2 * (c - x[i]);
        best_val = max(best_val, counter_cw_ret[i]);
        best_counter_cw_ret[i] = best_val;
    }

    long long res = 0;
    for(int i = 0; i < n; ++i) {
        long long cur_res = cw[i];
        if(i != n - 1) cur_res += best_counter_cw_ret[i + 1]; 
        res = max(cur_res, res);
    }
    for(int i = n - 1; i >= 0; --i) {
        long long cur_res = counter_cw[i];
        if(i != 0) cur_res += best_cw_ret[i - 1];
        res = max(cur_res, res);
    }

    cout << res << endl;

    return 0;
}
