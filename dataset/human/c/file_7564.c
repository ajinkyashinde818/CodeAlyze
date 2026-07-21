#include<stdio.h>
#define Max 10000

int main(){
  int i, j, num[Max];
  for(i=0;i<Max;i++){
    scanf("%d",&num[i]);
    if(num[i]==0) break;
  }

  for(j=0;j<i;j++) printf("Case %d: %-d\n",j+1,num[j]);
  
  return 0;
}
