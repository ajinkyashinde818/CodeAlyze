#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<long long> A(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];

        if (A[i] < 0)
            cnt++;

        A[i] = max(A[i], -A[i]);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i];

    if (cnt % 2 == 0) {
        cout << sum << endl;
    }
    else {
        long long n = *min_element(A.begin(), A.end());
        cout << sum - 2 * n << endl;
    }

    return 0;
}
