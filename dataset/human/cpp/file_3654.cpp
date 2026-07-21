#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int minv = pow(10, 9);
    int cnt = 0;
    int64_t ret = 0;
    for (int i = 0; i < N; i++) {
        if (abs(A[i]) < minv) minv = abs(A[i]);
        if (A[i] < 0) cnt++;
        ret += abs(A[i]);
    }
    if (cnt % 2 != 0) {
        ret -= minv * 2;
    }
    cout << ret << endl;


    return 0;
}
