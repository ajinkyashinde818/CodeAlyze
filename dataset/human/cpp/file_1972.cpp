#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, M, Q, A, B, C, arr[200005];
string s, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	A = 0, B = 0, C = 1e9+2;
	for (int i = 1; i <= N; ++i){
		cin >> arr[i];
		if (arr[i] < 0){
			B++;
			arr[i] *= -1;
		} 
		C = min(C,abs(arr[i]));
		A += arr[i];
	}
	if (B%2!=0){
		A -= 2*C;
	}
	cout << A << '\n';
	
}
