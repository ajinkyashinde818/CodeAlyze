#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const long long INF = 1LL << 60;

int main() {
        int N; cin >> N;
        LL A[N];
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
        }

        LL minA = INF;
        LL sum = 0;
        int minusN = 0;
        for (int i = 0; i < N; ++i) {
                if (A[i] < 0) {
                        minusN++;
                }
                minA = min(minA, abs(A[i]));
                sum+=abs(A[i]);
        }
        if (minusN%2 == 0) {
                cout << sum << "\n";
        } else {
                sum = sum - minA*2;
                cout << sum << "\n";
        }
        return 0;
}
