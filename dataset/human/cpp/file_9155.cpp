#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, string> A, B;
	int N, M; cin >> N >> M;
	for(int i=0; i<N; ++i) cin >> A[i];
	for(int i=0; i<M; ++i) cin >> B[i];
	bool judge=false;
	for(int i=0; i<=N-M; ++i){
	    for(int j=0; j<=N-M; ++j){
	        bool check=true;
	        for(int k=0; k<M; ++k){
	            if(A[i+k].substr(j, M)!=B[k]){
	                check=false;
	                break;
	            }
	        }
	        if(check){
	            judge=true;
	            break;
	        }
	    }
	    if(judge) break;
	}
	if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
