#include <iostream>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	char A[N][N], B[M][M];
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

	for(int y=0; y<N-M+1; y++){
		int flag=1;
		for(int x=0; x<N-M+1; x++){
			if(A[y][x]==B[0][0]){
				flag = 0;
				for(int i=1; i<M; i++){
					for(int j=1; j<M; j++){
						if(A[y+i][x+j]!=B[i][j]){
							flag=1;
							break;
						}
					}
					if(flag==1){
						break;
					}
				}
			}
		}
		if(flag==0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
