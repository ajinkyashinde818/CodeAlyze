#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int N;
    cin >> N;

    long long min_A = LONG_MAX, sum = 0, negative_num = 0;
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        if (A < 0) {
            negative_num++;
            A = -A;
        }
        sum += A;
        min_A = min(min_A, A);
    }

    if (negative_num % 2 == 0) {
        cout << sum << endl;
    } else {
        cout << sum - 2*min_A << endl;
    }

    
    return 0;
}
