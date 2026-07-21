#include<stdio.h>

int main(void){

int i,N,R[200000],max,min;

for(scanf("%d",&N);i<N;scanf("%d",&R[i++]));

max=R[1]-R[0];
min=R[0];

for(i=1;i<N;i++){

max=max<R[i]-min?R[i]-min:max;
min=min>R[i]?R[i]:min;

}

printf("%d\n",max);

return 0;

}
