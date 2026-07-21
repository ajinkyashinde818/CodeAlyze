#include <stdio.h>
int main(void)
{
	int k,s,x,y,z,c=0;
	scanf("%d%d",&k,&s);
	for(x=0; x<=k; x++){
		for(y=x; y<=k; y++){
			for(z=y; z<=k; z++){
				if(x+y+z==s){
					if(x==y && y==z){
						c=c+1;
					}else if(x!=y && x!=z && y!=z){
						c=c+6;
					}else{
						c=c+3;
					}
				}
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
