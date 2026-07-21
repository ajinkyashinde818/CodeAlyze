#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    bool haszero = false;
    int  mcount = 0; 
    int  nzmmv  = 1000000000;
    vector<int> a(n);

    long result = 0; 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        result += abs(a[i]);
        if (a[i] < 0) {
            ++mcount;
        }
        if (abs(a[i]) < nzmmv) {
            nzmmv = abs(a[i]);
        }
    }

    if (mcount % 2 == 1){
        result -= (nzmmv * 2);
    }
    cout << result << endl;
}
