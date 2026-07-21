#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll NUM = pow(10,9) + 7;

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	for(int i(0);i<2*N;i += 2){
		if(S[i] == 'B') S[i] = 'W';
		else S[i] = 'B';
	}
	if(S[0] == 'B'){
		cout << 0 << endl;
		return 0;
	}
	int l_n(0);
	ll ans(1);
	for(int i(0);i<2*N;i++){
		if(S[i] == 'W') l_n++;
		else{
			if(l_n <= 0){
				cout << 0 << endl;
				return 0;
			}else{
				ans = (ans * l_n)%NUM;
				l_n--; 
			}
		}
	}
	if(l_n != 0){
		cout << 0 << endl;
		return 0;
	}
	for(int i(1);i<=N;++i) ans = (ans*i)%NUM;
	cout << ans << endl;
	return 0;
}
