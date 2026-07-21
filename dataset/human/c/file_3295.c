#include <stdio.h>
int main(void)
{
int K,N,i,max,min;
scanf("%d",&K);
scanf("%d",&N);
int A[N],a[N];
for(i=1;i<=N;i++)
scanf("%d",&A[i]);
max=K-A[N]+A[1];
for(i=1;i<N;i++){
a[i]=A[i+1]-A[i];
if(a[i]>max)
max=a[i];
}
min=K-max;
printf("%d",min);
return 0;
}
