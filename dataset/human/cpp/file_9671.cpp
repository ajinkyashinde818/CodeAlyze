#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	int N, M;
	vector< vector<int> > a_N, a_M;
	int i,j,x,y;
	bool ans = false;
	
	cin >> N;
	cin >> M;
	
	a_N.resize(N);
	for ( i = 0; i < N; i++ ) {
		a_N[i].resize(N);
	}
	
	a_M.resize(M);
	for ( i = 0; i < M; i++ ) {
		a_M[i].resize(M);
	}
	
	for (  i = 0; i < N; i++ ) {
		string s;
		cin >> s;
		
		for ( j = 0; j < N; j++ ) {
			a_N[i][j] = ( s.substr(j,1) == "#" ) ? 1 : 0;
		}
	}
	for (  i = 0; i < M; i++ ) {		
		string s;
		cin >> s;
		
		for ( j = 0; j < M; j++ ) {
			a_M[i][j] = ( s.substr(j,1) == "#" ) ? 1 : 0;
		}
	}
	
	for (  i = 0; i <= N-M; i++ ) {
	for (  j = 0; j <= N-M; j++ ) {
		
		bool match = true;
		
		for (  x = 0; x < M; x++ ) {
		for (  y = 0; y < M; y++ ) {
			
			if ( a_M[x][y] != a_N[i+x][j+y] ) { match = false; }
			
		}
		}
		if ( match ) {
			ans = true;
		}
	}
	}
	
	cout << ( ans ? "Yes" : "No" ) << endl;
	
	
	return 0;
}
