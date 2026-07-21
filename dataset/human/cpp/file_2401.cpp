#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    long A[N]; for (int i = 0; i < N; i++) cin >> A[i];
    int num_neg = 0;
    long sum = 0, min_abs = abs(A[0]);
    bool is_exist_zero = false;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) num_neg++;
        else if (A[i] == 0) is_exist_zero = true;
        min_abs = min(min_abs, abs(A[i]));
        sum += abs(A[i]);
    }
    if (is_exist_zero) cout << sum << endl;
    else {
        if (num_neg % 2 == 0) cout << sum << endl;
        else cout << sum - 2 * min_abs << endl;
    }
    return 0;
}
