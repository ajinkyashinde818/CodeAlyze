#include<stdio.h>
int main(){
	int i,j,x,ms,s,o[]={0,2,6,4,1,3,7,5};
	int c[]={1,2,1,2,1,4,1,4},p[10];
	while(scanf("%d",&p[0])!=EOF){
		x=ms=0;
		for(i=0;i<8;i++){
			if(i!=0)scanf("%d",&p[i]);
			if(p[i]>c[i])ms+=p[i]-c[i];
		}
		for(i=0;i<8;i++){
			s=0;
			for(j=0;j<8;j++){
				if(p[j]>c[(j+o[i])%8])s+=p[j]-c[(j+o[i])%8];
				//printf("%d ",c[(j+o[i])%8]);
			}
			//printf("i=%d o=%d s=%d\n",i,o[i],s);
			if(s<ms)x=i,ms=s;
		}
		for(i=0;i<8;i++)printf("%s%d",(i==0)?"":" ",c[(i+o[x])%8]);
		printf("\n");
	}
	return 0;
}
