#include<stdio.h>

main(){
	int x[100000];
	int i,c;
	i = 0;
	c = 1;
	while(1){
		scanf("%d",&x[i]);
	    if(x[i]==0)break;
	    i++;
	    c++
	    ;
	}
	for(i=1;i<c;i++){
		printf("Case %d: %d\n",i,x[i-1]);
	}
	return 0;
}
