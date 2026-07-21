#include<stdio.h>
#define NUMBER 10000
int main(void)
{
int x[NUMBER],i,N=0,tmp;

for(i=0;i<NUMBER;i++){
    scanf("%d",&tmp);
    if(tmp==0){break;}
    x[i]=tmp;
    N++;
}

for(i=0;i<N;i++){
    printf("Case %d: %d\n",i+1,x[i]);
}

return 0;
}
