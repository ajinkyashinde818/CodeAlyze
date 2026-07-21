#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, c = 0;
    long long ans = 0;
    cin >> n;
    int a[100001], abs[100001];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            c++;
            abs[i] = (-1) * a[i];
        }
        else abs[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        ans += abs[i];
    }
    
    sort(abs, abs+n);
    if(c % 2) {
        ans -= 2 * abs[0];
    }
    cout << ans << endl;
	return 0;
}
