#include <stdio.h>
#include <math.h>

int main(void){
    int i,n,m,l;
	int max,min;
    scanf("%d",&n);
	scanf("%d",&min);
	scanf("%d",&m);
	max = m-min;
	if(min>m){
		min = m;
	}
	for(i=2;i<n;i++){
		scanf("%d",&m);
		l = m-min;
		if(max<l){
			max = l;
		}
		if(min>m){
			min = m;
		}
	}
	
	printf("%d\n",max);
	return 0;
}
