#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> s(n+1, 0);

    long long sum = 0;
    for(long long i = 0; i < n; i++) cin >> a[i], sum += a[i];

    for(long long i = 0; i < n; i++) s[i+1] = s[i] + a[i];

    long long minv = 1e20;
    for(long long i = 1; i <= n-1; i++){
        long long x, y;
        x = s[i];
        y = sum - s[i];
        minv = min(minv, abs(x-y));
    }
    cout << minv << endl;
    return 0;
}
