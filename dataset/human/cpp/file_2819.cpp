#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N;

/*
    
    dp1[n] : [0..n] の内、i==nで操作をしていない場合の ΣBの最大値
    dp2[n] : [0..n] の内、i==nで操作をしている場合の   ΣBの最大値
    
    
*/

ll dp1[100005];
ll dp2[100005];

int main(){
	cin >> N;
	
	vector<ll> A(N+1);
	for ( int i = 0; i < N; i++ )
		cin >> A[i];
	
	dp1[0] = A[0];
	dp2[0] = -A[0];
	for ( int i = 1; i < N; i++ ){
		dp1[i] = max(dp1[i-1]+A[i], dp2[i-1]-A[i]);
		dp2[i] = max(dp1[i-1]-A[i], dp2[i-1]+A[i]);
	}
	
	cout << dp1[N-1] << endl;
	
	return 0;
}
