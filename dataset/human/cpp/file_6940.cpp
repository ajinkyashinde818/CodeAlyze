#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N; 
	int A[200010], B[200010]; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	for(int i = 0; i < N; i++) cin >> B[i]; 
	int cnt[200010] = {}; 
	for(int i = 0; i < N; i++){
		cnt[A[i]] ++; cnt[B[i]] ++; 
	}
	for(int i = 1; i <= N; i++){
		if(cnt[i] > N){
			cout << "No" << "\n"; return 0;
		}
	}
	cout << "Yes" << "\n"; 
	for(int i = 0; i < (N+1)/2; i++) swap(B[i], B[N-1-i]); 
	vector<int> overlap; 
	vector<int> not_overlap; 
	int num = -1; 
	for(int i = 0; i < N; i++){
		if(A[i] == B[i]){
			overlap.push_back(i); num = A[i]; 
		}
	}
	for(int i = 0; i < N; i++){
		if(A[i] != num && B[i] != num) not_overlap.push_back(i);
	}
	for(int i = 0; i < (int) overlap.size(); i++){
		swap(B[overlap.at(i)], B[not_overlap.at(i)]); 
	}
	for(int i = 0; i < N; i++) cout << B[i] << " ";
	cout << "\n";  
}
