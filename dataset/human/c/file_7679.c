#include <stdio.h> 
int main(void)
{
int x[10000],i,j;
i=0;
scanf("%d",&x[i]);
while(x[i]!=0){
	i++;
	scanf("%d",&x[i]);
}
j=i-1;
for(i=0;i<=j;i++){
	printf("Case %d: %d\n",i+1,x[i]);
}
return 0;
}
