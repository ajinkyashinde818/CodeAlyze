#include<stdio.h>
int main(void){
int num,i;
for(i=0;i<10000;i++){
scanf("%d",&num);
if(num==0)
break;
if(num<1||num>10000)
return 0;
printf("Case %d: %d\n",i+1,num);
}
return 0;
}
