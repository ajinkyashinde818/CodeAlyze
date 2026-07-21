#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
	int N, M; 
  	cin >> N >> M; 
	char A[60][60] = {}, B[60][60] = {}; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j]; 
        }
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
			cin >> B[i][j]; 
        }
	}
	string ans = "No"; 
	for(int s = 0; s <= N-M; s++){
		for(int t = 0; t <= N-M; t++){
			bool possible = true; 
			for(int i = 0; i < M; i++){
				for(int j = 0; j < M; j++){
					if(A[i+s][j+t] != B[i][j]){
						possible = false; 
					}
				}
			}
          if(possible) ans = "Yes"; 
		}
	}
	cout << ans << endl; 
}
