#include <stdio.h>
#include <math.h>

int main(void)
{
	int a[30], b[30], c[30];
	int i, n, s;
	s=0;

	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<n;i++){
		scanf("%d", &b[i]);
		s=s+b[i];
	}

	for(i=0;i<n-1;i++){
		scanf("%d", &c[i]);
	}
	
	for(i=0;i<n;i++){
		if(a[i]+1==a[i+1]){
			s=s+c[a[i]-1];
		}
	}
	
	printf("%d", s);	
	return 0;
}
