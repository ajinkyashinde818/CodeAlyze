#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
typedef long long ll;

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string A[55];
    string B[55];
    for (int i = 0; i < N; i++){
	cin >> A[i];
    }
    for (int i = 0; i < M; i++){
	cin >> B[i];
    }

    bool can = false;
    for (int i = 0; i <= N-M; i++){
	for (int j = 0; j <= N-M; j++){

	    bool can2 = true;
	    for (int k = 0; k < M; k++){
		for (int l = 0; l < M; l++){
		    if (A[i+k][j+l] != B[k][l]){
			can2 = false;
		    }
		}
	    }
	    if (can2) can = true;
	}
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
