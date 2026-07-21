#include <stdio.h>

int a[2000000];

int main(){
	int n;
	for(int i = 0; i < 2000000; i++){
		a[i] = 1;
	}
	for(int i = 2; i < 2000000; i++){
		if(a[i]){
			for(int j = i * 2;j < 2000000; j = j + i){
					a[j] = 0;
			}
		}
	}
	scanf("%d",&n);
	while(n != 0){
		long int ans = 0;
		for(int i = 2; i < 2000000; i++){
			if(a[i]){
				ans += i;
				n--;
				if(n == 0) break;
			}
		}
		printf("%ld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
