#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007

int n ;
string a ;



void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    long long x = 0 ;
    long long ans = 1 ;
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        if ( x > ( 2 * n - i ) ) {
            ans = 0 ;
        }
        else {
            if ( a[ i ] == 'W' ) {
                if ( ( x & 1 ) != 0 ) {
                    ++ x ;
                }
                else {
                    ans = ( ans * x ) % MOD ;
                    -- x ;
                }
            }
            else {
                if ( ( x & 1 ) == 0 ) {
                    ++ x ;
                }
                else {
                    ans = ( ans * x ) % MOD ;
                    -- x ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans * i ) % MOD ;
    }
    printf ( "%lld\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
