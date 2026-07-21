#include <stdio.h>

int main(void) {

	int n;
	scanf("%d",&n);

	int r[n];
	int i;

	for(i=0; i<n; i++) {
		scanf("%d",&r[i]);
	}

	int maxv = r[1]-r[0];
	int minv = r[0];
	
	//printf("%d",maxv);
	
	for(i=1; i<n; i++) {
		if(maxv < r[i]-minv) {
			maxv = r[i]-minv;
			
		}
		if(minv > r[i]){
			minv = r[i];
		}
	}
	
	printf("%d\n",maxv);

	return 0;

}
