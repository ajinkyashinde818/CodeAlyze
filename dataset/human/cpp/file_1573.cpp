#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N; cin >> N;
	int P=2;
	while(P*(P-1)/2<N) ++P;
	if(P*(P-1)/2>N){
	    cout << "No" << endl;
	    return 0;
	}
	cout << "Yes" << endl;
	cout << P << endl;
	vector<vector<int>> V(P, vector<int>(P-1, 0));
	int now=1;
	for(int i=0; i+1<P; ++i){
	    for(int j=i; j+1<P; ++j){
	        V[i][j]=V[j+1][i]=now;
	        ++now;
	    }
	}
	for(int i=0; i<P; ++i){
	    cout << P-1;
	    for(int j=0; j+1<P; ++j) cout << ' ' << V[i][j];
	    cout << endl;
	}
	return 0;
}
