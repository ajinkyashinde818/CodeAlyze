#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, A[100001];

    cin >> N;
    for (int i=0; i<N; ++i) cin >> A[i];

    for (int i=0; i<N-1; ++i) {
        if (A[i] < 0) {
            A[i] *= -1;
            A[i+1] *= -1;
        }
    }

    long long sum = 0;
    for (int i=0; i<N; ++i) {
        sum += A[i];
    }

    long long res = sum;
    for (int i=N-2; i>=0; --i) {
        sum = sum - A[i] - A[i+1];
        A[i] *= -1;
        A[i+1] *= -1;
        sum = sum + A[i] + A[i+1];
        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}
