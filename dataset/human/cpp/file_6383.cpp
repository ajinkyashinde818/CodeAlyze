#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long fact(int n){
	if (n == 0) return 1;
	else return n * (fact(n-1) % (1000000007));
}

int main() {
	int N;
	cin >> N;
	int S[300000];
	for (int i=0; i<2*N; i++){
		char s;
		cin >> s;
		if(s=='B') S[i] = 1;
		else S[i] = 0;
	}

	//Lなら0、Rなら1
	int A[300000];
	A[0] = 0;
	for (int i=1; i<2*N; i++){
		if (S[i-1] == S[i]){
			if (A[i-1]==1) A[i] = 0;
			else A[i] = 1;
		}
		else A[i] = A[i-1];
	}

	int L[300000];
	int R[300000];
	int l = 0;
	int r = 0;
	L[0] = 0;
	R[0] = 0;
	for (int i = 0; i<2*N; i++){
		if(A[i] == 0) l++;
		else r++;
		L[i+1] = l;
		R[i+1] = r;
	}

	long long ans;
	if(l==r && S[0] != 0 && S[2*N-1] != 0) {

	ans = 1;
	for (int i = 0; i<2*N; i++){
		if(A[i] == 1) ans = ans * (L[i]-R[i]) % (1000000007);
	}

	ans = (ans * (fact(N)% (1000000007))) % (1000000007);
	}
	else ans = 0;


	cout << ans << endl;

  return 0;
}
