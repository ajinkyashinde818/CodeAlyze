#include <stdio.h>

int main(void) {
	int n, i, a[200001], msa, l, sa;
	
	scanf("%d", &n);
	
	scanf("%d%d", &a[0], &a[1]);
	
	l=a[0]>a[1]?a[1]:a[0];
	msa=a[1]-a[0];
	
	for(i=2;i<n;i++){
		scanf("%d", &a[i]);
		sa=a[i]-l;
		if(sa>msa)
		msa=sa;
		if(l>a[i])
		l=a[i];
	}
	
	printf("%d\n", msa);
	return 0;
}
