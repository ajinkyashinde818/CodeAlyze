#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	long long int  N,snuke,arai,min,sum=0;
	long long int a[200001];
	scanf("%lld",&N);
	//printf("%lld\n",N);
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	snuke = a[0];
	arai = sum-a[0];
	//printf("%lld %lld\n",snuke,arai);
	min = abs(sum + 2*a[0]);
	//printf("%lld\n",min);
	for(int i=1;i<N-1;i++){
		snuke += a[i];
		arai -= a[i];
		if(abs(snuke - arai) < min){
			min = abs(snuke - arai);
			//printf("%lld\n",min);
		}
	}
	printf("%lld\n",min);
	
	return 0;
}
