#include <bits/stdc++.h>
using namespace std;

int main(){
	int c[100000];
	int max = -10000;
	long long int sum = 0;
	int s = 0;
	int b[100000];
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> b[i];
		sum += abs(b[i]);
	}
	for(int i = 0;i<n;i++){
		if(b[i] <= 0){
			s += 1;
		}
	}
	for(int i = 0;i<n;i++){
		if(b[i] <= 0){
			c[i] = abs(b[i]);
		}
		else{
			c[i] = b[i];
		}
	}
	sort(c,c+n);
	//cout << c[0];
	if(s % 2 == 0){
		cout << sum;
	}
	else{
		cout << sum-2*c[0];
	}
	
}
