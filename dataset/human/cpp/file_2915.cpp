#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	long long A[114514] = {}; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	long long absmin = 1145141919; 
	int negcnt = 0; 
	long long abssum = 0; 
	for(int i = 0; i < N; i++){
		abssum += abs(A[i]); 
		absmin = min(absmin, abs(A[i])); 
		if(A[i] <= 0) negcnt ++;
	}
	if(negcnt % 2 == 0) cout << abssum << endl; 
	else cout << abssum - 2 * absmin << endl; 
}
