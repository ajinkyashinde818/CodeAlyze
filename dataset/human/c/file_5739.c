#include <stdio.h>

int main(){
 long n,R[200000]={0};
 
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d",&R[i]);
 }

 long maxProfit=R[1]-R[0],mini=R[0];
 for(int i=1;i<n;i++){
  if(maxProfit<R[i]-mini){
   maxProfit=R[i]-mini;
  }
  if(mini>R[i]){
   mini=R[i];
  }
 }
 printf("%d\n",maxProfit);
 return 0;
}
