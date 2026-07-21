#include <iostream>
#include <vector>
using namespace std;

int main() {

  long long int n, m;
  cin >> n >> m;

  vector< string > a, b;

  for ( long long int i = 0; i < n; i++ ) {

    string in;
    cin >> in;
    a.push_back( in );

  }

  for ( long long int i = 0; i < m; i++ ) {

    string in;
    cin >> in;
    b.push_back( in );

  }

  for ( long long int y = 0; y < n - m + 1; y++ ) {

    for ( long long int x = 0; x < n - m + 1; x++ ) {

      bool f = true;
      for ( long long int yy = 0; yy < m; yy++ ) {

	for ( long long int xx = 0; xx < m; xx++ ) {

	  if ( a[y+yy][x+xx] != b[yy][xx] ) {
	    f = false;
	    break;
	  }

	}

      }

      if ( f == true ) {
	cout << "Yes" << endl;
	return 0;
      }

    }

  }

  cout << "No" << endl;

  return 0;

}
