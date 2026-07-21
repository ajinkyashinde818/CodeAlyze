#include<iostream>
using namespace std;
int main() {
    int n, m=1e9, b=0;
    long long r=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        r += abs(a);
        m = min(m, abs(a));
        b ^= a < 0;
    }
    cout << r - b * m * 2 << endl;
    return 0;
}
