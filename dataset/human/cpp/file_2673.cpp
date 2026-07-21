#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e5+10 ;
long long a[maxn] ;
long long gcd1[maxn] ;
long long gcd2[maxn] ;

int main() {

    long long n ;
    cin >> n ;
    long long mn = 0 ;
    long long sum = 0 ;
    long long m = 1e9 ;

    for(long long i = 0, tmp; i < n; i++){

        cin >> tmp ;
        sum += abs(tmp) ;
        m = min(m, abs(tmp)) ;
        if(tmp < 0)
            mn++ ;

    }
    if(mn%2 == 1){
        cout << sum - m*2 ;
    }else{
        cout << sum ;
    }

}
