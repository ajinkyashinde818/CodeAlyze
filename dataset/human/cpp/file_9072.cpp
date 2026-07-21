#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	
	char A[N][N];
	char B[M][M];
	for(int i=0; i<N; i++){
	for(int j=0; j<N; j++){
		cin >> A[i][j];
	}
	}
	for(int i=0; i<M; i++){
	for(int j=0; j<M; j++){
		cin >> B[i][j];
	}
	}
	
	int ans=0;
	for(int i=0; i<N-M+1; i++){
	for(int j=0; j<N-M+1; j++){
		ans=1;
		for(int k=0; k<M; k++){
		for(int l=0; l<M; l++){
			if(A[i+k][j+l]!=B[k][l]){
				ans=0;
			}
		}
		}
		if(ans==1){
			cout << "Yes"<<endl;
			return 0;
		}
	}
	}
	
	cout << "No" << endl;
	return 0;
}
