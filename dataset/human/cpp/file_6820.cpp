#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<int,int> mp;
	int n ;
	cin >> n;
	vector<int> A(n), B(n);
	for(int i=0; i<n; i++) cin >> A[i];
	for(int i=0; i<n; i++) cin >> B[i];
	reverse(B.begin(), B.end());
	int el = -1;
	for(int i=0; i<n; i++){
		if(A[i] == B[i]){
			el = A[i];
			break;
		}
	}
	if(el == -1){
		cout << "Yes\n";
		for(int i=0; i<n; i++) cout << B[i] << " ";
		return 0;
	}
	int l, r;
	for(int i=0; i<n; i++){
		if(A[i]==el && B[i]==el){
			l = i;
			break;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(A[i]==el && B[i]==el){
			r = i;
			break;
		}
	}
	for(int i=0; i<n; i++){
		if(l>r) break;
		if(A[i]!=el && B[i]!=el){
			swap(B[i], B[l]);
			l++;
		}
	}
	if(l<=r){
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for(int i=0; i<n; i++) cout << B[i] << " ";
	return 0;
}
