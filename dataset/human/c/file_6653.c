#include<stdio.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int main(){
  int N,minval,ans=-1e9,num;
  scanf("%d",&N);
  scanf("%d",&minval);
  N--;
  while(N--){
    scanf("%d",&num);
    ans = MAX(ans, num-minval);
    minval = MIN(minval, num);
  }
  printf("%d\n",ans);
  return 0;
}
