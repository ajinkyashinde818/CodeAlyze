#include <iostream>
#include <vector>
using namespace std;
int n;
vector < int > ans[(1<<10)];

void genAns ( int snum, int kleft, int sy ) {
    if ( kleft == 0 ) { return; }

    for ( int i = 0 ; i < kleft ; i ++ ) { ans[sy].push_back( snum +i ); }
    for ( int y = 1; y <= kleft ; y ++ ) { ans[sy+y].push_back( snum+y-1 ); }

    genAns ( snum + kleft, kleft-1, sy+1 );
}

int main () {

    cin >> n;
    int k;
    for ( k = 1 ; k*(k+1) < 2*n ; k ++ ) {}

    if ( k*(k+1) != 2*n ) { cout << "No\n"; return 0; }

    cout << "Yes\n";
    genAns( 1, k, 0 );
    cout << k+1 << "\n";
    for ( int i = 0 ; i < k+1 ; i ++ ) {
        cout << ans[i].size() << " ";
        for ( int j = 0 ; j < ans[i].size() ; j ++ ) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
