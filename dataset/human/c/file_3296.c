#include<stdio.h>

int main(void){
int ensyu,kensu,maxsa=0,i,k,first,before=0,now;
(void)scanf("%d %d",&ensyu,&kensu);
for(i=0;i<kensu;i++){
    (void)scanf("%d",&now);
    if(i==0)
    first=now;
    if(maxsa<(now-before))
    maxsa=(now-before);
    before=now;
}
if(first+ensyu-now>maxsa)
maxsa=first+ensyu-now;
printf("%d\n",ensyu-maxsa);
return 0;
}
