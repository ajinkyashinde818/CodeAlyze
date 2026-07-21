#include <stdio.h>
#include <cstdlib>

int main(void){
	int N;
	long long int res;
	long long int min=9223372036854775807;
	long long int sumb = 0;
	long long int a[200000]={0};
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i]);
		sumb += a[i];
	}
	long long int suma=0;
	for(int i=0;i<N-1;i++){
		suma += a[i];
		sumb -= a[i];
		res = std::abs(suma-sumb);
		if(res < min){
			min = res;
		}
	}
	printf("%lld\n",min);
	return 0;
}
