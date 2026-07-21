#include <iostream>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N, A[100010];
    int min = 2000000001;

    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] < 0) {
            A[i] = -A[i];
            cnt++;
        }
        if (min > A[i]) min = A[i];
    }

    long long sum = 0;
    if (cnt % 2) {
        sum -= min; sum -= min;
    }
    for (int i = 0; i < N; i++) sum += A[i];

    cout << sum << '\n';
}
