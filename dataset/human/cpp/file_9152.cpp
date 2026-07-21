#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

int main(){
	int N, M;
	vector<string> A, B;
	int i, j, k;
	cin >> N >> M;
	for (i = 0; i < N; i++){
		string s;
		cin >> s;
		A.push_back(s);
	}
	for (i = 0; i < M; i++){
		string s;
		cin >> s;
		B.push_back(s);
	}
	for (i = 0; i < N - M + 1; i++){
		for (j = 0; j < N - M + 1; j++){
			bool flg = true;
			for (k = 0; k < M; k++){
				if (B[k] != A[i + k].substr(j, M)){
					flg = false;
				}
			}
			if (flg){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
