#include<stdio.h>
#define A 2000000
int main(void){
int n,i,j,k;
int R[A];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&R[i]);
}
for(i=0;i<n-1;i++){
if(i==0 || j>R[i]){
j=R[i];
}
if(i==0 || k<R[i+1]-j){
k=R[i+1]-j;
}
}
printf("%d\n",k);
return 0;
}
