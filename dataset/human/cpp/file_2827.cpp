#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(ll i=0;i<N;i++){
		cin >> A[i];
	}
	int count = 0;
	ll check0 = 0;
	for(int i=0;i<N;i++){
		if(A[i] <= 0)count++;
		if(A[i] == 0)check0 = 1;
	}
	vector<ll> B(N);
	for(int i=0;i<N;i++){
		B[i] = abs(A[i]);
	}
	ll ans = 0;
	sort(B.begin(),B.end());
	if(check0){
		for(int i=0;i<N;i++){
			ans += B[i];
		}
	}
	else if(count % 2){
		ans -= B[0];
		for(int i=1;i<N;i++){
			ans += B[i];
		}
	}
	else{
		for(int i=0;i<N;i++){
			ans += B[i];
		}
	}
	cout << ans << endl;
}
