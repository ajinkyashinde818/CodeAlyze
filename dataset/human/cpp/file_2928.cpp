#include <string>
#include <numeric>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n],count;
	unsigned long sum = 0;
	int min = 1000000001;
	for(int i = 0; i < n;i++){
		cin >> a[i];
		if(abs(a[i]) < min){
			min = abs(a[i]);
		}
		if(a[i] < 0){
			count++;
			a[i] = -a[i];
		}
		sum += a[i];
	}
	if(count % 2 == 1){
		sum -= 2 * min;
	}
	cout << sum << endl;
}
