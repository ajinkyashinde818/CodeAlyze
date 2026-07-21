#include <iostream>
#include <string>

using namespace std;

int N, M;
string A[55], B[55];

bool check(int i, int j)
{
	for(int di = 0; di < M; di++){
		for(int dj = 0; dj < M; dj++){
			if(A[i+di][j+dj] != B[di][dj]) return false;
		}
	}
	return true;
}

int main(void)
{
	cin >> N >> M;
	if(M > N){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < M; i++) cin >> B[i];
	
	for(int i = 0; i <= N-M; i++){
		for(int j = 0; j <= N-M; j++){
			if(check(i, j)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
