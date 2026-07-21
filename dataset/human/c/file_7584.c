#include<stdio.h>
int main(){
  int i=0;
  int ians;
  int x[10000];
  while(1){
    scanf("%d",&x[i]);
    if(x[i]==0)  break;
    i++;
    }
    for(ians=0;ians<i;ians++){
      printf("Case %d: %d\n",ians+1,x[ians]);
    }
    return 0;
}
