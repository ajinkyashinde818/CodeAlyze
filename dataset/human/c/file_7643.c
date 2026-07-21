#include<stdio.h>
int main()
{
  int a[10000];
  int i;
  for(i=1;i<=10000;i++){
    scanf("%d",&a[i]);
    if(a[i]==0){
      break;
    }
  }
  for(i=1;i<=10000;i++){
    if(a[i]==0){
      break;
    }
    printf("Case %d: %d\n",i,a[i]);
  }

  return 0;
}
