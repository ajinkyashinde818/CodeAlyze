#include<stdio.h>

main(){
	int n,R,min,max,i;
	scanf("%d",&n);
	scanf("%d",&R);
	min=R;
	scanf("%d",&R);
	max=R-min;
	if(R<min)min=R;
	for(i=2;i<n;i++){
		scanf("%d",&R);
		if(R-min>max)max=R-min;
		if(R<min)min=R;
		
	}
	printf("%d\n",max);
	return 0;		
}
