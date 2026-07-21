#include<iostream>

using namespace std;

int main(){
	int N, M;
	char A[50][50], B[50][50];
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < M; i++){
		cin >> B[i];
	}
	bool canflag = false;
	for(int ai = 0; ai < N; ai++){
		for(int aj = 0; aj < N; aj++){
			bool flag = true;
			for(int bi = 0; bi < M; bi++){
				for(int bj = 0; bj < M; bj++){
					if(A[ai + bi][aj + bj] != B[bi][bj]){
						flag = false;
					}
				}
				if(flag == false){
					break;
				}
			}
			if(flag == true){
				canflag = true;
				break;
			}
		}
	}
	if(canflag == true){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
