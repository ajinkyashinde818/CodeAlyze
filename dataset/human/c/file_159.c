#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*k+(j))

void run(void){
  int n;
  scanf("%d",&n);
  int k=1;
  while((k+1)*k/2<=n) k++;
  if(n!=k*(k-1)/2){
    printf("No\n");
    return;
  }
  printf("Yes\n%d\n",k);
  int *ans=(int *)calloc(k*k,sizeof(int));
  int p=1;
  int i,j;
  for(i=0;i<k;i++){
    for(j=i+1;j<k;j++){
      ans[POS(i,j)]=p;
      ans[POS(j,i)]=p;
      p++;
    }
  }
  for(i=0;i<k;i++){
    printf("%d",k-1);
    for(j=0;j<k;j++){
      if(i==j) continue;
      printf(" %d",ans[POS(i,j)]);
    }
    putchar('\n');
  }
}

int main(void){
  run();
  return 0;
}
