#include<stdio.h>

int Maximum(int *,int);
int main(){
  int i,n,a[200000],max;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  max=Maximum(a,n);
  printf("%d\n",max);
  return 0;
}

int Maximum(int *a,int n){
  int i,max=(-1000000000),j,x,min;
  min=a[0];
  for(i=1;i<n;i++){

    if(max<(a[i]-min))max=a[i]-min;
    if(min>a[i])min=a[i];

  }
  return max;
}
