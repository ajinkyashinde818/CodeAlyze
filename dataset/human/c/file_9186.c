#include <stdio.h>
#include <stdlib.h>

// useage : swap(&int1,&int2);
// 値入れ替え
int swap(int *c1,int *c2){
  int tmp;
  tmp=*c1;
  *c1=*c2;
  *c2=tmp;
  return 0;
}

int main(void) {
 
  int n;
  scanf("%d",&n);
  int k;
  scanf("%d",&k);
  int tmp,cnt=0;
  for(int i=0;i<n;i++){
    scanf("%d",&tmp);
    if(tmp>=k)cnt+=1;
  }
  
  printf("%d\n",cnt);

  return 0;
}
