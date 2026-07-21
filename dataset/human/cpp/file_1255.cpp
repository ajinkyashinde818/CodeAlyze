#include <bits/stdc++.h>
using namespace std;


int main(){	
	long long R;
	long long B;
	long long G;
	long long N;
	scanf("%lld",&R);
	scanf("%lld",&G);
	scanf("%lld",&B);
	scanf("%lld",&N);
	long long res = 0;
	for (int i=0; i<=N/R; i++) {
		for (int j=0; j<=(N-i*R)/G; j++) {
			if ((N-i*R-j*G)%B == 0) res++;
		}
	}
	cout << res << endl;
	return 0;
}
