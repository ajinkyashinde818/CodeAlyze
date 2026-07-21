#include<stdio.h>

int main(){

char Q[3]="#.";

int H,W;
while(1){
scanf("%d %d",&H,&W);
if(H==0&&W==0)break;
for(int i=0;i<H;i++){
for(int j=0;j<W;j++)
{
if(i%2==0)printf("%c",Q[j%2]);
else printf("%c",Q[(j+1)%2]);
}

printf("\n");
}
printf("\n");
}
return 0;
}
