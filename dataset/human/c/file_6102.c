#include <stdio.h>
#include <stdlib.h>

#define NMAX 200000

int main(void){
	int n,c,i,j;
	int r[NMAX];
	scanf("%d",&n);
	for(c=0;c<n;c++){
		scanf("%d",&r[c]);
	}
	int maxj = -1000000000;
	int mini = r[0];
	for(j=1;j<n;j++){
		if(maxj < r[j] - mini){
			maxj = r[j] - mini;
		}
		if(mini > r[j]){
			mini = r[j];
		}
	}
	printf("%d\n",maxj);
}
