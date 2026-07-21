#include<stdio.h>
main(){
  int x;
  int y=0;
  int a[10000];
  for(int i=0; i<10000;i++){
  scanf("%d",&x);
  if(x==0) break;
  a[i]=x;
  y+=1;
  }
  for(int i=0;i<y;i++){
    printf("Case %d: %d\n",i+1,a[i]);
  }
  return 0;
}
