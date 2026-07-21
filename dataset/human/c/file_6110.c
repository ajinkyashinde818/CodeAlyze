#include<stdio.h>

long minv,maxv;
int n;
int main(){
  scanf("%d",&n);
  long r[200000];

for(int j=0;j<n;j++){
  scanf("%ld",&r[j]);
  if(j==0){minv = r[0];maxv=-10000000000;}
  else{
  if(maxv<=r[j]-minv){
    maxv=r[j]-minv;
  }
  if(minv>r[j]){
    minv=r[j];
  }}
  //printf("maxv;%lf minv;%lf\n",maxv,minv);
}
printf("%ld\n",maxv);
  return 0;
}
