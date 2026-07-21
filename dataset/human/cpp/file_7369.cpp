#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int n;
int main() {
    cin >> n;
    long long arr[n];
    long long fromLeft[n];
    long long fromRight[n];
    for (int i = 0; i < n; i++) {
      	cin >> arr[i];
        fromLeft[i] = 0;
        fromRight[i] = 0;
    }
    fromLeft[0] = arr[0];
    fromRight[n-1] = arr[n-1];
    for (int i = 1; i < n; i++) {
        fromLeft[i] = fromLeft[i-1] + arr[i];
        fromRight[n-i-1] = fromRight[n-i] + arr[n-i-1];
    }
    long long ans = numeric_limits<long long int>::max();
    for (int i = 0; i < n-1; i++) {
        ans = min(ans, abs(fromLeft[i]-fromRight[i+1]));
    }
    cout << ans << endl;
    return 0;
}
