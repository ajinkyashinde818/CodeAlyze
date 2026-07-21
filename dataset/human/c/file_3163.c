#include <stdio.h>

int main(void){
	int k=0, n=0, a[200000] = {0}, b[200000] = {0} , i, m=0, ans=0;
	
	scanf("%d", &k);
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < n-1; i++){
		b[i] = a[i+1] - a[i];
		//printf("%d\n", b[i]);
		if(b[i] > m){
			m = b[i];
		}
	}
	b[n-1] = k - a[n-1] + a[0];
	if(b[n-1] > m){
		m = b[n-1];
	}
	
	//printf("%d\n", m);
	ans = k - m;
	printf("%d", ans);
	
	return 0;
}
