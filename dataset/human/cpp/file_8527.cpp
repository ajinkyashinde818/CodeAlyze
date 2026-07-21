#include<iostream>
#include <string>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	string A[55];
	string B[55];
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int j = 0; j < M; j++){
		cin >> B[j];
	}
	
	bool judge = false;
	
	for(int i = 0; i < N - M + 1; i++){
		for(int j = 0; j < N - M + 1; j++){
			for(int k = 0; k < M; k++){
				if(B[k] != A[i + k].substr(j, M)){
					break;
				}
				if(k == M - 1){
					judge = true;
				}
			}
		}
	}
	if(judge){
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
