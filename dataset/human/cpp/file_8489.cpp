#include <bits/stdc++.h>
using namespace std;

const int DIM = 55;

char a[DIM][DIM], b[DIM][DIM];

int main( void ) {
    
    int n, m;
    cin >> n >> m;
    
    for( int i = 1; i <= n; i ++ )
        cin >> ( a[i] + 1 );
    for( int i = 1; i <= m; i ++ )
        cin >> ( b[i] + 1 );
    
    bool ans = false;
    for( int i = 1; i <= n - m + 1; i ++ ) {
    for( int j = 1; j <= n - m + 1; j ++ ) {
        bool ok = true;
        
        for( int ii = 1; ii <= m; ii ++ )
        for( int jj = 1; jj <= m; jj ++ )
            if( b[ii][jj] != a[i + ii - 1][j + jj - 1] )
                ok = false;
        
        ans |= ok;
    } }
    
    cout << ( ( ans == true ) ? "Yes" : "No" );
    return 0;
}
