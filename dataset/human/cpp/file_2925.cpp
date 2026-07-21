#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;



int main(){
	ll N;
	cin>>N;
	int ni = 0;
	vector<ll>A(N);
	ll M = 0;
	ll L = 1000000000;
	for(int i = 0; i < N; i++){
		cin>>A[i];
		if(A[i] < 0)ni++;
		M+=abs((int)A[i]);
		if(L > abs(A[i]))L = abs(A[i]);
	}
	if(ni % 2 == 0)cout<<M<<endl;
	else cout<<M - L - L<<endl;
	return 0;
}
