#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<long> A(N);
    for (int n = 0; n < N; n++) cin >> A[n];
    int cnt = 0;
    for (int n = 0; n < N; n++) if (A[n] < 0) cnt++;
    for (int n = 0; n < N; n++) A[n] = abs(A[n]);
    long sum = 0;
    for (int n = 0; n < N; n++) sum += A[n];

    if (cnt % 2) {
        sort(A.begin(), A.end());
        sum -= 2 * A[0];
    }

    cout << sum << endl;
}
