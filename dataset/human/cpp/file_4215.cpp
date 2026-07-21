#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    x++;

    int ans = 0;
    long long sum = 0;
    long long curr = 1;

    while (2*sum+curr <= x) {
        ans++;
        sum += curr;
        curr *= 3;
    }

    ans += ans-1;
    curr /= 3;
    sum += sum-curr;
    while (curr >= 1) {
        if (sum + curr <= x) {
            ans++;
            sum += curr;
        } else {
            curr /= 3;
        }
    }

    cout << ans-1 << endl;

}
