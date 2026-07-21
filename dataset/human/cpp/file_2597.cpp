#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long arr[n];
	for(int i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}	
	long long soma = 0;
	long long mini = 1e9 + 7;
	for(int i = 0; i < n - 1; i++){
		if(arr[i] < 0){
			arr[i] *= -1LL;
			arr[i + 1] *= -1LL;
		}
		mini = min(mini, arr[i]);
		soma += arr[i];
	}
	if(arr[n - 1] < 0LL){
		if((arr[n - 1] * -1LL) >= mini){
			soma -= (mini * 2);
			soma += -1LL * arr[n - 1];
		}else{
			soma += arr[n - 1];
		}
	}else{
		soma += arr[n - 1];
	}
	printf("%lld\n", soma);
	return 0;
}
