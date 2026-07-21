#include <bits/stdc++.h>
using namespace std;




int main(){

	int n;
	long long a[200000];
	long long x = 0,y = 0, sum = 0;
	long long min = 9223372036854775807;

	cin >>n;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}

	for(int i=0;i<n;i++){
		sum += a[i];
	}

	for(int i=0;i<n-1;i++){
		x += a[i];
		y = sum -x;
		if(min > labs(x - y)){
			min = labs(x - y);
//			cout <<min <<endl;
		}
	}
	cout <<min <<endl;

	return 0;
}
