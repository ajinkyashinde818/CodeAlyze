#include <bits/stdc++.h>
using namespace std;

long long a[100005];
long long pos[100005];

int main()
{
    long long n; ///LL
    cin >> n;
    for(long long i =0; i < n; ++i){
        cin >> a[i];
    }

    long long sum = 0;
    long long mi = 987654321;
    long long us = 0;
    for(long long i = 0; i < n; ++i){
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
        if(a[i] < 0){
            us++;
        }
    }

    sum = (us % 2 == 0 ? sum : sum - 2 * mi);

    cout << sum << "\n";
    return 0;
}
