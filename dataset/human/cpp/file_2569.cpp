#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long ans = 0;
    int min = 1000000000;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int temp = abs(A[i]);
        ans += temp;
        if (min > temp) {
            min = temp;
        }
        if (A[i] < 0) {
            count++;
        }
    }
    if (count % 2 != 0) {
        ans -= 2 * min;
    }
    cout << ans << endl;
    return 0;
}
