#include <bits/stdc++.h>

using namespace std;

main(){
	vector<int> arr;
	int size; scanf("%d",&size);
	int num;
	long long sumA=0, sumB=0;
	for(int i=0;i<size;++i){
		scanf("%d",&num);
		arr.push_back(num);
		sumA += num;
	}
	sumA -= arr[0];
	sumB += arr[0];
	long long less = abs(sumB-sumA);
	for(int i=1;i<size-1;++i){
		sumA -= arr[i];
		sumB += arr[i];
		long diff = abs(sumB-sumA);
		if(diff<less) less = diff;
	}
	cout << less;
}
