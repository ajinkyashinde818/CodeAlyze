#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n];
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll min=9223372036854775807LL;
    ll sum_now=0;
    for(int i=0; i<n-1; i++) {
        sum_now+=a[i];
        if(min>abs(sum-2*sum_now)) min = abs(sum-2*sum_now);
    }

    cout << min << endl;

    return 0;
}
