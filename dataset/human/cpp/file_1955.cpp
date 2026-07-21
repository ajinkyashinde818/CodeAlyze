#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long int ans = 0;
    sort(A.begin(), A.end());

    int i = 0;
    while (i < N - 1) {
        if (A[i] >= 0) break;
        else if (A[i+1] <= 0 || -A[i] > A[i+1]) {
            ans = ans - A[i] - A[i+1];
            i += 2;
        }
        else break;
    }
    while (i < N) ans += A[i++];

    cout << ans << endl;

    return 0;
}
