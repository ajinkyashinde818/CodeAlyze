#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long a[200002];

long long f( int l, int r ) {
    long long sum = 0;
    int i;
    for ( i = l; i <= r; i++ ) {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    int i;
    for ( i = 1; i <= n; i++ ) {
        cin >> a[i];
    }

    long long sum1 = 0, sum2 = 0;

    long long sumT = f(1, n);

    long long Min = LLONG_MAX;

    sum1 = a[1];
    sum2 = sumT - sum1;
    if ( abs(sum1 - sum2) < Min ) {
            Min = abs(sum1 - sum2);
    }

    for ( i = 2; i < n; i++ ) {
        sum1 += a[i];
        sum2 = sumT - sum1;
        if ( abs(sum1 - sum2) < Min ) {
            Min = abs(sum1 - sum2);
        }
    }

    cout << Min;
    return 0;
}
