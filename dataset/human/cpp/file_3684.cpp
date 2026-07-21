#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(void) {
    int N, C;
    vector<long long> A;

    C = 0;
    cin >> N;
    for (int i=0;i<N;i++) {
        long long X;
        cin >> X;
        if (X<0) C++;
        A.push_back(abs(X));
    }

    if (C%2) cout << accumulate(A.begin(), A.end(), 0LL) - 2LL*(*min_element(A.begin(), A.end())) << endl;
    else cout << accumulate(A.begin(), A.end(), 0LL) << endl;

    return 0;
}
