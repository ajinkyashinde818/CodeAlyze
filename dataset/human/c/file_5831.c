#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,i;
  int *x;
  int minv=0,maxv;

scanf("%d",&n);
if(n<2||n>200000)return 0;

x = (int *)malloc(sizeof(int) * n);

for(i = 0;i<n;i++){
scanf("%d",&x[i]);
if(x[i]<1||x[i]>1000000001)return 0;
}


minv = x[0];
maxv=x[1]-x[0];
for(i=1;i<n;i++) {
  if(maxv<x[i]-minv){
  maxv = x[i]-minv;
}
  if(x[i]<minv){
  minv = x[i];
}
}

printf("%d\n",maxv);

return 0;
}
