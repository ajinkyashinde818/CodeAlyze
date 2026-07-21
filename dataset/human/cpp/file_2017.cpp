#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    int minus = 0;
    for(int i=0; i<N; i++) {
        cin >> A.at(i);
        if(A.at(i) < 0) {
            minus += 1;
            A.at(i) *= -1;
        }
    }
    long long int ans = accumulate(A.begin(), A.end(), 0LL);
    if(minus % 2 == 0) {
        cout << ans << endl;
    } else {
        int minimum = *min_element(A.begin(), A.end());
        cout << ans - 2 * minimum << endl;
    }

    return 0;
}
