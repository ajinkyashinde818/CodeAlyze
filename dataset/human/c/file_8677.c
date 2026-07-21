#include<stdio.h>
int main(){
  int i, n, count=0, next, f=-1;
  scanf("%d", &n);
  int an[100000];

  for(i=0;i<n;i++){
    scanf("%d", &an[i]);
  }

  int flg[100000]={};

  next = an[0];

  while (next!=1 && next!=2 && flg[next-1]==0) {
    flg[next-1]=1;
    next = an[next-1];
    count++;
  }

  if(next==2){
    count++;
    printf("%d\n", count);
  }else{
    printf("%d\n", f);
  }

  return 0;
}
