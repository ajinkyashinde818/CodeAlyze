#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n,k,ans=0,i;
	int h[100001];

	scanf("%d %d",&n, &k);

	for(i =0; i<n;i++){
		scanf("%d",&h[i]);
	}

	for(i =0; i<n;i++){
		if(h[i]>=k)
			ans++;
	}

	printf("%d",ans);

	return EXIT_SUCCESS;
}
