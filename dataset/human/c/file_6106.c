#include <stdio.h>
#define INF 2e9

int min(int a,int b){
    if (a>b) return b;
    else return a;
}

int max(int a,int b){
    if (a>b) return a;
    else return b;
}

int main(){
  int i, n, r = -INF, m = INF, t;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&t);
    r = max(r,t-m);
    m = min(t,m);
  }
  printf("%d\n",r);
  
  return 0;
}
