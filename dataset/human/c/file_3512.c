#include <stdio.h>

int main(void){
	int n, a[200001]={0}, f[200001]={0}, i, p=1, j, x,pp;
	long k;
	
	scanf("%d", &n);
	scanf("%ld", &k);
	for(i=1; i < n+1; i++){
		scanf("%d", &a[i]);
	}
	
	f[1]=1;
	for(i = 2; i < 200002; i++){
		if(i == k+2){
			printf("%d", p);
			return 0;
		}
		pp = p;
		p = a[pp];
		if(f[p] == 0){
			f[p] = i;
		}else{
			break;
		}
	}
	
	x = i - f[p];
	j = (k - (f[p]-1)) % (i - f[p]);
	
	for(i = 0; i < j; i++){
		pp = p;
		p = a[pp];
	}
	
	printf("%d", p);
	
	return 0;
}
