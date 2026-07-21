#include<stdio.h>
int main(void){
 int i,last;
 int tests[10000];
 for(i=0;i<=10000;i++){
  scanf("%d",&tests[i]);
  if(tests[i]==0){
    last=i-1;
    break;
  }
 }
 for(i=0;i<=last;i++){
   printf("Case %d: %d\n",i+1,tests[i]);
 }
 return(0);
}
