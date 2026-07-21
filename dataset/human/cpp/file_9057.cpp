#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> temp (N);
	vector<string> test (M);
	for(int i = 0;i < N;i++){
		cin >> temp.at(i);
	}
	for(int i = 0;i < M;i++){
		cin >> test.at(i);
	}
	
	for(int i = 0;i < (N-M+1)*(N-M+1);i++){
		for(int j = 0;j <= M*M;j++){
			if(j == M*M){
				cout << "Yes" << endl;
				return 0;
			}
			else{
				if(test.at(j/M).at(j%M) != temp.at(i/(N-M+1)+j/M).at(i%(N-M+1)+j%M)){
					break;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
