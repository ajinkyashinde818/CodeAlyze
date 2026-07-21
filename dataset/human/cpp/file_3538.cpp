#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N];
	vector<int> a;
	for(int i=0; i<N; i++) cin >> A[i];
	for(int i=0; i<N; i++){
		if(A[i] < 0) a.push_back(A[i]);
	}
	sort(a.begin(), a.end());
	if(a.size() % 2 == 0){
		long long ans = 0;
		for(int i=0; i<N; i++){
			if(A[i] < 0) ans += (-A[i]);
			else ans += A[i];
		}
		cout << ans << endl;
	}else{
		long long ans = 0;
		int min = 0;
		for(int i=1; i<N; i++){
			if(abs(A[min]) > abs(A[i])) min = i;
		}
		if(A[min] < 0){
			for(int i=0; i<N; i++){
				if(i != min){
					if(A[i] < 0) ans += (-A[i]);
					else ans += A[i];
				}
			}
			ans += A[min];
			cout << ans << endl;
		}else{
			for(int i=0; i<N; i++){
				if(i != min){
					if(A[i] < 0) ans += (-A[i]);
					else ans += A[i];
				}
			}
			ans -= A[min];
			cout << ans << endl;
		}
	}
	return 0;
}
