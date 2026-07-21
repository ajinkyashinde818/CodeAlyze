#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define FOR(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define PRN(n) printf("%d\n",n)
#define PRF(n) printf("%lf\n",n)
#define PRL(n) printf("%lld\n",n)
#define PRS(s) printf("%s\n",s)
#define PRC(c) printf("%c",c)
#define mod 1000000007
typedef long long int ll;
ll dp[100001];
int q(const void *a, const void *b){
    return *(ll*)a-*(ll*)b;
}
int main(void) {
  int e,y;
  scanf("%d %d",&e,&y);
  if(e==0){
    if(y<1912){
      PRC('M');
      y-=1867;
    }else if(y<1926){
      PRC('T');
      y-=1911;
    }else if(y<1989){
      PRC('S');
      y-=1925;
    }else{
      PRC('H');
      y-=1988;
    }
  }else if(e==1){
    y+=1867;
  }else if(e==2){
    y+=1911;
  }else if(e==3){
    y+=1925;
  }else{
    y+=1988;
  }
  PRN(y);
  return 0;
}
