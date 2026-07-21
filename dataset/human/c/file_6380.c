#include<stdio.h>
int max(int a,int b){
	if(a>b){return a;}
	else{return b;}
}
main(){
	int i,r1,r2,cumDif,maxDif,tmpDif;
	scanf("%d %d %d",&i,&r1,&r2);
	cumDif=r2-r1;
	maxDif=cumDif;
	r1=r2;
	while(scanf("%d",&r2)!=EOF){
		tmpDif=r2-r1;
		cumDif=tmpDif+max(cumDif,0);
		if(maxDif<cumDif){maxDif=cumDif;}
		r1=r2;
	}
	if(maxDif<cumDif){maxDif=cumDif;}
	printf("%d\n",maxDif);
	return 0;
}
