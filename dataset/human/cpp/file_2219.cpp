#include "bits/stdc++.h"
using namespace std;


int main(){

	int N; 
	long tmp;
	vector<long> A;

	cin >> N;
	
	for (int i = 0 ; i < N; i++){
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(),A.end());
	// 要素数が奇数か偶数か
	int L = A.size();

	//偶数
	if (L%2==0){
		//cout << accumulate(A.begin(),A.end(), 0) << endl;
		for (int i = 0 ; i < N-1; i=i+2){
			if (A[i]+A[i+1]<0){
				A[i]= -A[i];
				A[i+1]= -A[i+1];
			}
		}
	}
	// 奇数
	else if (L%2==1){
		//cout << accumulate(A.begin(),A.end(), 0) << endl;
		for (int i = 0 ; i < N-1; i=i+2){
			if (A[i]+A[i+1]<0){
				A[i]= -A[i];
				A[i+1]= -A[i+1];
			}
		}
	}

	long ans = accumulate(A.begin(),A.end(), 0LL);
	cout << ans << endl;

	return 0;
}
