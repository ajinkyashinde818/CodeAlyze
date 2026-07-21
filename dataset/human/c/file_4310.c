#include <stdio.h>
#define DIV 1000000007

int main(){
  int N,M;
  int a;
  int now=0;
  int here=1, before=0;

  scanf("%d %d",&N,&M);

  for(int i=0;i<M;i++){
    scanf("%d",&a);
    while(now<a){
      int tmp = (here+before)%DIV;
      now += 1;
      before = here;
      here = tmp;
    }
    here = 0;
  }

  while(now<N){
    int tmp = (here+before)%DIV;
    now += 1;
    before = here;
    here = tmp;
  }
    
  printf("%d\n",here);
  
  
  return 0;
}
