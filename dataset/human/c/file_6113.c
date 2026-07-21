#include<stdio.h>
#define N 200000
int main(){
  int ary[N],i,n,min,t,max;
  scanf("%d",&n);
  scanf("%d",&ary[0]);
  min=ary[0];
  for(i=1;i<n;i++){
    scanf("%d",&ary[i]);
    }
  max=ary[1]-min;
  for(i=1;i<n;i++){
    if(ary[i]-min>max){
      max=ary[i]-min;
    }
    if(ary[i]<min){min=ary[i];}
  }
  printf("%d\n",max);
  return 0;
}
