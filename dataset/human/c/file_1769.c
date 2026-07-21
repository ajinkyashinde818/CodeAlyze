#include<stdio.h>
int main(void){
int N,i,j,manzoku=0;
scanf("%d",&N);
int A[N+1],B[N+1],C[N+1];
C[N]=0;
for(i=0;i<N;i++){scanf("%d",&A[i]);}
for(i=0;i<N;i++){scanf("%d",&B[i]);}
for(i=0;i<N-1;i++){scanf("%d",&C[i]);}

for(j=0;j<N;j++){
manzoku+=B[A[j]-1];
if((0<j<N) && ((A[j-1]+1)==A[j])){
manzoku+=C[A[j-1]-1];
}
}
printf("%d",manzoku);
}
