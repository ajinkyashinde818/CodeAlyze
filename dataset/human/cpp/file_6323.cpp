#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; string S; 
	cin >> N >> S; 
	long long int Fac[100010] = {}; 
	Fac[0] = 1; 
	long long int P = 1e9 + 7; 
	for(int i = 1; i <= 100005; i++){
		Fac[i] = Fac[i-1] * (long long) i % P; 
	}
	if(S.at(0) == 'W' || S.at(N*2-1) == 'W'){
		cout << 0 << endl; return 0; 
	}
	long long int stock = 0; 
	long long int ans = 1; 
	for(int i = 0; i < N*2; i++){
		if(S.at(i) == 'B' && stock % 2 == 0){
			stock ++; 
		}
		else if(S.at(i) == 'B' && stock % 2 == 1){
			ans *= stock; ans %= P; 
			stock --; 
			if(stock < 0){
				cout << 0 << endl; return 0; 
			}
		}
		else if(S.at(i) == 'W' && stock % 2 == 0){
			ans *= stock; ans %= P; 
			stock --; 
			if(stock < 0){
				cout << 0 << endl; return 0; 
			}
		}
		else if(S.at(i) == 'W' && stock % 2 == 1){
			stock ++; 
		}
	}
	if(stock != 0){
		cout << 0 << endl; return 0; 
	}
	long long int final = ans * Fac[N] % P; 
	cout << final << endl; 
}
