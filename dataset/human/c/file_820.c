#include<stdio.h>
#define rep(i,n) for(int i=0; i<n; ++i)

int min(int a,int b){
  int temp;
  if(a>b)return b;
  if(a<=b)return a;
}


int main(){

  int d,g;
  scanf("%d%d",&d,&g);

  int p[11];
  int c[11];

  rep(i,d){
    scanf("%d",&p[i]);
    scanf("%d",&c[i]);
  }

  int ans = 1000000000;
  for(int bit=0; bit < (1<<d) ; ++bit){
    int sum = 0, num = 0, rest_max = -1;
    for(int i=0; i < d ; i++){
      if(bit >> i & 1){
        sum += 100 * (i+1) * p[i] + c[i];
        num += p[i];
      }else{
        rest_max = i;
      }
    }
    if(sum < g){
      int s1 = 100 * (rest_max + 1);
      int need = (g - sum + s1 -1) / s1;
      if(need >= p[rest_max]){
        continue;
      }
      num += need;
    }
    ans = min(ans,num);  
  }

  printf("%d",ans);


  return 0;
}
