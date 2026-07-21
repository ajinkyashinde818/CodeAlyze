#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    long N, i, sign = 1, num, min = __LONG_MAX__;
    cin >> N;
    vector<long> A(N);

    for(i = 0; i < N; i++) {
        cin >> num;
        if(num < 0) sign = sign * -1;
        A[i] = abs(num);
        if(A[i] < min) min = A[i];
    }

    long sum = 0;
    for(i=0; i<N; i++) sum = sum + A[i];

    (sign==1) ? cout << sum : cout << sum - min * 2;
    cout << endl;
}
