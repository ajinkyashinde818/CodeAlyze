#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int p[8],i,j,v,min,t,minv,si;
	int c[]={4,1,4,1,2,1,2,1};
	
	while(~scanf("%d",&p[0])){
		for(i=1;i<8;i++){
			scanf("%d",&p[i]);
		}
		
		min=-1;
		minv=-1;
		for(i=0;i<8;i++){
			t=0;
			v=0;
			for(j=0;j<8;j++){
				t+=p[j]>c[(i+j)%8]?p[j]-c[(i+j)%8]:0;
				v+=(c[(i+j)%8])*pow(10,7-j);
			}
			if(min==t || min==-1){
				if(minv>v || minv==-1){
					min=t;
					minv=v;
					si=i;
				}
			}
			if(min>t || min==-1){
				min=t;
				minv=v;
				si=i;
			}
		}
		
		for(i=0;i<8;i++){
			printf("%d",c[(si+i)%8]);
			if(i!=7)printf(" ");
		}
		printf("\n");
	}
	return 0;
}
