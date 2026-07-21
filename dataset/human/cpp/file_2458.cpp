#include <iostream>
#include <numeric>
using namespace std;


int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int minusNum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) minusNum++;
    }

    long all_abs_sum = 0;

    for (int i = 0; i < N; i++) {
        all_abs_sum += abs(A[i]);
    }

    long result;
    if (minusNum % 2 == 0) {
        result = all_abs_sum;
    } else {
        int min = 1000000009;
        for (int i = 0; i < N; i++) {
            if (min > abs(A[i])) {
                min = abs(A[i]);
            }
        }
        result = all_abs_sum - 2 * min;
    }

    cout << result << endl;

	return 0;
}
