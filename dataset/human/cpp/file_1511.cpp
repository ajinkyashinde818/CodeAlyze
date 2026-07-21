#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main (void){
	int n,k = -1;
	cin >> n;
	n *= 2;
	for(int i = 1; i < n; ++i){
		if(n % i == 0 && abs(i - n / i) == 1){
			k = n / i;
			break;
		}
	}
	if(k != -1){
		cout << "Yes" << endl;
		cout << k << endl;
	}else{
		cout << "No" << endl;
		return 0;
	}
	for(int i = 0; i < k; ++i){
		cout << k-1 << " ";
		int tmp = 1;
		for(int j = 0; j < i; ++j){
			cout << tmp + i - j - 1 << " ";
			tmp += (k-1) - j;
		}
		for(int j = tmp; j <= (k-1) - i + tmp - 1; ++j){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
