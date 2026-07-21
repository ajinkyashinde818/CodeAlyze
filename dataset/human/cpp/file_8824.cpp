#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {

    ll N,M;
    cin >> N>> M;
    vector<string> a(N),b(M);
    for(int i=0; i<N; i++) {
	cin >> a[i];
    }
    for(int i=0; i<M; i++) {
	cin >> b[i];
    }

    for(int i=0; i<N; i++) {
	for(int j=0; j<N; j++) {
	    // 左上の位置
	    if( N-i < M or N-j < M ) continue;
	    bool f = true;
	    for(int k=0; k<M; k++) {
		for(int l=0; l<M; l++) {
		    if( a[i+k][j+l] != b[k][l] ) f = false;
		}
	    }
	    if(f){
		cout << "Yes" << endl;
		return 0;
	    }
	}
    }
    cout << "No" << endl;
    return 0;
}
