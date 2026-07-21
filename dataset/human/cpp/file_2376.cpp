#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
// numeric_limits<int>::max()

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll minAbs = abs(numeric_limits<ll>::max());
    ll sum = 0;
    ll numNegative = 0;
    bool zeroFound = false;
    for (int i = 0; (i < N); ++i) {
        cin >> A[i];
        minAbs = min(minAbs, abs(A[i]));
        if (A[i] == 0)
            zeroFound = true;
        else if (A[i] < 0)
            numNegative++;
        sum += abs(A[i]);
    }
    bool numEven = (numNegative % 2 == 0) ? true : false;
    if (zeroFound || numEven)
        cout << sum << endl;
    else
        cout << sum - minAbs * 2 << endl;
    return 0;
}
