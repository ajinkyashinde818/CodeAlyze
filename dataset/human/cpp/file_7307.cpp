#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N;
    cin >> N;;
    int64_t sum = 0;
    int64_t sum2 = 0;
    int64_t avg = INT64_MAX;
    vector<int64_t>vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
        sum += vec[i];
    }

    for (int i=N-1; i>0; i--){
        sum -= vec[i];
        sum2 += vec[i];
        int64_t s = abs(sum - sum2);
        if (s < avg) {
            avg = s;
        }
    }

    cout << avg << endl;
    return 0;
}
