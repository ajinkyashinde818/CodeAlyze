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
#include<unordered_map>
using namespace std ;

#define MAXN 1007

struct tuhla {
    double x , y ;
    double r ;
};
int n ;
tuhla a[ MAXN ] ;

double dist[ MAXN ][ MAXN ] ;

double ans[ MAXN ] ;


void dijkstra ( int st ) {
    for ( int i = 1 ; i <= n + 2 ; ++ i ) {
        ans[ i ] = -1 ;
    }
    ans[ st ] = 0 ;
    priority_queue < pair < double , int > > pq ;
    pq.push ( { 0 , st } ) ;
    while ( pq.empty ( ) == false ) {
        pair < double , int > aux = pq.top ( ) ;
        pq.pop ( ) ;
        aux.first = -aux.first ;
        if ( aux.first > ans[ aux.second ] || aux.first < ans[ aux.second ] ) { continue ; }
        for ( int i = 1 ; i <= n + 2 ; ++ i ) {
            double c = aux.first + dist[ aux.second ][ i ] ;
            if ( ans[ i ] < 0 || ans[ i ] > c ) {
                ans[ i ] = c ;
                pq.push ( { - c , i } ) ;
            }
        }
    }
}

double calc ( tuhla p1 , tuhla p2 ) {
    double act = sqrt ( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) ) ;
    act -= p1.r + p2.r ;
    if ( act < 0 ) { act = 0 ; }
    return act ;
}

void input ( ) {
    pair < double , double > foo1 , foo2 ;
    cin >> foo1.first >> foo1.second >> foo2.first >> foo2.second ;
    cin >> n ;
    a[ n + 1 ].x = foo1.first ;
    a[ n + 1 ].y = foo1.second ;

    a[ n + 2 ].x = foo2.first ;
    a[ n + 2 ].y = foo2.second ;

    a[ n + 1 ].r = a[ n + 2 ].r = 0.0 ;
    
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y >> a[ i ].r ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n + 2 ; ++ i ) {
        for ( int j = 1 ; j <= n + 2 ; ++ j ) {
            if ( i == j ) { continue ; }
            dist[ i ][ j ] = calc ( a[ i ] , a[ j ] ) ;
        }
    }
    dijkstra ( n + 1 ) ;
    printf ( "%.15lf\n" , ans[ n + 2 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
