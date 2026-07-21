#include <stdio.h>

int main(){
  int n,k;
  int sum=0;
  scanf("%d %d",&n,&k);
  int buf[n];
  int i,tmp;
  for(i=0;i<n;i++){
    scanf("%d",&tmp);
    buf[i]=tmp;
    if(tmp>=k){
      sum++;
    }
  }
printf("%d",sum);
return 0;
}
