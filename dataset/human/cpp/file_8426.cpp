#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int N, M;
	cin >> N >> M;
	
	vector<string>a(N), b(M);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	for (int i=0; i<N-M+1; i++){
		for (int j=0; j<N-M+1; j++){

			bool flg = 1;
			for (int k=0; k<M; k++){
				for (int l=0; l<M; l++){
					if ( a.at(k+i).at(l+j) != b.at(k).at(l) ) {
						flg = 0;
						break;
					}
				}
				if (!flg) break;
			}
			
			if (flg) {
				cout << "Yes" << endl;
				return 0;
			}
			
		}
	} 
	cout << "No" << endl;
	
	return 0;
}
