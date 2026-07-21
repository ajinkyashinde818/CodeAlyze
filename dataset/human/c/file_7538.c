#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
int x[10001];
int i;
i=0;
int z=0;
do{
scanf("%d",&x[i]);
i++;
}while(x[i-1]!=0);
for(z=0;z<i-1;z++){
	
	
	printf("Case %d: %d\n",z+1,x[z]);
	
	
}
	return 0;
}
