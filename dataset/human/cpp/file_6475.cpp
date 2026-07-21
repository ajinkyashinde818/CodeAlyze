#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main(){
	long long N; cin >> N;
	string S; cin >> S;
	long long ans = 1, cnt = 1;
	long long p = 1;
	for(int i=1; i<=N; i++) p = (p * i) % mod;
	if(S[0] == 'W' || S[2*N-1] == 'W'){
		cout << 0 << endl;
	}else{
		for(int i=1; i<2*N-1; i++){
			if(cnt % 2 == 0 && S[i] == 'W'){
				ans = (ans * cnt) % mod;
				cnt--;
			}else if(cnt % 2 == 0 && S[i] == 'B'){
				cnt++;
			}else if(cnt % 2 == 1 && S[i] == 'W'){
				cnt++;
			}else if(cnt % 2 == 1 && S[i] == 'B'){
				ans = (ans * cnt) % mod;
				cnt--;
			}
		}
		if(cnt == 1){
			cout << ans * p % mod<< endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}
