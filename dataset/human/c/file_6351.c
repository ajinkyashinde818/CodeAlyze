#include<stdio.h>
int main(){
  int a[200000];
  int b,i,j;
  int minv,maxv=0;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }
  minv=a[0];
  maxv=10*10*10*10*10*10*10*10*10*(-1);
  for(j=1;j<b;j++){
    if(maxv < a[j]-minv){
      maxv=a[j]-minv;
    }
    if(minv > a[j]){
      minv=a[j];
    }
  }
  printf("%d\n",maxv);
}
