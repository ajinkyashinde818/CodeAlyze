#include <stdio.h>
  
int main(void){
int number[10000],x,i=0,n;
scanf("%d",&x);
if(x!=0){
	do{
		i++;
		number[i]=x;
		scanf("%d",&x);
	} while(x!=0 && i<=10000);
}
n=i;
for(i=1;i<=n;i++){
printf("Case %d: %d\n",i,number[i]);
}
return 0;
}
