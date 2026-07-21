#include <iostream>
using namespace std;
long long n, c;
pair < long long, long long > arr[(1<<20)];
long long sumP[(1<<20)], sumS[(1<<20)];
int main () {
    cin >> n >> c;
    for ( long long i = 0 ; i < n ; i ++ ) {
        cin >> arr[i].first >> arr[i].second;
    }

    sumP[0] = arr[0].second - arr[0].first;
    for ( long long i = 1 ; i < n ; i ++ ) {
        sumP[i] = sumP[i-1] + arr[i].second - ( arr[i].first - arr[i-1].first );
    }

    sumS[n-1] = arr[n-1].second - ( c - arr[n-1].first );
    for ( long long i = n-2 ; i >= 0 ; i -- ) {
        sumS[i] = sumS[i+1] + arr[i].second - ( arr[i+1].first - arr[i].first );
    }

    long long ans = max( sumS[0], sumP[n-1] );
    ans = max( ans, 0LL );

    long long maxP = 0;
    for ( long long i = 0 ; i+1 < n ; i ++ ) {
        maxP = max( maxP, sumP[i] );

        //cout << "going for " << sumS[i+1] << " then returning with -" << (c-arr[i+1].first) << " for " << maxP << "\n";
        ans = max( ans, maxP + sumS[i+1] - ( c - arr[i+1].first ) );
    }
    long long maxS = 0;
    for ( long long i = n-1 ; i > 0 ; i -- ) {
        maxS = max( maxS, sumS[i] );
        ans = max( ans, maxS + sumP[i-1] - ( arr[i-1].first ) );
    }

    for ( long long i = 0 ; i < n ; i ++ ) {
        ans = max( ans, sumP[i] );
        ans = max( ans, sumS[i] );
    }
    cout << ans << "\n";
    return 0;
}
