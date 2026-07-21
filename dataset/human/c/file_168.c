#include<stdio.h>
#include<stdlib.h>

int main(void){
 int m,n,tmp,i,j,k;
 short *flg;
 int *stack;
 
 scanf("%d%d",&n,&m);
 flg=(short *)calloc(n+1,sizeof(short));
 stack=(int *)calloc(m,sizeof(int));
 for(i=0;i<m;i++){
  scanf("%d",&tmp);
  flg[tmp]=1;
  stack[i]=tmp;
 }
 for(i=m-1;i>=0;i--){
  if(flg[stack[i]]==1) printf("%d\n",stack[i]);
  flg[stack[i]]=2;
 }
 for(i=1;i<=n;i++) if(flg[i]==0) printf("%d\n",i);
 free(flg);
 free(stack);
 return 0;
}
